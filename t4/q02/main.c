#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void listdir(const char *path, int N,const char *substring)
{
  DIR *dir;
  struct dirent *entry;
  int j;

  if (!(dir = opendir(path)))
    return;
  if (!(entry = readdir(dir)))
    return;
  printf("Resultado de buscador '%s' na pasta %s\n",substring,path);

  do {
    /* int i = 1; */
    if (entry->d_type == DT_DIR) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;
    }
    else if(strstr(entry->d_name, substring) != NULL){
      char file_name[256];
      strcpy(file_name,path);
      strcat(file_name,"/");
      strcat(file_name,entry->d_name);
      /* printf("Nome do arquivo  = %s\n\n", file_name); */
      FILE *desired_file = fopen(file_name, "r");
      if(!desired_file)
        printf("Invalid file\n");
      else{
        printf("%s/%s\n", path,entry->d_name);
        for(j = 0; j<30;j++){
          printf("%c",getc(desired_file));
        }
        printf("\n");
      }
    }
    /* i++; */
  } while (entry = readdir(dir) /* || i == N */ );
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
    listdir(path,N,substring);
  }

  return 0;
}
