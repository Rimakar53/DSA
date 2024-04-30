#include<stdio.h>
#include<stdlib.h>
void tripletform(int**matrix,int row,int col,int**triplet){
    int c=1;
    triplet[0][0]=row;
    triplet[0][1]=col;
    triplet[0][2]=2;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]!=0){
                triplet[c][0]=i;
                triplet[c][1]=j;
                triplet[c][2]=matrix[i][j];
                c++;

            }
        }
    }

}



int main()
{
   int m,n;
   printf("enter the value of m and n:");
   scanf("%d%d",&m,&n);
   int k=2;
   int**matrix=(int**)malloc(m*sizeof(int));
   for(int i=0;i<m;i++){
    matrix[i]=(int*)malloc(n*sizeof(int));
   }
   int**triplet=(int**)malloc((3)*sizeof(int));
    for(int i=0;i<k+1;i++){
    triplet[i]=(int*)malloc(3*sizeof(int));
   }

   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        printf("enter the value of element on the position %d ,%d:",i,j);
        scanf("%d",&matrix[i][j]);
    }
   }
   tripletform(matrix,m,n,triplet);
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        printf("%d",triplet[i][j]);
        printf(" ");
    }
    printf("\n");
   }
   return 0;
    
}