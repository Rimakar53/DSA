#include<stdio.h>
typedef struct list{
    int data;
    struct list* next;
}node;
node* create(node*p){
    node* tail,*temp;
    node*q=(node*)malloc(sizeof(node));
    printf("enter the value of element:");
    scanf("%d",&q->data);
    q->next=NULL;
    if(p==NULL){
        temp=tail=q;
    }
    int y;
    printf("enter 1 to continue and 0 to exit:");
    scanf("%d",&y);
    while(y){
        node*q=(node*)malloc(sizeof(node));
        printf("enter the value of element:");
        scanf("%d",&q->data);
        q->next=NULL;
        tail->next=q;
        tail=q;
         printf("enter 1 to continue and 0 to exit:");
        scanf("%d",&y);
    }
}
int main()
{
    node* head =NULL;
    head =craete(head);
    display(head);
}