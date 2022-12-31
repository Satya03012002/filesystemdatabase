#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "ls.h"
#include "cat.h"
#include "date.h"
#include "mkdir.h"
#include "rm.h"
// #include "data.h"

#define deli " \t\r\n"

int main()
{

    printf("\n\n\n\n\n\t\t\t\t\t********  Welcome to SHELL  ********\n\n");
    char command[100];
    char cwd[100];
    char pfolder[30];
    char *pfile;
    struct schema
    {
        char attribute_name[50];
        char data_type[50];
    };

    do
    {
        printf("%s-dnms-terminal %s $ ", getenv("USER"), getcwd(cwd, 100));
        fflush(stdin);

        scanf("%[^\n]%*c", command);

        char *argv[20];
        int i = 0;
        argv[i] = strtok(command, deli);
        int count = 0;
        while (argv[i] != NULL)
        {

            count++;

            // printf("token- %d - %s\n", i, argv[i]);
            argv[++i] = strtok(NULL, deli);
        }

        argv[i] = NULL;

        if (strcmp(argv[0], "help") == 0)
        {
            printf("\n\n\n\n\n\t\t*** WELCOME TO MY SHELL ***\n\n");
            printf("\t\t satya prakash \n\n");
        }

        else if (strcmp(argv[0], "pwd") == 0)
        {
            char cwd[256];
            printf("%s\n", getcwd(cwd, sizeof(cwd)));
        }

        else if (strcmp(argv[0], "echo") == 0)
        {
            for (int i = 1; argv[i] != NULL; i++)
            {
                printf("%s ", argv[i]);
            }
            printf("\n");
        }

        else if (strcmp(argv[0], "cd") == 0)
        {
            int status;
            if (strcmp(argv[1], "~") == 0)
            {
                status = chdir(getenv("HOME"));
            }
            else
            {
                status = chdir(argv[1]);
            }
            if (status != 0)
            {
                printf("no such file or directory exists\n");
            }
        }

        else if (strcmp(argv[0], "exit") == 0)
            break;

        else if (strcmp(argv[0], "ls") == 0)
        {

            ls_1(argv);
        }

        else if (strcmp(argv[0], "rm") == 0)
        {
            rm_1(argv);
        }
        else if (strcmp(argv[0], "SELECT") == 0)
        {
            //  int status = chdir(pfolder);
            char table_name[20];
             char ref_table_name[20];
            for (int j = 0; j < strlen(argv[1]) + 1; j++)
            {
                table_name[j] = argv[1][j];
            }

            
            strcat(table_name, "-data");
           
            FILE *schemafile, *datafile, *readfile ,*refdatfile,*reffile;

            datafile = fopen(table_name, "a");
            schemafile = fopen(argv[1], "r+");
            readfile = fopen(table_name, "r+");
            

            if (schemafile == NULL || readfile == NULL || datafile == NULL)
            {
                fprintf(stderr, "\nError opening file\n");
                exit(1);
            }

            int size = (count - 2);

            struct schema inp;

            struct final
            {
                struct schema arr[size];
            };
            struct final data;
    
            int i = 0;


            // while ((i < size) && fread(&inp, sizeof(struct schema), 1, schemafile))
            // {

            //     for (int j = 0; j < strlen(inp.attribute_name) + 1; j++)
            //     {
            //         data.arr[i].attribute_name[j] = inp.attribute_name[j];
            //     }
            //     printf(" data.arr[%d].attribute_name - %s    ",i, data.arr[i].attribute_name);

            //     for (int j = 0; j < strlen(argv[i + 2]) + 1; j++)
            //     {
            //         data.arr[i].data_type[j] = argv[i + 2][j];
            //     }
            //     printf("data.arr[%d].data_type - %s\n",i, data.arr[i].data_type);

            //     i++;
            // }

            struct ref{
                char fkey[20];
                char table[20];
            };

            struct ref reference[50];
            int k = 0;

              while (fread(&inp, sizeof(struct schema), 1, schemafile))
            {
                if (strcmp(inp.data_type , "INT") == 0|| strcmp(inp.data_type , "CHAR") == 0)
                {
                    
                    for (int j = 0; j < strlen(inp.attribute_name) + 1; j++)
                    {
                        data.arr[i].attribute_name[j] = inp.attribute_name[j];
                    }
                    printf(" data.arr[%d].attribute_name - %s    ", i, data.arr[i].attribute_name);

                    for (int j = 0; j < strlen(argv[i + 2]) + 1; j++)
                    {
                        data.arr[i].data_type[j] = argv[i + 2][j];
                    }
                    printf("data.arr[%d].data_type - %s\n", i, data.arr[i].data_type);

                    i++;
                }else{

                    // int i = 0;
                    for (int j = 0; j < strlen(inp.attribute_name) + 1; j++)
                    {
                        reference[k].fkey[j] = inp.attribute_name[j];
                    }
                    printf(" reference[%d].fkey - %s ", k, reference[k].fkey);

                    for (int j = 0; j < strlen(inp.data_type) + 1; j++)
                    {
                        reference[k].table[j] = inp.data_type[j];
                    }
                    printf("reference[%d].table - %s\n", k, reference[k].table);

                    k++;
                }
            }
            reference[k].fkey[0] = '-';
            reference[k].table[0] = '-';

            fclose(schemafile);

            fwrite(&data, sizeof(struct final), 1, datafile);
            if (fwrite != 0)
                printf("Contents to file written successfully !\n");
            else
                printf("Error writing file !");
            fclose(datafile);

            struct final input;

            int j = 0;
            while (fread(&input, sizeof(struct final), 1, readfile))
            {

                for (int i = 0; i < size; i++) //for (int i = 0; i < 2; i++)
                {
                    // printf (" %s %s\n", input.arr[i].attribute_name, input.arr[i].data_type);
                    printf(" %s ", input.arr[i].data_type);
                }

                printf("\n");

                // printf ("roll_no = %s , name = %s\n", data->attribute_name, data->data_type);
                j++;
            } 
            fclose(readfile);
            int l = 0;

            while (reference[l].fkey[0] !=  '-')
            {

                printf("entering in the foreign table\n");
            
                for (int j = 0; j < strlen(reference[l].table) + 1; j++)
                {
                    ref_table_name[j] = reference[l].table[j];
                }

               

                reffile = fopen(ref_table_name, "r+");
                if (reffile == NULL)
                {
                    fprintf(stderr, "\nError opening file\n");
                    exit(1);
                }
               
                int p = 0;
                int nu = 0;
                while (fread(&inp, sizeof(struct schema), 1, reffile ))
                {   
                    if (strcmp(inp.data_type , "INT") == 0|| strcmp(inp.data_type , "CHAR") == 0){
                        p++;
                    }
                    
                }
                printf("no. of attribute in foreign table - %d\n", p);
                size = p;

                strcat(ref_table_name, "-data");
                refdatfile = fopen(ref_table_name, "r+");

                // if (refdatfile == NULL)
                // {
                //     fprintf(stderr, "\nError opening file\n");
                //     exit(1);
                // }

                struct final refdata;
                while (fread(&refdata, sizeof(struct final), 1, refdatfile))
                {

                    printf("entering into foreign table data\n");

                    

                    for (int i = 0; i < p; i++) // for (int i = 0; i < 2; i++)
                    {
                        // printf (" %s %s\n", input.arr[i].attribute_name, input.arr[i].data_type);
                        printf(" %s ", refdata.arr[i].data_type);
                    }

                    printf("\n");

                    // printf ("roll_no = %s , name = %s\n", data->attribute_name, data->data_type);
                    j++;
                }

                l++;
                p = 0;
                nu = 0;
            }
        }

        else if (strcmp(argv[0], "CREATE") == 0 && strcmp(argv[1], "DATABASE") == 0)
        {
            for (int j = 0; j < strlen(argv[2]) + 1; j++)
            {
                pfolder[j] = argv[2][j];
            }
            pid_t cpid = fork();
            if (cpid == 0)
            {

                int status_code = execl("/bin/mkdir", "mkdir", argv[2], NULL);

                if (status_code == -1)
                {
                    printf("Process did not terminate correctly\n");
                    exit(1);
                }

                printf("This line will not be printed if execvp() runs correctly\n");

                exit(0);
            }
            else
            {
                int status = chdir(argv[2]);

                // printf("status- %d\n", status);
                wait(NULL);
            }
            // data_1();
        }

        else if ((strcmp(argv[0], "CREATE") == 0 && strcmp(argv[1], "TABLE") == 0) || (strcmp(argv[1], "FOREIGN") == 0))
        {

            int status = chdir(pfolder);

            printf("status- %d\n", status);

            if (strcmp(argv[1], "FOREIGN") == 0)
            {
                printf("hello\n");
                pfile = argv[0];
                chdir(pfolder);
            }
            else
            {
                pfile = argv[2];
            }

            printf("pfile - %s\n", pfile);

            if (fork() == 0)
            {

                FILE *outfile, *appendfile;
                outfile = fopen(pfile, "a");

                if (outfile == NULL)
                {
                    fprintf(stderr, "\nError opened file\n");
                    exit(1);
                }

                if (strcmp(argv[1], "FOREIGN") != 0)
                {
                    appendfile= fopen(pfile, "w");
                    int size = (count - 3) / 2;

                    struct schema table[size];

                    for (int i = 0; i < size; i++)
                    {
                        char *ptr = argv[2 * i + 3];

                        for (int j = 0; j < strlen(ptr) + 1; j++)
                        {
                            table[i].attribute_name[j] = ptr[j];
                        }

                        printf(" attribute_name -%s \n", ptr);

                        ptr = argv[2 * i + 4];

                        for (int j = 0; j < strlen(ptr) + 1; j++)
                        {
                            table[i].data_type[j] = ptr[j];
                        }
                        printf(" data_type -%s \n", ptr);
                        fwrite(&table[i], sizeof(struct schema), 1, outfile);
                    }
                }
                else
                {

                    struct schema table;
                    char *ptr = argv[3];

                    for (int j = 0; j < strlen(ptr) + 1; j++)
                    {
                        table.attribute_name[j] = ptr[j];
                    }

                    ptr = argv[6];

                    for (int j = 0; j < strlen(ptr) + 1; j++)
                    {
                        table.data_type[j] = ptr[j];
                    }
                    fwrite(&table, sizeof(struct schema), 1, outfile);
                }

                if (fwrite != 0)
                    printf("contents to file written successfully !\n");
                else
                    printf("error writing file !\n");

                fclose(outfile);

                FILE *infile;
                struct schema input;

                infile = fopen(pfile, "r+");
                if (infile == NULL)
                {
                    fprintf(stderr, "\nError opening file\n");
                    exit(1);
                }

                printf("attribute_name       data_type \n");

                while (fread(&input, sizeof(struct schema), 1, infile))
                {
                    //  printf ("id = %d name = %s %s\n", input.id,input.fname, input.lname);
                    printf("%s   %s\n", input.attribute_name, input.data_type);
                }
                // close file
                fclose(infile);
            }
            else
            {

                wait(NULL);
            }
        }
        // else if (strcmp(argv[0], "FOREIGN") == 0)
        // {

        // }

        else if (strcmp(argv[0], "mkdir") == 0)
        {
            mkdir_1(argv);
        }

        else if (strcmp(argv[0], "date") == 0)
        {
            date_1(argv);
        }

        else if (strcmp(argv[0], "cat") == 0)
        {
            cat_1(argv);
        }

        else
        {
            if (fork() == 0)
            {
                int status = execvp(argv[0], argv);
                if (status == -1)
                {
                    printf("command is not found: %s\n", argv[0]);
                }
                exit(0);
            }
            else
            {
                wait(NULL);
            }
        }

    } while (1);

    return 0;
}
