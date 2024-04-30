#include<stdio.h>
#include<stdlib.h>
void display(int** a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           printf("%d",a[i][j]);
           printf(" "); 
        }
        printf("\n");
    }
}
int nonzeroelement(int** a,int m,int n){
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0){
                k++;
            }
        }
    }
    return k;
}
int beneficial(int m,int n,int r){
    if(m*n>r*3){
        return 1;
    }
    else
        return 0;
}
void tripletform(int** a,int** triplet,int m,int n,int k){
    int c=1;
    triplet[0][0]=m;
    triplet[0][1]=n;
    triplet[0][2]=k;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0){
                triplet[c][0]=i;
                triplet[c][1]=j;
                triplet[c][2]=a[i][j];
                c++;
            }
          
        }
    }

}
int** transposeform(int** triplet,int r){
    int j=0;
    for(int i=0;i<r;i++){
        int temp =triplet[i][j];
        triplet[i][j]=triplet[i][j+1];
        triplet[i][j+1]=temp;
    }
    return triplet;

}
 void sparsh(int** a,int r){

    int m=a[0][0];
    int n=a[0][1];
      int** matrix=(int**)malloc(m*sizeof(int*));
        for(int i=0;i<m;i++){
            matrix[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=0;
        }
    }
    for(int i=1;i<r;i++){
        int x=a[i][0];
        int y=a[i][1];
        matrix[x][y]=a[i][2];
    }
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           printf("%d",matrix[i][j]);
           printf(" "); 
        }
        printf("\n");
    }
 }

    
    
 


int main(){
    int m,n;
    printf("enter the value of m and n:");
    scanf("%d%d",&m,&n);
    int** a=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        a[i]=(int*)malloc(n*sizeof(int*));
    }
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        printf("enter the element:");
        scanf("%d",&a[i][j]);
    }
}
int k=nonzeroelement(a,m,n);
int r=k+1;
int b=beneficial(m,n,r);
if(b==0){
    printf("the triplet form is not beneficial:");
}
else
{
    int** triplet=(int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++){
        triplet[i]=(int*)malloc(3*sizeof(int));
    }

        tripletform(a,triplet,m,n,k);
        display(triplet,r,3);
        int** transpose=(int**)malloc(r*sizeof(int*));
        for(int i=0;i<r;i++){
            transpose[i]=(int*)malloc(3*sizeof(int));
    }
    transpose=transposeform(triplet,r);
    printf("the transpose matrix is\n");
    display(transpose,r,3);
    printf("the sparsh transpose is\n");
    sparsh(transpose,r);
    
}

return 0;
}