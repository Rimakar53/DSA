#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int size;
    int f;
    int r;
    int* arr;
};


void enque(struct queue* q,int val){
    if(q->r==q->size-1)
            printf("the queue is full\n");
    else{
        q->r++;
        q->arr[q->r]=val;
    }
    
}

int deque(struct queue* q){
    int a=-1;
    if(q->f==q->r)
        printf("the queue is empty\n");
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size=2;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int*));
     printf("%d\n",enque(&q,12));;
   
    printf("the value is %d\n",deque(&q));
    printf("the value is %d\n",deque(&q));
    return 0;
}// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int r;
    int f;
    int* arr;
};
void enqueue(struct queue* q,int val){
    if((q->r+1)%q->size==q->f)
        printf("this queue is full\n");
    else
    {
        q->r++;
        q->arr[q->r]=val;
        
    }
}

int dequeue(struct queue* q){
    int a=-1;
    if(q->r==q->f)
        printf("dequeue is not possible\n");
    else
    {
        q->f++;
        a=q->arr[q->f];
        
    }
    return a;
}


int main() {
    struct queue q;
    q.f=q.r=0;
    q.size=2;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,56);
    enqueue(&q,67);
    enqueue(&q,47);
    printf("the number is %d\n",dequeue(&q));
    
    

    return 0;
}

#include<stdio.h>
void enqueue(int q[],int *r,int *f,int n,int x){
    if(*r==n-1)
        printf("overflow");
    else
    {   if(*r==-1&&*f==-1){
            *r=*f=0;
            q[*r]=x;
        }
        else
        {
            *r=*r+1;
            q[*r]=x;
        }
    }
        
    
}

void dequeue(int q[],int *r,int *f)
{   if(*f==-1)
        printf("underflow");
    else{
        printf("%d",q[*f]);
        *f=*f+1;
    }
}
void display(int q[],int *f,int *r){
    for(int i=0;i<=*r;i++){
        printf("%d",q[i]);
        printf(" ");
    }
}

int main()
{
    int f,r;
    f=r=-1;
    int q[5];
    enqueue(q,&r,&f,5,89);
    enqueue(q,&r,&f,5,9);
    display(q,&f,&r);
    dequeue(q,&r,&f);
    dequeue(q,&r,&f);
    return 0;
    
}