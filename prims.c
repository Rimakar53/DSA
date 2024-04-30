#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
	int data;
	int w;
	struct node* next;
}node;

typedef struct vertex
{
	int u;
	int key;
	int p;
	node* adj;
}v;


node* insert_begin(node* head, int V, int W);
void min_heapify(int *a, int *h, int i, int n, v* graph);
void Build_priorityQ(int* a, int* h, int n, v* graph);
void heap_decrease_key(int* a, int* h, int i, int n, v* graph);
void Dequeue_priorityQ(int* a, int* h, int* nptr, v* graph);
void initialize_single_source_shortest_Path(int s, v* graph, int n);
void prims(int s, int n, v* graph);
void relax(int u, int a, int h, int n, node* p, v* graph);

void min_heapify(int* a, int* h, int i, int n, v* graph)
{
	int l, r, min, temp;
	l=2*i+1;
	r=2*i+2;
	if(l<n && graph[a[l]].key<graph[a[i]].key)
		min = l;
	else
		min = i;
	if(r<n && graph[a[r]].key<graph[a[min]].key)
		min = r;
	if(min!=i)
	{
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
		h[a[min]] = min;
		h[a[i]] = i;
		min_heapify(a,h,min,n,graph);
	}
}			
	
void Build_priorityQ(int* a, int* h, int n, v* graph)
{
	int i;
	for(i=((n-2)/2);i>=0;i--)
		min_heapify(a,h,i,n,graph);
}

void heap_decrease_key(int* a, int* h, int i, int n, v* graph)
{
	int temp;
	while(i>0 && graph[a[(i-1)/2]].key>graph[a[i]].key)
	{
		temp = a[(i-1)/2];
		a[(i-1)/2] = a[i];
		a[i] = temp;
		h[a[(i-1)/2]] = (i-1)/2;
		h[a[i]] = i;
		i = (i-1)/2;
	}			
}

void Dequeue_priorityQ(int *a, int *h, int* nptr, v* graph)
{
	int n = *nptr;
	h[a[0]] = -1;
	a[0] = a[n-1];
	h[a[0]] = 0;
	*nptr = *nptr - 1;
	min_heapify(a,h,0,*nptr,graph);
}

void initialize_single_source_shortest_Path(int s, v* graph, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		graph[i].u=i;
		graph[i].key=INT_MAX;
		graph[i].p=INT_MAX;
	}
	graph[s].key=0;
	graph[s].p=-1;
}

void prims(int s, int n, v* graph)
{
	int i, prQ[n], hash[n], u, v, j;
	for(i=0;i<n;i++)
	{
		prQ[i] = i;
		hash[i] = i;
	}
	node* p;
	initialize_single_source_shortest_Path(s, graph, n);
	Build_priorityQ(prQ, hash, n, graph);
	while(n>0)
	{
		u=prQ[0];
		Dequeue_priorityQ(prQ, hash, &n, graph);
		if(graph[u].key!=INT_MAX)
		{
			p=graph[u].adj;
			while(p!=NULL)
			{
				v=p->data;
				for(j=0;j<n;j++)
				{
					if(prQ[j]==v && ((p->w)<graph[v].key))
					{
						graph[v].p = u;
						graph[v].key = p->w;
						//printf("%d	%d->", v , u);
						heap_decrease_key(prQ,hash,hash[v],n,graph);
						break;
					}
				}
				p=p->next;
			}
		}
	}
}

int main()
{
	FILE* f1;
	int n,s,i,u,dest,w, weight;
	f1 = fopen("graph.txt", "r");
	if(f1 == NULL)
	{
		printf("ERROR!");
		return 1;
	}
	printf("ENTER SOURCE VERTEX\n");
	scanf("%d", &s);
	fscanf(f1, "%d\n", &n);
	v graph[n];
	for(i=0;i<n;i++)
		graph[i].adj = NULL;
	while(!feof(f1))
	{
		fscanf(f1, "%d %d %d\n", &u, &dest, &w);
		graph[u].adj=insert_begin(graph[u].adj, dest, w);
		graph[dest].adj=insert_begin(graph[dest].adj, u, w);
	}
	/*for(i=0;i<n;i++)
	{
		node* head = graph[i].adj;
		printf("%d\t", i);
		while(head)
		{
			printf("\t%d %d\t", head->data, head->w);
			head = head->next;
		}
		printf("\n");
	}*/
	fclose(f1);
	prims(s,n,graph);
	printf("EDGES IS THE MST ARE:\n");
	for(i=0;i<n;i++)
	{
		if(graph[i].p != -1)
		{
		    printf("%d	%d\n", graph[i].p, graph[i].u);
		    weight += graph[i].key;
		} 
	}
	printf("THE WEIGHT OF THE MST IS %d\n", weight);
	return 0;
}

node* insert_begin(node* head, int V, int W)
{
	node* new = (node *)malloc(sizeof(node));
	new->data = V;
	new->w = W;
	new->next = NULL;
	if(head == NULL)
		return new;
	else
	{
		new->next = head;
		return new;
	}
}