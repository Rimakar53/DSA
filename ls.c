#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list*next;
}node;

node* delend(node*p)
{   node* pre=NULL;
    if(p==NULL)
        return p;
    else if(p->next==NULL){

         printf("this is an empty list\n");
        free(p);
        return NULL;
       
    }
    else
      {  node* temp =p,*pre=NULL;
        while(p)
        {   pre=p;
            p=p->next;

        }
        node* delp=p;
        pre->next=p->next;
        free(delp);
        return temp;
      }


}

node* insertbegin(node* p)
{
    node*q=(node*)malloc(sizeof(node));
    printf("enter the element:");
    scanf("%d",&q->next);
    q->next=NULL;
    if(p==NULL)
        return q;
    else
     {   q->next=p;
        return q;
     }

}

void display(node* p){
    while(p)
    {
        printf("%d",p->data);
        printf(" ");
        p =p->next;
    }
}
node* create(node*p){
    node*temp,*tail;
    node*q=(node*)malloc(sizeof(node));
    printf("enter element:");
    scanf("%d",&q->data);
    q->next=NULL;
    if(p==NULL){
        temp=tail=q;
    }
    int y;
    printf("enter 1 to continue and 0 to finish:");
    scanf("%d",&y);
    while(y){
        node*q=(node*)malloc(sizeof(node));
         printf("enter element:");
            scanf("%d",&q->data);
        q->next=NULL;
        tail->next=q;
        tail=q;
        printf("enter 1 to continue and 0 to finish:");
        scanf("%d",&y);
    }
    return temp;
}

int main()
{
    node*head=NULL;
    head=create(head);
    display(head);
    printf("the list after deletion\n");
    head=insertbegin(head);
    display(head);
    head=delend(head);
    display(head);
    return 0;


}