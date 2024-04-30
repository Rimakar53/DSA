#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct priority{
    int size;
    int arr[MAX];
}pq;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(pq* p,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<p->size&&p->arr[left]>p->arr[largest]){
        largest=left;
    }
     if(right<p->size&&p->arr[right]>p->arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(&p->arr[largest],&p->arr[i]);
        heapify(p,largest);
    }
}

void enqueue(pq* p){
    int x;
    printf("enter your data:");
    scanf("%d",&x);
    if(p->size==MAX){
        printf("overflow\n");
    }
    if(p->size==0){
        p->arr[p->size]=x;
        p->size++;
    }
    else{
        p->arr[p->size]=x;
        p->size++;
        int childid=p->size-1;
        int parentid=(childid-1)/2;
        while(parentid>=0&&p->arr[childid]>p->arr[parentid]){
            swap(&p->arr[parentid],&p->arr[childid]);
            childid=parentid;
            parentid=(childid-1)/2;

        }
    }
}

void display(pq*p){
    for(int i=0;i<p->size;i++){
        printf("%d",p->arr[i]);
        printf(" ");
    }
}

void dequeue(pq* p){
    int x=p->arr[0];
    p->arr[0]=p->arr[p->size-1];
    p->size--;
    heapify(p,0);
    printf("the largest element is %d\n",x);


}

int main(){
    pq p;
    p.size=0;
    enqueue(&p);
    enqueue(&p);
    enqueue(&p);
    enqueue(&p);
    display(&p);
    dequeue(&p);
    dequeue(&p);
    return 0;


}