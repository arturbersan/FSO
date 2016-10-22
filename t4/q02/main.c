#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
int stop=0;

void listdir(const char *name, int level,int N,const char *substring)
{
  DIR *dir;
  struct dirent *entry;
  int j;

  if (!(dir = opendir(name)))
    return;
  if (!(entry = readdir(dir)))
    return;

  do {
    if (entry->d_type == DT_DIR) {
      char path[1024];
      int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
      path[len] = 0;
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;
      listdir(path, level + 1,N,substring);
    }
    else if(strstr(entry->d_name, substring) != NULL){
      char file_name[256];
      strcpy(file_name,name);
      strcat(file_name,"/");
      strcat(file_name,entry->d_name);
      if(stop==N)
        break;
      stop++;

      FILE *desired_file = fopen(file_name, "r");
      if(!desired_file)
        printf("Invalid file\n");
      else{
        printf("%d %s/%s\n", stop,name,entry->d_name);
        for(j = 0; j<30;j++){
          char character = getc(desired_file);
          if(character == EOF)
            break;
          printf("%c",character);
        }
        printf("\n");
      }
    }
  } while (entry = readdir(dir));
  closedir(dir);
}

int main(int argc, char ** argv)
{
  if(argc != 4) {
    printf("Numero invalido de parametros\n");
  } else {
    char *path = argv[1];
    char *substring = argv[2];
    int N = atoi(argv[3]);
    listdir(path,0,N,substring);
  }

  return 0;
}
