#include<stdio.h>
#include<stdlib.h>
void input(int* a,int n){
    for(int i=0;i<n;i++){
        printf("enter element:");
        scanf("%d",&a[i]);
    }
}
void display(int* a,int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}

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
    printf("the number of passes required\n");
    printf("%d\n",c);
}

void insertionsort(int* a,int n)
{   int c2=0;
  int key, j;
  for(int i=1;i<=n-1;i++){
    key=a[i];
    j=i-1;
    while(a[j]>key){
        a[j+1]=a[j];
        j--;
        c2++;
    }
    a[j+1]=key;
  }
   printf("the number of passes required\n");
    printf("%d\n",c2);
}

void selectionsort(int* a,int n)
{   int c3=0;
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min]){
                min=j;
            }
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            c3++;
        }
    }
     printf("the number of passes required\n");
    printf("%d\n",c3);
}




int main()
{
    int arr1[5],arr2[10],arr[10];
    input(arr1,5);
    display(arr1,5);
    printf("the sorted array is\n");
    bubblesort(arr1,5);
    display(arr1,5);
    printf("the sorted array is\n");
    insertionsort(arr1,5);
    display(arr1,5);
    printf("the sorted array is\n");
    selectionsort(arr1,5);

    return 0;

}