// Online C compiler to run C program online
#include <stdio.h>
int push(int stack[],int n,int top){
    int x;
    if(top==n-1)
        printf("overflow\n");
    else
    {   printf("enter the element:");
        scanf("%d",&x);
        stack[++top]=x;
        return top;
    }
}

void display(int stack[],int top){
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
        printf(" ");
    }
}

int pop(int stack[],int top){
    if(top==-1){
        printf("underflow");
    }
    else{
        top--;
        return top;
    }
}

int main() {
    int top=-1;
    int stack[5];
      top=push(stack,5,top);
      top=push(stack,5,top);
    display(stack,top);
    top=pop(stack,top);
    printf("after pop operation\n");
    display(stack,top);
   

    return 0;
}#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list* next;
}node;

node* push(node* top){
    node* q=(node*)malloc(sizeof(node));
    printf("enter data:");
    scanf("%d",&q->data);
    q->next=NULL;
    if(top==NULL){
        q->next=NULL;
        top=q;
        
    }
    else{
        q->next=top;
        top=q;
        
    }
    return top;
}

void display(node* top){
    while(top){
        printf("%d\n",top->data);
        top=top->next;
    }
}

node* pop(node* p){
        if(p->next==NULL){
            free(p);
            return NULL ;
        }
        else{
            
        
        node* ptr=p;
        p=p->next;
        free(ptr);
        return p;
    }
    
}
    


int main(){
    node* top=NULL;
    top=push(top);
    top=push(top);
    top=push(top);
    display(top);
    top=pop(top);
    printf("after deletion\n");
    display(top);
    return 0;
}