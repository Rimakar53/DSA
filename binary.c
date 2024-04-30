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

void inorder(node* p){
    if(p){
        inorder(p->left);
        printf("%d",p->data);
        inorder(p->right);
    }
}



int main()
{
    node* p=createnode(6);
    node*p1=createnode(8);
    node*p2=createnode(5);
    p->left=p1;
    p->right=p2;
    inorder(p);
    return 0;

}