#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "queue.h"
#include <errno.h>
#include <sys/stat.h>
#include <linux/limits.h>

int main(int argc, char const *argv[])
{
    if(argc != 2){
        fprintf(stderr,"%i Wrong ammount of arguments\n",argc);
        
        for(size_t i = 0; i < argc; i++)
        {
            printf("%s\n",argv[i]);
        }
        
        return 1;
    }
    queue *DIRQueue = newQueue();
    DIR *cur;
    char* path;
    char* tmp;
    struct dirent *readRet;
    struct stat curStat;
    if(argv[1][0]=='/'){
        enqueue((char*)argv[1],DIRQueue);
    }
    else{
        tmp = malloc(PATH_MAX+1);
        getcwd(tmp,PATH_MAX-strlen(argv[1])-2);
        strcat(tmp,"/");
        strcat(tmp,argv[1]);
        if(argv[1][strlen(argv[1])-1]!='/'){
            strcat(tmp,"/");
        }
        enqueue(tmp,DIRQueue);
        tmp = NULL;
    }
    
    
    while(DIRQueue->Count != 0){
        path = dequeue(DIRQueue);
        cur = opendir(path);
        if(cur == NULL){
            fprintf(stderr,"%s\n",strerror(errno));
            if(errno != EACCES && errno != ENOENT)
            return errno;
        }
        else {
            while((readRet =readdir(cur))!=NULL){
                tmp = (char*)malloc(strlen(path)+strlen(readRet->d_name)+2);
                strcpy(tmp,path);
                
                strcat(tmp,readRet->d_name);
                lstat(tmp,&curStat);
                if(S_ISDIR(curStat.st_mode)&&strcmp(readRet->d_name,".")!=0 && strcmp(readRet->d_name,"..")!=0){
                    if(tmp[strlen(tmp)-1]!='/'){
                        strcat(tmp,"/");
                    }
                    enqueue(tmp,DIRQueue);
                    tmp = NULL;

                }
                else if(S_ISREG(curStat.st_mode)){
                    printf("%s\n",tmp);
                    free(tmp);

                }
                else{
                    free(tmp);

                }
            }
            closedir(cur);
        }
    }
    return 0;
}
