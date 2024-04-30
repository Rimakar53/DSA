#include<stdio.h>
int trg(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]==x)
            return i;
    }
    return -1;
}

int main(){
    int arr[5]={6,7,8,9,10};
    printf("%d",trg(arr,5,10));
    return 0;
}
#include<stdio.h>

int search(int a[],int n){
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(i==a[j])
                flag=1;
        }
        if(flag==0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[5]={1,3,5,2,1};
    printf("%d",search(arr,5));
    return 0;
}