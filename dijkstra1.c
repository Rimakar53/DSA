#include<stdio.h>
#include<stdlib.h>

typedef struct nodes{
    int data;
    int wt;
    struct nodes *next;
}node;

typedef struct vertex{
    int d;
    int dist;
    int p;
    node *adj;
}v;

node* insertbeg(node *p,int x,int w){
    node *q=(node*)malloc(sizeof(node));
    q->data=x;
    q->wt=w;
    q->next=NULL;
    if(p==NULL)
        return q;
    q->next=p;
    return q;
}

void swap(int *pq,int *hash,int u,int v){
    int temp=hash[v];
    hash[v]=hash[u];
    hash[u]=temp;
    temp=pq[v];
    pq[v]=pq[u];
    pq[u]=temp;
}

void initial(v* vt,int *pq,int *hash,int n,int s){
    for(int i=0;i<n;i++){
        pq[i]=i;
        hash[i]=i;
        vt[i].adj=NULL;
        vt[i].d=0;
    
    if(i==s){
        vt[i].p=-1;
        vt[i].dist=0;
    }
    else{
        vt[i].p=-2;
        vt[i].dist=9999;
    }
}
}

void minheapify(v *vt,int *pq,int *hash,int i,int n){
  int  small=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && vt[pq[left]].dist<vt[pq[small]].dist){
        small=left;
    }
    if(right<n && vt[pq[right]].dist<vt[pq[small]].dist){
        small=right;
    }
    if(small!=i){
        swap(pq,hash,i,small);
        minheapify(vt,pq,hash,small,n);
    }
}

void upheapify(int x,int *pq,v *vt,int *hash){
    if(x!=0){
        int p=(x-1)/2;
        int a=vt[pq[p]].dist;
        int b=vt[pq[x]].dist;
        if(b<a){
            swap(pq,hash,x,p);
            upheapify(p,pq,vt,hash);
        }
    }
}

void buildheapify(int *pq,v* vt,int *hash,int size){
    int i;
    for(i=size/2-1;i>=0;i--)
    {
        minheapify(vt,pq,hash,i,size);
    }
}

int dequeue(v *vt,int *pq,int *hash,int *size){
    int min=pq[0];
    pq[0]=pq[*size-1];
    hash[pq[0]]=0;
    *size--;
    minheapify(vt,pq,hash,0,*size);
    return min;
}

void relax(v *vt,int u,int V,int wt,int *pq,int *hash ){
    if(vt[V].dist>vt[u].dist+wt){
        vt[V].dist=vt[u].dist+wt;
        vt[V].p=u;
        upheapify(V,pq,vt,hash);
    }
}

void dijkstra(v *vt,int *pq,int *hash,int size){
    while(size!=0){
        int c=dequeue(vt,pq,hash,&size);
        node *p=vt[c].adj;
        vt[c].d=1;

        while(p!=NULL){
            relax(vt,c,p->data,p->wt,pq,hash);
            p=p->next;
            }
        }
    }

void path(v *vt,int x,int s){
    if(vt[x].p== -1)
        printf("%d",x);
    else if(vt[x].p==9999)
        return;
    else{
        path(vt,vt[x].p,s);
        printf("->%d",x);
    }
}

int main(){
    FILE *fp=fopen("list.txt","r");
    int i, u,j,weight,n,s,dest,w;
    printf("ENTER SOURCE VERTEX\n");
	scanf("%d", &s);
	fscanf(fp, "%d\n", &n);
    int* pq=(int*)malloc(n*sizeof(int));
     int* hash=(int*)malloc(n*sizeof(int));
	v graph[n];
	//for(i=0;i<n;i++)
	//	graph[i].adj = NULL;
	while(!feof(fp))
	{
		fscanf(fp, "%d %d %d\n", &u, &dest, &w);
		graph[u].adj =insertbeg(graph[u].adj, dest, w);
		//graph[dest].adj=insert_begin(graph[dest].adj, u, w);
	}
    buildheapify(pq,graph,hash,n);
    dijkstra(graph,pq,hash,n);
    for(i=0;i<n;i++){
        printf("-----path---\n");
        path(graph,i,s);
        printf("weight\n",graph[i].dist);
    }
    return 0;
}