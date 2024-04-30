
#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list* next;
    struct list* pre;
}node;

node* insertionbeg(node* p)
 {   node* q=(node*)malloc(sizeof(node));
    printf("enter the element\n");
    scanf("%d",&q->data);
    q->next=q->pre=NULL;
    if(p==NULL)
        return q;
    else{
        q->next=p;
        p->pre=q;
        return q;
    }
}

node* insertionend(node*p){
    node* q=(node*)malloc(sizeof(node));
    printf("enter the element\n");
    scanf("%d",&q->data);
    q->next=q->pre=NULL;
    if(p==NULL)
        return q;
    else
    {  node*temp=p;
        while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    q->pre=p;
    return temp;
    }

}

node* insertionmid(node* p,int y){
    node* q=(node*)malloc(sizeof(node));
    printf("enter the element\n");
    scanf("%d",&q->data);
    q->next=q->pre=NULL;
    if(p==NULL)
        return q;
    else
     {   node* temp=p;
        while(p){
            if(p->data==y)
                break;
            p=p->next;
        }
        q->next=p->next;
        p->next->pre=q;
        p->next=q;
        q->pre=p;
        return temp;
     }


}

void display(node* p){
    while(p){
        printf("%d\n",p->data);
        p=p->next;
    }
}

node* delbeg(node* p){
    if(p==NULL)
    {   printf("empty list\n");
        return NULL;
    }
    else{
        if(p->next==NULL){
            printf("empty list\n");
            free(p);
            return NULL;
        }
        else{
            node* temp =p;
            p=p->next;
            p->pre=NULL;
            free(temp);
            return p;
        }
    }
}

node* delend(node* p){
      if(p==NULL)
    {   printf("empty list\n");
        return NULL;
    }
    else{
        if(p->next==NULL){
            printf("empty list\n");
            free(p);
            return NULL;
        }
        else{
            node* temp=p;
            while(p->next!=NULL){
                p=p->next;
            }
            node* del=p;
            p->pre->next=NULL;
            free(del);
            return temp;
        }
    
}
}


int main()
{
    node* head=NULL;
    head=insertionbeg(head);
     head=insertionbeg(head);
     head=insertionend(head);
     head=insertionmid(head,8);
     head=delend(head);
    display(head);
    return 0;
}