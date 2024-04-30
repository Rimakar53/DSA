#include<stdio.h>
#include<stdlib.h>

void bubblesort(int* a,int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insertionsort(int* a,int n){
    int key,j;
    for(int i=1;i<n-1;i++){
        key=a[i];
        j=i-1;
        while(a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

    }
}

void selectionsort(int* a,int n){
    int min;
    for (int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
           if(a[min]>a[j]){
                min=j;
           }
           if(min!=i){
                 int temp=a[i];
                a[i]=a[min];
                a[min]=temp;

           }
          

         
        }
    }
}

void display(int* a,int n ){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}

int main()
{
    int arr[5];
    for(int i=0;i<5;i++){
        printf("enter element:");
        scanf("%d",&arr[i]);
    }
    printf("the array is\n");
    display(arr,5);
    bubblesort(arr,5);
    printf("the sorted array is\n");
    display(arr,5);
    insertionsort(arr,5);
    printf("the sorted array is\n");
    display(arr,5);
    selectionsort(arr,5);
    printf("the sorted array is\n");
    display(arr,5);
    return 0;

}
#include<stdio.h>
#include<stdlib.h>
int bubblesort(int* a,int n){
    int c1=0;
    for(int i=0;i<n-1;i++){
        int t=0;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                t=1;
                c1++;
            }
            
        }
        if(t==0)
            break;
    }
    return c1;
}

int insertionsort(int* a,int n){
    int key,j,c=0;
    for(int i=1;i<=n-1;i++){
        key=a[i];
        j=i-1;
        while(a[j]>key){
            a[j+1]=a[j];
            j--;
            c++;
        }
        a[j+1]=key;
    }
    return c;
    }
    
int selectionsort(int* a,int n){
    int c2=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
            c2++;
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    return c2;
}
void display(int* a,int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}
void input(int* a,int n){
    for(int i=0;i<n;i++){
        printf("enter the element:");
        scanf("%d",&a[i]);
    }
}

int main()
{
    int a[10];
    input(a,10);
    printf("the number of passes required is %d\n",bubblesort(a,10));
    printf("the array is \n");
    printf("selection sort %d\n",selectionsort(a,10));
    display(a,10);
     printf("the array is \n");
     printf("insertion sort is %d\n",insertionsort(a,10));
     display(a,10);
     return 0;
    
    
}