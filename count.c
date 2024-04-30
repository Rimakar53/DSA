#include<stdio.h>

void sort(int a[],int n){
    int k=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>k)
            k=a[i];
    }
    int c[10]={0};
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    for(int i=1;i<=k;i++){
        c[i]+=c[i-1];
    }
    int b[n];
    for(int i=n-1;i>=0;i--){
        b[--c[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

int main(){
    int a[8]={5,6,6,4,3,5,9,3};
    sort(a,8);
    for(int i=0;i<8;i++){
        printf("%d",a[i]);
        printf(" ");
    }
    return 0;
}