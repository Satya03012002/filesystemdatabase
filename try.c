#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include "ls.h"
#include "cat.h"
#include "date.h"
#include "mkdir.h"
#include "rm.h"
#include "data.h"

#define deli " \t\r\n"



int main(){

    
    printf("\n\n\n\n\n\t\t\t\t\t********  Welcome to SHELL  ********\n\n");
    char command[100];
    char cwd[100];
    
    do{
        printf("%s-newterminal %s $ ",getenv("USER"), getcwd(cwd, 100));
        fflush(stdin);
         
        scanf("%[^\n]%*c", command);

        int count = 0;
        char* argv[9];
        int i = 0;
        argv[i] = strtok(command, deli);
        while(argv[i] != NULL){
            count++;
            argv[++i] = strtok(NULL, deli);
        }
        printf("count - %d\n", count);
        printf("i - %d\n", i);

        argv[i] = NULL;

        
        if(strcmp(argv[0], "help") == 0){
            printf("\n\n\n\n\n\t\t*** WELCOME TO MY SHELL ***\n\n");
            printf("\t\t satya prakash \n\n");
        }

        else if(strcmp(argv[0], "pwd") == 0){
            char cwd[256];
            printf("%s\n",getcwd(cwd, sizeof(cwd)));
        }

        else if(strcmp(argv[0], "echo") == 0){
            for(int i=1; argv[i]!= NULL;i++){
                printf("%s ",argv[i]);
            }
            printf("\n");
        }

        else if(strcmp(argv[0],"cd") == 0){
            int status;
            if(strcmp(argv[1],"~") == 0){
                status = chdir(getenv("HOME"));
            }
            else{
                status = chdir(argv[1]);
            }
            if(status != 0){
                printf("no such file or directory exists\n");
            }
        }

        else if(strcmp(argv[0], "exit") == 0) break;

        else if(strcmp(argv[0], "ls") == 0){

            ls_1(argv);
            

        }

        else if(strcmp(argv[0], "rm") == 0){
            rm_1(argv);
        }
        else if(strcmp(argv[0], "data") == 0){

            int* b = (int*)argv[1];
            int c = *b;
            data_1(c);
        }

        else if(strcmp(argv[0], "mkdir") == 0){
           mkdir_1(argv);
        }

        else if(strcmp(argv[0], "date") == 0){
           date_1(argv);
        }

        else if(strcmp(argv[0], "cat") == 0){
            cat_1(argv);
        }

        else{
            if(fork() == 0){
                int status = execvp(argv[0], argv);
                if(status == -1){
                    printf("command is not found: %s\n",argv[0]);
                }
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
    }while (1);
    
    return 0;
}