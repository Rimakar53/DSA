#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list* next;
}node;

node* enqueue(node* f){
    node* r=f;
    node* n=(node*)malloc(sizeof(node));
    printf("enter the element:");
    scanf("%d",&n->data);
    n->next=NULL;
    if(f==NULL)
        return n;
    else{
       while(f->next!=NULL){
           f=f->next;
       }
       f->next=n;
     
    }
    return r;
}

void display(node* p){
    while(p){
        printf("%d",p->data);
        printf(" ");
        p=p->next;
    }
}

int main()
{
    node* f ;
    f=NULL;
   f= enqueue(f);
    f= enqueue(f);
    display(f);
    return 0;
}