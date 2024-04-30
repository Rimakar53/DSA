// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list *next;
}node;

typedef struct vertex{
    int name;
    int deg;
    node *adj;
    char color;
    int parent;
    int d;
    int f;
}v;
node* insert_begin(node*p,int x){
    node*q=(node*)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(p==NULL){
        return q;
    }
    else{
        q->next=p;
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

int main() {
   int n,i,src,des,y=1;
   printf("enter the number of vertices:");
   scanf("%d",&n);
   v *vtx=(v*)malloc(sizeof(v)*n);
   for(i=0;i<n;i++){
       vtx[i].name=0;
       vtx[i].deg=0;
       vtx[i].color='w';
       vtx[i].parent=1111;
       vtx[i].d=0;
       vtx[i].f=0;
       vtx[i].adj=NULL;
   }
   while(y){
       printf("enter the edge information:");
       scanf("%d%d",&src,&des);
       vtx[src].name=src;
       vtx[src].adj=insert_begin(vtx[src].adj,des);
       vtx[src].deg++;
       vtx[des].name=des;
        printf("enter 1 to continue and 0 to exit:");
        scanf("%d",&y);
   }
     printf("before insertion\n");
     for(int x=0;x<n;x++){
        printf("the information:\n");
        printf("%d\n",vtx[x].name);
        printf("%d\n",vtx[x].d);
        printf("%d\n",vtx[x].parent);
        printf("%c\n",vtx[x].color);
        printf("%d\n",vtx[x].deg);
        printf("%d\n",vtx[x].f);
        printf("the adj list\n");
        display(vtx[x].adj);
        printf("\n");
    }
   
   
   

    return 0;
}