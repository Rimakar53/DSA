#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void merge(int* arr,int p,int q,int r){
    int i,j;int id1,id2;
    int n1=q-p+2;//q is the mid and p,r is the starting nad ending index;
    int n2=r-q+1;
    int l[n1];
    int ri[n2];
    for( i=0;i<n1-1;i++){
        l[i]=arr[p+i];
    }
    l[i]=INT_MAX;
    for( j=0;j<n2-1;j++){
        ri[j]=arr[q+j+1];
    }
    ri[j]=INT_MAX;
     id1=0;
     id2=0;
    for(int k=p;k<=r;k++){
        if(l[id1]<ri[id2]){
            arr[k]=l[id1];
            id1++;
        }
        else{
            arr[k]=ri[id2];
            id2++;
        }
    }

}

void mergesort(int*arr,int p,int r){
   if(p<r){
        int q=(p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
   }
}
void display(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf(" ");
    }
}

int main(){
    int arr[5]={34,25,2,1,6};
    mergesort(arr,0,4);
    display(arr,5);
    return 0;


}