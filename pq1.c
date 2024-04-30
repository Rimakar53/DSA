#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAX  100
typedef struct student{
    char name[100];
    int cgpa;
}st;

void swap(int* a,int* b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

void heapify(int pq[],int hash[],int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&pq[left]>pq[largest]){
        largest=left;
    }
     if(right<n&&pq[right]>pq[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&pq[largest],&pq[i]);
        hash[pq[i]]=i;
        hash[pq[largest]]=largest;
        heapify(pq,hash,largest,n);

    }
}
/*
void buildpq(int pq[],int hash[],int n){
    for(int i=0;i<n;i++){
        pq[i]=i;
        hash[i]=i;
    }
    for(int i=n/2-1;i>=0;i--){
        heapify(pq,hash,i,n);
    }
}*/

void enqueue(int pq[],int hash[],int x,int n,struct student r[])
 {
    pq[n-1]=n-1;
    int childid=n-1;
    int parentid=(n-1)/2;
    while(parentid>=0&& r[pq[childid]].cgpa>r[pq[parentid]].cgpa){
        swap(&pq[parentid],&pq[childid]);
        hash[pq[childid]]=childid;
        hash[pq[parentid]]=parentid;
        childid=parentid;
        parentid=(childid-1)/2;
    }
}
void dequeue(int pq[],int hash[],int n){
    if(n==0){
        printf("the queue is empty\n");
    }
    int x=pq[0];
    hash[x]=-1;
    pq[0]=pq[n-1];
    hash[pq[0]]=0;
    n--;
    heapify(pq,hash,0,n);
    printf("the highest cgpa student roll is %d\n",x);

}

void increase(int pq[],int hash[],int i,int n, struct student r[]){
    if(i>n){
        printf("invalid index\n");
    }
    printf("enter new cgpa  for %s",r[i].name);
    scanf("%d",&r[i].cgpa);
       int childid=i;
    int parentid=(childid-1)/2;
    while(parentid>=0&& r[pq[childid]].cgpa>r[pq[parentid]].cgpa){
        swap(&pq[parentid],&pq[childid]);
        hash[pq[childid]]=childid;
        hash[pq[parentid]]=parentid;
        childid=parentid;
        parentid=(childid-1)/2;
    }

}

void display(st r[],int pq[],int n){
    for(int i=0;i<n;i++){
        int roll=pq[i];
        printf("%d\t\t%s\t\t%d\n",roll,r[roll].name,r[roll].cgpa);
    }
}

void print(int*a,int n){
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf(" ");
    }
}

int main(){
    st r[MAX];
    int pq[MAX];
    int hash[MAX]={0};
    int n=0;
    printf("enter student name:");
    scanf("%s",r[n].name);
    printf("enter cgpa:");
    scanf("%d",&r[n].cgpa);
    enqueue(pq,hash,n,n+1,r);
    n++;
    printf("\n");
     printf("enter student name:");
    scanf("%s",r[n].name);
    printf("enter cgpa:");
    scanf("%d",&r[n].cgpa);
    enqueue(pq,hash,n,n+1,r);
    n++;
    printf("\n");
      printf("enter student name:");
    scanf("%s",r[n].name);
    printf("enter cgpa:");
    scanf("%d",&r[n].cgpa);
    enqueue(pq,hash,n,n+1,r);
    n++;
    display(r,pq,n);
   increase(pq,hash,2,n,r);
    display(r,pq,n);
    printf("hash array\n");
    print(hash,n);
    return 0;

}