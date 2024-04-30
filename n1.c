#include<stdio.h>
#include<stdlib.h>
void countsort(int *a,int n){
    int k=a[0];int b[n];
    for(int i=0;i<n;i++){
        if(a[i]>k)
            k=a[i];
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]=+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
      b[ --count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}
void display(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}

int main(){
    int a[5]={1,9,4,5,3};
    countsort(a,5);
    display(a,5);
}