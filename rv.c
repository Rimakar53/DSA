#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list* next;
}node;

node * create(node* p){
    int y=1,x;
    node* temp,*tail;
        node* q=(node*)malloc(sizeof(node));
            printf("enter data:");
            scanf("%d",&x);
            q->data=x;
            q->next=NULL;
    if(p==NULL)
       { temp=tail=q;
       }
       
    
        while(y)
        {      
            node* q=(node*)malloc(sizeof(node));
            printf("enter data:");
            scanf("%d",&x);
            q->data=x;
            q->next=NULL;
            tail->next=q;
            tail=q;
             printf("enter 1 to continue and 0 to exit");
                scanf("%d",&y);
           
            
        }
    
    return temp;
}
void display(node *p){
    while(p){
        printf("%d",p->data);
        printf(" ");
        p=p->next;
    }
}

node* reverse(node *p){
    node * q=NULL;
    node *temp;
    while(p){
        temp=q;
        q=p;
        p=p->next;
        q->next=temp;
    }
    return q;
}

int main()
{
    node* head=NULL;
    head=create(head);
    display(head);
    head=reverse(head);
    display(head);
    return 0;
}