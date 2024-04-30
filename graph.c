#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list* next;
}node;
typedef struct vertex
{
    int data;
    node* adj;
    char color;
    int d;
    int f;
    int deg;
    char parent;
    
}v;




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
void display(node* p){
 while(p)
    {
        printf("%d",p->data);
        printf(" ");
        p =p->next;
    }
}
typedef struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

void enque(struct queue* q,int val){
    if(q->r==q->size-1)
            printf("the queue is full\n");
    else{
        q->r++;
        q->arr[q->r]=val;
    }
    
}

int deque(struct queue* q){
    int a=-1;
    if(q->f==q->r)
        printf("the queue is empty\n");
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}




int main()
{
    int n=10;
    v* vx=(v*)malloc(n*sizeof(v));
    int i;
    for(i=0;i<n;i++){
        vx[i].data=0;
        vx[i].adj=NULL;
        vx[i].color='w';
        vx[i].parent='*';
        vx[i].deg=0;
        vx[i].d=9999;
        vx[i].d=1000;
    }
    int src,des;
    for (int i=0;i<3;i++){
        printf("enter the edge information:");
        scanf("%d%d",&src,&des);
        vx[src].adj=insertbegin(vx[src].adj,des);
        vx[des].adj=insertbegin(vx[des].adj,src);
        vx[src].deg++;
        vx[des].deg++;
    }
  insert_begininsert_begin
    dfs(vx,3);
    printf("after insertion\n");
     for(int x=0;x<3;x++){
        printf("the information:\n");
        printf("%d\n",vx[x].data);
        printf("%d\n",vx[x].d);
        printf("%c\n",vx[x].parent);
        printf("%c\n",vx[x].color);
        printf("%d\n",vx[x].deg);
        printf("the adj list\n");
        display(vx[x].adj);
        printf("\n");
    }
  
    return 0;
}
/*

void bfs (v* vx , int s,int n,struct queue* q)
{ 
    for (int i=0;i<n;i++){
        vx[i].d=9999;
        vx[i].color='w';
        vx[i].parent='*';
    }
    vx[s].d=0;
    vx[s].color='g';
    vx[s].parent='*';
    enqueue(q,s);
    while(q->f!=q->r)
    {
      int  x=dequeue(q);
        for(int i=0;i<n;i++){
           node* temp=vx[i].adj;
             while(temp!=NULL)
             {  
                if()
             }

            }
            
        }

    }*/

    void dfs(v* vx,int n){
        int i;
        for(i=0;i<n;i++){
            vx[i].color='w';
            vx[i].parent='999';
        }
        int time=0;
        for(int i=0;i<n;i++){
            if(vx[i].color=='w'){
               v vt=vx[i];
                dfsvisit(vt,vx,time);
            }
        }


    }

    void dfsvisit(v vx,v* vt,int time)
    {
        time++;
        vx.color='g';
        vx.d=time;
        node* temp=vx.adj;
        while(temp!=NULL)
        {   int j=temp->data;
            if(vt[j].color=='w'){
                    vt[j].parent=vx.data;
                    dfsvisit(vt[j], vt);
            }
            temp=temp->next;
        }
        vx.color='b';
        time++;
        vx.f=time;
    }
        

    



    
    
   




