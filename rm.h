


void rm_1(char** args){
     if(fork() == 0){
                
                
            
               int status_code =  execvp("/bin/rm", args);
                if (status_code == -1)
                {
                    printf("Process did not terminate correctly\n");
                    exit(1);
                }

                printf("This line will not be printed if execvp() runs correctly\n");

                exit(0);
            }  
            else{
                wait(NULL);
            } 
    
}