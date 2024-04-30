// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list* next;
}node;

node* insertbeg(node*p,int x){
    node* q=(node*)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(p==NULL)
        return q;
    else
    {
        q->next=p;
    }    
}

void display(node* p){
    while(p){
        printf("%d",p->data);
        printf(" ");
        p=p->next;
    }
}

node* delend(node*p){
    if(p==NULL)
        return NULL;
    else if(p->next==NULL)
    {
        free(p);
        return NULL;
    }
    else
    {   node* pre=NULL;
        node* temp=p;
       while(p->next!=NULL){
            pre=p;
            p=p->next;
       }
       node* delp=p;
       pre->next=NULL;
       free(delp);
       return temp;

    }
}

int main() {
    node* p=NULL;
    p=insertbeg(p,8);
    p=insertbeg(p,7);
    p=insertbeg(p,89);
    display(p);
    p=delend(p);
    p=delend(p);
    display(p);

    
    
    

    return 0;
}