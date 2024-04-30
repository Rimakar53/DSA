#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int *a,int n,int i){
    int l=i;
    
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&a[left]>a[l]){
        l=left;
    }
    if(right<n&&a[right]>a[l]){
        l=right;
    }
    if(l!=i){
        swap(&a[i],&a[l]);
        heapify(a,n,l);
    }
}

void heapsort(int *a,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

void display(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}

int main(){
    int a[5]={7,2,3,1,4};
    heapsort(a,5);
    display(a,5);
    return 0;
}