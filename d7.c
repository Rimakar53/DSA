// Online C compiler to run C program online
#include <stdio.h>
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

int** tripletformation(int** a,int m,int n){
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0)
                k++;
        }
    }
    int  r=k+1;
   
    
    int **triplet=(int**)malloc(r*sizeof(int*));
    for(int i=0;i<m;i++){
        triplet[i]=(int*)malloc(3*sizeof(int));
    }
    
    triplet[0][0]=m;
    triplet[0][1]=n;
    triplet[0][2]=k;
    int c=1;
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

 display(triplet,r,3);
 return triplet;
   
    
}
void addtriplet(int m,int n,int **t1,int **t2){
    int a=t1[0][2];
    int b=t2[0][2];
    int c=a+b;
    int r=c+1;
    int **ad=(int**)malloc(r*sizeof(int));
    for(int i=0;i<3;i++){
        ad[i]=(int*)malloc(3*sizeof(int));
    }
    int k=1;
    ad[0][0]=m;
    ad[0][1]=n;
    ad[0][2]=c;
    printf("%d\n",t1[1][0]);
    printf("%d\n",t2[1][0]);
    
    for(int i=1;i<a;i++){
        for(int j=0;i<=3;i++){
            ad[k][j]=t1[i][j];

        }
        k++;
    }
    k++;
        for(int i=1;i<=b;i++){
        for(int j=0;i<3;i++){
            ad[k][j]=t2[i][j];

        }
        k++;
        
    }
    display(ad,r,3);
    

}

int main() {
     int **a=(int**)malloc(3*sizeof(int*));
    for(int i=0;i<3;i++){
        a[i]=(int*)malloc(3*sizeof(int));
    }
  printf("enter the 1 st element:");
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          printf("enter the element:");
          scanf("%d",&a[i][j]);
      }
  }
   int **b=(int**)malloc(3*sizeof(int*));
    for(int i=0;i<3;i++){
        b[i]=(int*)malloc(3*sizeof(int));
    }
     printf("enter the 1 st element:");
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          printf("enter the element:");
          scanf("%d",&b[i][j]);
      }
  }
 int** t1= tripletformation(a,3,3);
 printf("second matrix\n");
 int** t2= tripletformation(b,3,3);
 printf("addition\n");
  addtriplet(3,3,t1,t2);

 

    return 0;
}
/*

void addtriplet(int m,int n,int **t1,int **t2){
    int a=t1[0][2];
    int b=t2[0][2];
    int c=a+b;
    int r=c+1;
    int **ad=(int**)malloc(r*sizeof(int));
    for(int i=0;i<3;i++){
        ad[i]=(int*)malloc(3*sizeof(int));
    }
    int k=1;
    ad[0][0]=m;
    ad[0][1]=n;
    ad[0][2]=c;
    for(int i=1;i<r;i++){
        for(int j=0;i<3;i++){
            ad[k][j]=t1[i][j];

        }
        k++;
    }
    k++;
        for(int i=1;i<r;i++){
        for(int j=0;i<3;i++){
            ad[k][j]=t2[i][j];

        }
        k++;
    }
    

}
*/