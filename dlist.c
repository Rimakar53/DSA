#include<stdio.h>
#include<stdlib.h>
typedef struct dlist*{
    int data;
    struct list* next;
}node;
node* create(node*p){
    node*temp,*tail;
    node*q=(node*)malloc(sizeof(node*));
    printf("enter the element:");
    scanf("%d",q->data);
    if(p==NULL){
        q->next=q;
        temp=tail=p;
    }
    int y;
    printf("enter 1 to contunie and 0 to exit:");
    scanf("%d",&y);
    while(y){
         node*q=(node*)malloc(sizeof(node*));
        printf("enter the element:");
        scanf("%d",q->data);
        q->next=temp;
        tail->next=q;
        tail=q;
        printf("enter 1 to contunie and 0 to exit:");
        scanf("%d",&y);
    }
    return temp;

}
void display(node*p){
    do{
        printf("%d",p->next);
        printf(" ");
        p=p->next;
    }while(p-next!=temp);
}
int main()
{
    node*head=NULL;
    head=create(head);
    dispaly(head);
    return 0
}