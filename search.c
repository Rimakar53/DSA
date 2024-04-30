#include<stdio.h>
#include<stdlib.h>

void ls(int *a,int n,int x){
    for(int i=0;i<n;i++)
    {
        if(a[i]==x){
            printf("data found in the position %d",i);
            return;
        }
    }
    printf("data not found:");
    return;
}


void bs(int *a,int n,int x)
{
    int low,mid,high;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
         mid=(low+high)/2;
    
        if(a[mid]==x)
        {
            printf("data found in the position %d",mid);
            return ;
        }
        if(a[mid]<x)
        {
            low=mid+1;
        }
        if(a[mid]>x)
        {
            high=mid-1;
        }
    }

    printf("data not found:");
    return;

}

void is(int*a,int n,int x)
{   int h,l,pos=0;
    l=0;h=n-1;
     while(pos<n&&pos>0)
    {
        l=0;h=n-1;
        pos=l+((h-l)*(x-a[l]))/(a[h]-a[l]);
        if(a[pos]==x)
        {
            printf("data found on position %d",pos);
            return;
        }
        else
        {
            h=pos-1;
        }
    }
    printf("data  not found:");
    return;
    

}

int main()
{
    int a[5]={2,4,6,8,10};
    is(a,5,4);
    return 0;
}

