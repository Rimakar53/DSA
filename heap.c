#include<stdio.h>

void heap(int a[],int n,int i){
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[large]){
        large=l;
    }
    if(r<n&&a[r]>a[large]){
        large=r;
    }
    
    if(large!=i){
        int temp=a[i];
        a[i]=a[large];
        a[large]=temp;
    
    heap(a,n,large);
    }
}
void buildmax(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heap(a,n,i);
    }
}
void heapsort(int a[],int n){
    buildmax(a,n);
    for(int i=n-1;i>0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heap(a,i,0);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
}

int main(){
    int a[7]={12,23,3,89,5,3,1};
    printf("the array\n");
    display(a,7);
    heapsort(a,7);
    printf("sorted array\n");
    display(a,7);
    return 0;
}