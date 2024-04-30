#include<stdio.h>
void triplet(int**a,int result,int row,int col){
    int k=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                k++;
            }
        }
    }
    int triplet[k+1][3];
    triplet[0][0]=row;
    triplet[0][1]=col;
    triplet[0][2]=k;
    int c=1;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                triplet[c][0]=i;
                triplet[c][1]=j;
                triplet[c][2]=a[i][j];
                c++;
            }
        }
     }
     

    }

int main()
{
    int m,n;
    printf("enter the value of m and n:");
    scanf("%d %d",&m,&n);

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("enter the elements:");
            scanf("%d",&arr[i][j]);
        }
    }
    return 0;
}


