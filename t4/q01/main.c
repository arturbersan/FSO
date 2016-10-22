#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <utime.h>

char *change_extension(char *file_name, char new_extension[3])
{
        char *bkp_name=malloc(sizeof(file_name));
        strcpy(bkp_name, file_name);

        int len=strlen(file_name);

        bkp_name[len-3]='b';
        bkp_name[len-2]='k';
        bkp_name[len-1]='p';

        return bkp_name;
}

void output(struct stat fs)
{
        printf("Horario de modificação: %s\n", ctime(&fs.st_mtime));
        printf("Horário de acesso: %s\n", ctime(&fs.st_atime));
        printf("\n");
}

int main(int argc, char *argv[])
{
        char *file_name = argv[1];
        char *pattern = argv[2];
        FILE *desired_file = fopen(file_name, "r");
        if (!desired_file) {
                printf("Invalid file.\n");
        } else {

                char command[256];
                char *new_name=change_extension(file_name, ".bkp");
                strcpy(command, "cp ");
                strcat(command, file_name);
                strcat(command, " ");
                strcat(command, new_name);
                system(command);

                fclose(desired_file);

                struct stat fs;
                stat(file_name, &fs);

                printf("Obs: Para ter acesso as informações do crtime do arquivo, cheque o README.pdf\n");
                printf("Informações antes da mudança:\n");
                output(fs);

                time_t t = time(NULL);
                struct tm *mytm = localtime(&t);
                char year[4], month[2], d[2], h[2], minutes[2];
                for (int i=0; i < 4; ++i) {
                        year[i]=pattern[i];
                }
                for (int i=0; i < 2; ++i) {
                        d[i]=pattern[i+6];
                        h[i]=pattern[i+8];
                        minutes[i]=pattern[i+10];
                        month[i]=pattern[i+4];
                }

                mytm->tm_min=atoi(minutes);
                mytm->tm_hour=atoi(h);
                mytm->tm_mday=atoi(d);
                mytm->tm_mon=atoi(month)-1;
                mytm->tm_year=atoi(year)-1900;
                mytm->tm_yday=atoi(d)*atoi(month);
                mktime(mytm);

                struct utimbuf time_buf;
                time_buf.actime=mktime(mytm);
                time_buf.modtime=mktime(mytm);
                utime(file_name, &time_buf);
                stat(file_name, &fs);

                printf("\nInformações após a mudança:\n");
                output(fs);

                free(new_name);

        }
        return 0;
}
