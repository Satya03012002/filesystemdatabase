#include <stdio.h>
#include <stdlib.h>




struct Graph{
    int attribute;
    char **arr;
};
struct Graph* adjMatrix = NULL;

void print(){
    for(int i = 0; i < adjMatrix->attribute; i++){
        for(int j = 0; j < adjMatrix->attribute; j++){
            printf("%d ",adjMatrix->arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}


struct Graph* CreateGraph(){
    
     adjMatrix = (struct Graph*)malloc(sizeof(struct Graph));
   printf("enter the no. of attribute\n");
   scanf("%d",&adjMatrix->attribute);
   printf("adjMatrix->attribute = %d\n", adjMatrix->attribute);
   
   (adjMatrix->arr) = (int**)malloc(((adjMatrix->attribute))*sizeof(int*));
   
  for(int i = 0; i < adjMatrix->attribute; i++){
      adjMatrix->arr[i] = (int*)malloc(((adjMatrix->attribute))*sizeof(int));
  }
  for(int j = 0; j < adjMatrix->attribute; j++){
       for(int k = 0; k < adjMatrix->attribute; k++){
           
           adjMatrix->arr[j][k] = 5+j;
        // adjMatrix->arr[0][k] = 5;
        // adjMatrix->arr[1][k] = 6;
        // adjMatrix->arr[2][k] = 7;
        // adjMatrix->arr[3][k] = 8;
        // adjMatrix->arr[4][k] = 9;
        // adjMatrix->arr[5][k] = 9;
      
        }
    }

   print();
  
  return adjMatrix;
    
    
    
}

int main()
{


    printf("create Graph\n");
    adjMatrix = CreateGraph();
   FILE *fptr;
   int a[adjMatrix->attribute][adjMatrix->attribute];

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("program.txt","w");


   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }


        //  for(int i = 0; i < adjMatrix->attribute; i++){

        //     // fwrite(adjMatrix->arr,sizeof(int),adjMatrix->attribute*adjMatrix->attribute,fptr);
        //     fwrite(adjMatrix->arr[i],sizeof(int),adjMatrix->attribute,fptr);

        //  }
         
        for(int i = 0; i<adjMatrix->attribute; i++){
               
               
               fputs(adjMatrix->arr[i], fptr);
        }

        // fwrite(adjMatrix->arr[0],sizeof(int),adjMatrix->attribute,fptr);
        // fscanf("\n",fptr);


         int b[adjMatrix->attribute];
        
        fptr = fopen("program.txt","r");

        // for(int i = 0; i<adjMatrix->attribute; i++){
              
            
        //     fread(b, sizeof(int) ,adjMatrix->attribute, fptr);
        //     for(int i = 0; i<adjMatrix->attribute; i++){
        //      printf("%d ",b[i]);
        //   }
        //   printf("\n");
            
        //   }

        // fread(b, sizeof(int) ,adjMatrix->attribute, fptr);

        // fread(a,sizeof(int),adjMatrix->attribute*adjMatrix->attribute,fptr);
        // for(int i = 0; i<adjMatrix->attribute; i++){
        //     for(int j = 0; j<adjMatrix->attribute;j++){

        //           printf("%d ",a[i][j]);
        //     }
        //      printf("\n");
            
        // }

        //   for(int i = 0; i<adjMatrix->attribute; i++){
        //      printf("%d ",b[i]);
        //   }

    //     b = fgetc(fptr);
	// while (str1 != EOF)
	// 	{
	// 		printf ("%c", str1);
	// 		str1 = fgetc(fptr);
	// 	}
   
   fclose(fptr);

   return 0;
}
