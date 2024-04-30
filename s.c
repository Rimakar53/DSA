// Online C compiler to run C program online
#include <stdio.h>

void bubble(int a[],int n){
    int flag=0;int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp =a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
            count++;
        }
        if(flag==0)
            break;
    }
    printf("the number of pass required  is %d\n",count);
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}

void insertionsort(int a[],int n){
    int c=0;
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
            c++;
        }
        a[j+1]=key;
    }
    printf("the comparison required is %d\n",c);
}

void selectionsort(int a[],int n){
    int c=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min])
                min=j;
                c++;
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        
        
    }
    printf("number of comparison required is %d\n",c);
}

void cocktailsort(int a[],int n){
    int c=0;
    int l=0;
    int r=n-1;
    int s=1;
    while(s){
        s=0;
        for(int i=l;i<r;i++){
            if(a[i]>a[i+1]){
                 int temp =a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                s=1;
            }
            c++;
        }
    if(!s)
        break;
    s=0;
    for(int i=r-1;i>=l;i--){
          if(a[i]>a[i+1]){
                 int temp =a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                s=1;
          }
          c++;
    }
    l++;
    
    }
    printf("the comparison required is %d\n",c);
}

int main() {
  int a[7]={7,6,5,4,3,2,1};
  display(a,7);
  printf("after sorting\n");
  cocktailsort(a,7);
  display(a,7);
  

    return 0;
}