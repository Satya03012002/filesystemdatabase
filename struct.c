// C program for writing
// struct to file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct to read and write


// int main ()
// {
// 	// FILE *outfile;
	
// 	// // open file for writing
// 	// outfile = fopen ("person.dat", "w");
// 	// if (outfile == NULL)
// 	// {
// 	// 	fprintf(stderr, "\nError opened file\n");
// 	// 	exit (1);
// 	// }

// 	// struct person input1 = {1, "rohan", "sharma"};
// 	// struct person input2 = {2, "mahendra", "dhoni"};
	
// 	// // write struct to file
// 	// fwrite (&input1, sizeof(struct person), 1, outfile);
// 	// fwrite (&input2, sizeof(struct person), 1, outfile);
	
// 	// if(fwrite != 0)
// 	// 	printf("contents to file written successfully !\n");
// 	// else
// 	// 	printf("error writing file !\n");

// 	// // close file
// 	// fclose (outfile);

// //     FILE *infile;
// //     struct schema input;
    
// //    /* Seek to the beginning of the file */
// // //    fseek(infile, 0, SEEK_SET);

// // // Open person.dat for reading
// // infile = fopen ("./harshu/SATYA.dat", "r");
// // if (infile == NULL)
// // {
// // fprintf(stderr, "\nError opening file\n");
// // exit (1);
// // }

// // // read file contents till end of file
// //  printf ("id       name \n");
// // while(fread(&input,sizeof(struct schema), 1, infile)){
// // 	    printf("hello\n");
// // 		printf ("%s \n",input.attribute_name);
// // 		printf("hello\n");
       
// // 		// printf ("%s %s\n",input.attribute_name, input.data_type);
// // }
// // // close file
// // fclose (infile);
// 	struct schema
// 	{
// 		char *attribute_name;
// 		char *data_type;
// 	};

// 	struct schema 

// 	return 0;
// }


struct Student{

    char attribute_name[50];
    char data_type[60];
};
struct final{
   struct Student arr[2];
};


int main()
{
	FILE *of;
	of = fopen("c1", "a");
	if (of == NULL)
	{
	  fprintf(stderr, "Error to open the file");
      exit (1);
	}
	 struct final table;
     char *ptr = "hello";
	//  for (int i = 0; i < 2; i++)
   //              {   
                    
   //              }

                        for (int i = 0; i < 2; i++)
                        {  
                           int j ;
                             for (j= 0; j < strlen(ptr)+1; j++)
                           {
                              table.arr[i].attribute_name[j] = ptr[j];
                            table.arr[i].data_type[j] = ptr[j];
                           }
                          
                            
                        }

                   
                fwrite(&table, sizeof(struct final), 1, of);

	if (fwrite != 0)
	  printf("Contents to file written successfully !\n");
   else
      printf("Error writing file !");
   fclose (of);
  
   FILE *inf;
   struct final input;
   inf = fopen ("c1", "r+");
   if (inf == NULL) {
	  fprintf(stderr,"Error to open the file");
      exit (1);
   }
   int i = 0;
  
      
      while(fread(&input, sizeof(struct final), 1, inf)){
      
           printf("i - %d\n",i);
        for (int i = 0; i < 2; i++)
                {   printf("i in lopp- %d\n",i);
                    printf (" %s %s\n", input.arr[i].attribute_name, input.arr[i].data_type);
                    
                }

      // printf ("roll_no = %s , name = %s\n", data->attribute_name, data->data_type);
     i++;

   }

   // fread(data, sizeof(struct Student), 2, inf);

   // for (int i = 0; i < 2; i++)
   //              {   
   //                  printf (" %s %s\n", data[i].attribute_name, data[i].data_type);
                    
   //              }
      
   fclose (inf);
}