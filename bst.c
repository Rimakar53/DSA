#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}node;
node* move(node* p,int x){
    if(p->data>x)
    {
        if(p->left==NULL)
                return p;
        else
           return  move(p->left,x);
    }

    else{
         if(p->right==NULL)
                return p;
        else
           return  move(p->right,x);

    }
}
node* bst(node* p){
    node *q=(node*)malloc(sizeof(node));
    int x;
    printf("enter the data:");
    scanf("%d",&x);
    q->data=x;
    q->left=q->right=NULL;
    if(p==NULL)
            return q;
    else{
        node *temp=p;
        node *parent = move(p,x);
        if(parent->data>x)
            parent->left=q;
        else
            parent->right=q;
        return temp;
    }
}
void inorder(node* p){
    if(p){
        inorder(p->left);
        printf("%d",p->data);
        inorder(p->right);
    }


}

node * min(node *p){
    if(p->left==NULL||p==NULL)
            return NULL;
    else
        min(p->left);
}

node* del(node* p,int x){
    if(p==NULL)
            return NULL;
    else if(p->data>x)
        p->left=del(p->left,x);
    else if(p->data<x)
        p->right=del(p->right,x);
    else{
        if(p->left==NULL){
            node* temp=p->right;
            free(p);
            return temp;
        }

        if(p->right==NULL)
         {       node* temp=p->left;
            free(p);
            return temp;
         }
         else{
            node *temp=min(p->right);
            p->data=temp->data;
            p->right= del(p->right,p->data);
         }
        
    }

     return p;
}



int main()
{
    node *p=NULL;
   p=bst(p);
   inorder(p);
   printf("\n");
   p=bst(p);
   inorder(p);
   p=bst(p);
    inorder(p);
   p= del(p,6);
    inorder(p);
    return 0;
}
