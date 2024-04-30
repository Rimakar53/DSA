#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

typedef struct vertex
{
	int name;
	int deg;
	char colour;
	int dist;
	int parent;
	node* adj;
}v;

v* create(int n);
node* insert_begin(node* p, int x);
void display(v* vertex, int n);
void enqueue (int q[], int * rear, int * front, int x, int n);
int dequeue (int q[], int* rear, int* front);
void BFS(v* vertex, int ver, int n);
int print_path(v* vertex, int v);

v* create(int n)
{
	v* vertex= (v*)malloc((sizeof(v))*n);
	int i;
	for(i=0;i<n;i++)
	{
		vertex[i].name=i;
		vertex[i].deg=0;
		vertex[i].colour= 'w';
		vertex[i].dist= 9999;
		vertex[i].parent= -1;	
		vertex[i].adj=NULL;
	}
	return vertex;
}

node* insert_begin(node* p, int x)
{
	node* q=(node *)malloc(sizeof(node));
	q->data=x;
	q->next= NULL;
	if(p==NULL)
		return q;
	else
	{
		q->next=p;
		return q;
	}
}

void display(v* vertex, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("VERTEX %d\n", vertex[i].name);
		printf("DEGREE %d\n", vertex[i].deg);
		printf("COLOUR %c\n", vertex[i].colour);
		printf("DISTANCE %d\n", vertex[i].dist);
		printf("PARENT %d\n", vertex[i].parent);
		printf("ADJACENCY LIST\n");
		node* p = vertex[i].adj;
		while(p)
		{
			printf("%d\t", p->data);
			p=p->next;
		}
		printf("\n");
		printf("PRINTING PATH\n");
		print_path(vertex, i);
	}
}

void enqueue (int q[], int *r, int *f, int x, int n)
{
		if(*r==-1 && *f==-1)
		{
			*f=*f+1;
			*r=*r+1;
			q[*r]=x;
		}	
		else
		{
			*r=*r+1;
			q[*r]=x;
		}	
			
}

int dequeue (int q[], int *f, int *r)
{
		int val= q[*f];
		*f=*f+1;
		return val;		
}

void BFS(v* vertex, int ver, int n)
{
	int f= -1, r=-1, b;
	int q[n],i;
	//for(i=0;i<n;i++)
	//{
		//if(vertex[i].name == ver)
		//{
			vertex[ver].dist=0;
			vertex[ver].colour= 'g';
			vertex[ver].parent= -1;
			enqueue(q, &r, &f, ver, n);
			
		//}
	//}
	printf("BFS TRAVERSAL STARTING FROM VERTEX %d:\n", ver);
	while(f!= -1 && f<=r)
	{
		int a= dequeue (q,&f, &r);
		printf("%d\t", a);
		//printf("DEQUEUE %d Front: %d Rear: %d\n" , a, f, r);
		node *p = vertex[a].adj;
		for(i=0;i<vertex[a].deg;i++)
		{
			b=p->data;
			if(vertex[b].colour == 'w')
			{
				//printf("Enqueuing: %d Front: %d Rear: %d\n", b, f, r);
				vertex[b].dist = vertex[a].dist +1;
				vertex[b].colour = 'g';
				vertex[b].parent = a;
				enqueue(q, &r, &f, b, n);
			}
			p = p->next;
		}
		vertex[a].colour= 'b';
	}
	printf("\n");
}

int print_path(v* vertex, int v)
{
	if(vertex[v].parent== -1)
	{
		printf("%d\n", v);
		return -1;
	}
	else
	{
		print_path(vertex, vertex[v].parent);
		printf("%d\t", v);
	}
	printf("\n");
	return 0;
}											
								
		
int main()
{
	FILE* fp;
	int n, e, i, flag=1, sr, dt, st_vt;
	fp= fopen("edge.txt", "r");
	printf("ENTER NUMBER OF EDGES\n");
	scanf("%d", &e);
	printf("ENTER NUMBER OF VERTICES\n");
	scanf("%d", &n);
	if(fp==NULL)
	{
		printf("ERROR IN OPENING FILE\n");
		return 1;
	}	
	v* graph= create (n);
	for(i=0;i<e;i++)
	{
		fscanf(fp, "%d %d", &sr, &dt);
		graph[sr].name= sr;
		graph[sr].adj=insert_begin(graph[sr].adj, dt);
		graph[sr].deg++;
		graph[dt].name= dt;
		graph[dt].adj=insert_begin(graph[dt].adj, sr);
		graph[dt].deg++;
	}
	display(graph, n);
	printf("ENTER THE STARTING VERTEX\n");
	scanf("%d", &st_vt);
	BFS(graph, st_vt, n);
	display(graph, n);
}