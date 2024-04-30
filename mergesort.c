// Online C compiler to run C program online
#include <stdio.h>
void merge(int a[],int si,int ei,int mid){
     int b[10];
    int i,j;
    i=si;
    j=mid+1;
    int k=si;
    while(i<=mid&&j<=ei)
    {
        if(a[i]<a[j])
         {  b[k]=a[i];
            i++;
            k++;
         }
        else
          {  b[k]=a[j];
            j++;k++;
          }
    }
    
   while(i<=mid){
       b[k]=a[i];
       k++;i++;
   }
   while(j<=ei){
       b[k]=a[j];
       k++;j++;
   }
   for(int i=si;i<=ei;i++){
       a[i]=b[i];
   }

    
    
    
}
void mergesort(int a[],int si,int ei){
    int mid;
    if(si<ei){
        mid=(si+ei)/2;
        mergesort(a,si,mid);
        mergesort(a,mid+1,ei);
        merge(a,si,ei,mid);
    
}
}

int main() {
    int a[5]={6,1,2,5,3};
    mergesort(a,0,4);
    for(int i=0;i<5;i++){
        printf("%d",a[i]);
        printf(" ");
    }

    return 0;
}