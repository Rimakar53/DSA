#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void buildheap(int arr[],int n,int i){
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(arr[l]<arr[large]&&l<n){
        large=l;
    }
     if(arr[r]<arr[large]&&l<n){
        large=r;
    }
    if(large!=i){
        swap(&arr[large],&arr[i]);
        buildheap(arr,n,large);

    }

}

void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        buildheap(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
       swap(&arr[i],&arr[0]);
       buildheap(arr,i,n);
    }
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}

int main(){
    int a[5]={8,1,2,3,90};
    heapsort(a,5);
    display(a,5);
    return 0;
}
