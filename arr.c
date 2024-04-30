#include<stdio.h>
#include<stdlib.h>
void bubblesort(int* a,int n){
    int t,c=0;
    for(int i=0;i<n-1;i++){
              t=0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                t=1;
               
            }
             c++;
        }
        if(t==0)
            break;
        
    }
}
int main()
{
    int n,flag;
    printf("enter n:");
    scanf("%d",&n);
    int arr1[n], arr2[n];
    for(int i=0;i<n;i++){
        printf("enter element:");
        scanf("%d",&arr1[i]);
    }
    printf("enter the second array\n");
      for(int i=0;i<n;i++){
        printf("enter element:");
        scanf("%d",&arr2[i]);
    }
    bubblesort(arr1,n);
    bubblesort(arr2,n);
    for(int i=0;i<n;i++){
         flag=0;
        if(arr1[i]==arr2[i])
            flag=1;
    }

    if(flag==1)
        printf("both array are same");
    else
        printf("the array is not same");

    return 0;
    
}