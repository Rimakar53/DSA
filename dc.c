#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 100

struct Node
{
    int dest;
    int weight;
    struct Node *next;
};

struct Vertex
{
    int name;
    int distance;
    int parent;
    struct Node *adjList;
} Vertices[size];

void addEdge(struct Vertex vertices[], int src, int dest, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = vertices[src].adjList;
    vertices[src].adjList = newNode;
}

void heap_decrease_key(int priority_queue[], int hash[], int i, int n)
{
    while (i > 0)
    {
        if (Vertices[priority_queue[i]].distance < Vertices[priority_queue[(i - 1) / 2]].distance)
        {
            int temp = priority_queue[i];
            priority_queue[i] = priority_queue[(i - 1) / 2];
            priority_queue[(i - 1) / 2] = temp;

            hash[priority_queue[i]] = i;
            hash[priority_queue[(i - 1) / 2]] = (i - 1) / 2;
        }
        i = (i - 1) / 2;
    }
}

void Min_heapify(int priority_queue[], int hash[], int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && Vertices[priority_queue[left]].distance < Vertices[priority_queue[largest]].distance)
    {
        largest = left;
    }

    if (right < n && Vertices[priority_queue[right]].distance < Vertices[priority_queue[largest]].distance)
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = priority_queue[i];
        priority_queue[i] = priority_queue[largest];
        priority_queue[largest] = temp;

        hash[priority_queue[i]] = i;
        hash[priority_queue[largest]] = largest;

        Min_heapify(priority_queue, hash, largest, n);
    }
}

void Build_priorityQ(int priority_queue[], int hash[], int n)
{
    for (int i = 0; i < n; i++)
    {
        priority_queue[i] = i;
        hash[i] = i;
    }
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Min_heapify(priority_queue, hash, i, n);
    }
}

void Dequeue_priorityQ(int priority_queue[], int hash[], int n)
{
    int x = priority_queue[0];
    int temp = priority_queue[0];
    priority_queue[0] = priority_queue[n - 1];
    priority_queue[n - 1] = temp;
    hash[priority_queue[0]] = 0;
    hash[priority_queue[n - 1]] = n - 1;
    hash[x] = -1; // Marking the dequeued student as removed in the hash
    Min_heapify(priority_queue, hash, 0, n - 1);
    // printf("Dequeued student with roll number %d\n", max_roll);
}

void Enqueue_priorityQ(int priority_queue[], int hash[], int new_roll, int n)
{
    priority_queue[n] = new_roll;
    hash[new_roll] = n;
    heap_decrease_key(priority_queue, hash, n, n + 1);
}

void prims(struct Vertex vertices[], int source, int n)
{
    int priority_queue[n];
    int hash[n];

    for (int i = 0; i < n; i++)
    {  // vertices[i].name=i;
        vertices[i].distance = 9999;
        vertices[i].parent = 9999;
        // vertices[i].adjList = NULL;
    }
    vertices[source].distance = 0;
    vertices[source].parent = -1;

    Build_priorityQ(priority_queue, hash, n);

    while (n > 0)
    {
        int u = priority_queue[0];
        Dequeue_priorityQ(priority_queue, hash, n);
        n--;
           

        struct Node *current = vertices[u].adjList;
        while (current != NULL)
        {
            if(vertices[u].distance == 9999) 
            break;
            int v = current->dest;
            if ( vertices[u].distance+ current->weight < vertices[v].distance)
            {
                vertices[v].distance = current->weight;
                vertices[v].parent = u;
                heap_decrease_key(priority_queue, hash, hash[v], n);
            }
            current = current->next;
        }
    }
}

void path(int i, int source)
{
    if (Vertices[i].parent == -1)
    {
        printf("%d", Vertices[i].name);
        return;
    }
    else if (Vertices[i].parent == 9999)
    {
        return;
    }
    path(Vertices[i].parent, source);
    printf(" -> %d", Vertices[i].name);
}

int main()
{
   /* int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter vertex details (Name):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Vertices[i].name);
        Vertices[i].adjList = NULL;
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);

    printf("Enter edge details (Source Destination Weight):\n");
    for (int i = 0; i < numEdges; i++)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(Vertices, src, dest, weight);
        addEdge(Vertices, dest, src, weight);
    }

    prims(Vertices, source, n);*/

  /*  printf("Shortest Distances from source vertex %s:\n", Vertices[source].name);
    for (int i = 0; i < n; i++)
    {
        printf("%s: %d ", Vertices[i].name, Vertices[i].distance);
        path(i, source);
        printf("\n");
    }
    int wt=0;
    printf("mst edges:\n");
    for(int i=0;i<n;i++){
        if(Vertices[i].parent!=-1){
            printf("%d %d\n",Vertices[i].parent,Vertices[i].name);
            wt+=Vertices[i].distance;
        }
    }
    printf("weight is %d\n",wt);*/

   int n,src,w,des;
   int source;
   printf("enter source;");
   scanf("%d",&source);
   FILE *fp;
   fp=fopen("list.txt","r");
   fscanf(fp,"%d\n",&n);
   for(int i=0;i<n;i++){
            Vertices[i].name=i;
              Vertices[i].adjList=NULL;  
   }
   while(!feof(fp)){
     fscanf(fp,"%d %d %d\n", &src, &des, &w);
        printf("%d %d %d\n",src ,des,w);
        addEdge(Vertices, src, des, w);
        addEdge(Vertices, des, src, w);
   }
   fclose(fp);
  
    prims(Vertices, source, n);
 printf("Shortest Distances from source vertex %d:\n", Vertices[source].name);
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d ", Vertices[i].name, Vertices[i].distance);
        path(i, source);
        printf("\n");
    }
    return 0;

}