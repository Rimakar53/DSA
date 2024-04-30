// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
int f=-1;
int r=-1;
int q[20];
int c=0;

typedef struct list{
    int data;
    struct list *next;
}node;

typedef struct vertex{
    int name;
    int deg;
    char color;
    node *adj;
    int parent;
    int d;
}v;
void enqueue(int q[],int n,int *f,int *r,int x,int *c){
    if(*c==n)
        printf("overflow");
    else
    {   if(*r==-1&&*f==-1){
            *r=*f=0;
            *c=*c+1;
            q[*r]=x;
        }
        else
        {   *c=*c+1;
            *r=(*r+1)%n;
            q[*r]=x;
        }
    }
        
    
}

int dequeue(int q[],int *r,int *f,int n,int *c)
{   if(*c==0)
        printf("underflow\n");
    else{
       int i=q[*f];
        *f=(*f+1)%n;
        *c=*c-1;
        return i;
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
node* insertbegin(node* p,int y)
{
    node*q=(node*)malloc(sizeof(node));
    q->data=y;
    q->next=NULL;
    if(p==NULL)
        return q;
    else
     {   q->next=p;
        return q;
     }

}
void print(v *vx,int n){
     for(int x=0;x<n;x++){
        printf("the information:\n");
        printf("%d\n",vx[x].name);
        printf("%d\n",vx[x].d);
        printf("%d\n",vx[x].parent);
        printf("%c\n",vx[x].color);
        printf("%d\n",vx[x].deg);
        printf("the adj list\n");
        display(vx[x].adj);
        printf("\n");
    }
}
int empty(int q[],int *c){
    if(*c==0)
        return 0;
    else
        return 1;
}

void bfs(v *vx,int n,int s){
    vx[s].d=0;
    vx[s].color='g';
    vx[s].parent=111;
    enqueue(q,20,&f,&r,s,&c);
    while(empty(q,&c)){
      int  i=dequeue(q,&r,&f,20,&c);
        printf("%d",i);
       
            node* temp=vx[i].adj;
            while(temp!=NULL){
                int j=temp->data;
                if(vx[j].color=='w'){
                    vx[j].d=vx[i].d+1;
                    vx[j].parent=vx[i].name;
                    vx[j].color='g';
                    enqueue(q,20,&f,&r,j,&c);
                    
                    
                }
                temp=temp->next;
            }
            vx[i].color='b';
        }
    }


int main()
{
   int n;int y=1;
   printf("enter the number of vertex:");
   scanf("%d",&n);
    v* vx=(v*)malloc(n*sizeof(v));
    int i;
    for(i=0;i<n;i++){
        vx[i].name=0;
        vx[i].adj=NULL;
        vx[i].color='w';
        vx[i].parent=1111;
        vx[i].deg=0;
        vx[i].d=9999;
        vx[i].d=1000;
    }
    int src,des;
    while(y){
        for (int i=0;i<n;i++){
             printf("enter the edge information:");
                scanf("%d%d",&src,&des);
            vx[src].name=src;
            vx[des].name=des;
            vx[src].adj=insertbegin(vx[src].adj,des);
            vx[des].adj=insertbegin(vx[des].adj,src);
            vx[src].deg++;
            vx[des].deg++;
            printf("enter 1 to continue and 0 to exit:");
            scanf("%d",&y);
        }
    }
    print(vx,n);
    printf("the tavarsal\n");
    bfs(vx,n,1);
    return 0;
}