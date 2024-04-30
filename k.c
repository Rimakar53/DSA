#include<stdio.h>
void selectionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void search(int a[],int k,int n){
    selectionsort(a,n);
    printf("the %d th largest element is:",k);
    printf("%d",a[n-k]);
}

int main(){
    int a[5]={5,3,1,2,4};
    search(a,2,5);
    return 0;
}
// Online C compiler to run C program online
#include <stdio.h>

void change(int a[],int n){
    int sum=1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
           sum*=a[j];
        }
        a[i]=sum;
        sum=1;
    }
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}

int main() {
   int a[4]={3,4,2,1};
   display(a,4);
   printf("after\n");
   change(a,4);
   display(a,4);

    return 0;
}
#include<stdio.h>
void searh(int a[],int n,int x){
    int m;
    for(int i=0;i<n;i++){
        m=x-a[i];
        for(int j=i;j<n;j++){
            if(a[j]==m)
            {
                printf("true");
                return;
            }
        }
    }
    printf("false");
}

int main(){
    int arr[6]={11,15,6,8,9,10};
    searh(arr,6,27);
    return 0;
}