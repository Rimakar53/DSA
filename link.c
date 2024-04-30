#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list*next;
}node;
node* create(node*p)
{
    node* temp,*tail;
    node*q=(node*)malloc(sizeof(node));
    printf("enter the element:");
    scanf("%d",q->data);
    q->next=NULL;
    if(p==NULL){
        tail=temp=q;
    }
    int y;
    printf("enter 1 to continue and 0 to finish:");
    scanf("%d",&y);
    while(y){
         node*q=(node*)malloc(sizeof(node));
        printf("enter the element:");
        scanf("%d",q->data);
        q->next=NULL;
        tail->next=q;
        tail=q;
         printf("enter 1 to continue and 0 to finish:");
        scanf("%d",&y);
    }
    return temp;
}
void display(node*p){
    while(p){
        printf("%d\n",p->data);
        p=p->next;
    }
}

int main()
{
   node* head=NULL;
    head=create(head);
    display(head);
    return 0;


}