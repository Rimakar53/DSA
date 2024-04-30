#include<stdio.h>
#include<stdlib.h>
int main(){
  int  matrix[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("enter the elements on position:");
            scanf("%d",matrix[i][j]);

        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d",matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    int m=matrix[0][0];
    int n=matrix[0][1];
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    int k,l;
    for(int i=1;i<3;i++){
        k=matrix[i][0];
        l=matrix[i][1];
        arr[k][l]=matrix[i][2];
        }
    
    printf("the matrix is\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d",arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;

}