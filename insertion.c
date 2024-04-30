#include<stdio.h>
#include<stdlib.h>
typedef struct ls{
    int data;
    struct ls* left;
    struct ls* right;
}node;

node* createnode(int y){
    node* p=(node*)malloc(sizeof(node));
    p->data=y;
    p->left=p->right=NULL;
    return p;
}

void insert(node* p,int y){
    node* pre=NULL;
    while(p!=NULL){
        pre=p;
         if(p->data==y)
            return ;
        else if(y<p->data)
            p=p->left;
        else
            p=p->right;
    }
    node* q=createnode(y);
    if(pre->data>y)
        pre->left=q;
    else
        pre->right=q;


}
int main()
{
    node* p=createnode(6);
    node*p1=createnode(4);
    node*p2=createnode(8);
    p->left=p1;
    p->right=p2;
    insert(p,2);
    printf("%d",p->left->left->data);
    return 0;
}