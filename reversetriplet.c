#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[2][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("enter the elements:");
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d",arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    int j=1;
    printf("transverse matrx is\n:");
    for(int i=0;i<2;i++){
        
            int temp;
            temp=arr[i][j];
            arr[i][j]=arr[i][j+1];
            arr[i][j+1]=temp;
        }
    
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d",arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
