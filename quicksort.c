#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int* arr,int left,int right){
    int i=left-1;
    int pivot=arr[right];
    for(int j=left;j<=right-1;j++){
        if(arr[j]<=pivot){
            i++;
            printf("%d----- %d\n",arr[j],arr[i]);
            swap(&arr[j],&arr[i]);
           // printf("%d %d",arr[j],arr[i]);
        }
    }
    swap(&arr[i+1],&arr[right]);
    return i+1;
}

void quicksort(int* arr,int left,int right){
    if(left<right){
        int k=partition(arr,left,right);
        quicksort(arr,left,k-1);
        quicksort(arr,k+1,right);
    }

}

void display(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
}

int main(){
    int arr[10]={2,3,4,6,5};
    quicksort(arr,0,4);
    display(arr,5);
    return 0;

}
