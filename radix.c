// Online C compiler to run C program online
#include <stdio.h>

void sort(int a[],int n,int pos){
      int k=(a[0]/pos)%10;
    for(int i=0;i<n;i++){
        if(a[i]/pos%10>k)
            k=a[i]/pos%10;
    }

    int c[10]={0};
    for(int i=0;i<n;i++){
        c[a[i]/pos%10]++;
    }
    for(int i=1;i<=k;i++){
        c[i]+=c[i-1];
    }
    int b[n];
    for(int i=n-1;i>=0;i--){
        b[--c[a[i]/pos%10]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}
void radixsort(int a[],int n){
    int k=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>k)
            k=a[i];
    }
    for(int pos=1;(k/pos)>0;pos*=10){
        sort(a,n,pos);
    }
}

int main() {
    int a[5]={567,34,23,1,30};
   radixsort(a,5);
      for(int i=0;i<5;i++){
        printf("%d",a[i]);
        printf(" ");
    }
   

    return 0;
}