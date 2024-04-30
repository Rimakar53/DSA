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

void heap_decrease_key(int priority_queue[], int hash[], int prQ_indx, int n)
{
    while (prQ_indx > 0)
    {
        if (Vertices[priority_queue[prQ_indx]].distance < Vertices[priority_queue[(prQ_indx - 1) / 2]].distance)
        {
            int temp = priority_queue[prQ_indx];
            priority_queue[prQ_indx] = priority_queue[(prQ_indx - 1) / 2];
            priority_queue[(prQ_indx - 1) / 2] = temp;

            hash[priority_queue[prQ_indx]] = prQ_indx;
            hash[priority_queue[(prQ_indx - 1) / 2]] = (prQ_indx - 1) / 2;
        }
        prQ_indx = (prQ_indx - 1) / 2;
    }
}

void Min_heapify(int priority_queue[], int hash[], int prQ_indx, int n)
{
    int left = 2 * prQ_indx + 1;
    int right = 2 * prQ_indx + 2;
    int largest = prQ_indx;

    if (left < n && Vertices[priority_queue[left]].distance < Vertices[priority_queue[largest]].distance)
    {
        largest = left;
    }

    if (right < n && Vertices[priority_queue[right]].distance < Vertices[priority_queue[largest]].distance)
    {
        largest = right;
    }

    if (largest != prQ_indx)
    {
        int temp = priority_queue[prQ_indx];
        priority_queue[prQ_indx] = priority_queue[largest];
        priority_queue[largest] = temp;

        hash[priority_queue[prQ_indx]] = prQ_indx;
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
    int max_roll = priority_queue[0];
    int temp = priority_queue[0];
    priority_queue[0] = priority_queue[n - 1];
    priority_queue[n - 1] = temp;
    hash[priority_queue[0]] = 0;
    hash[priority_queue[n - 1]] = n - 1;
    hash[max_roll] = -1; // Marking the dequeued student as removed in the hash
    Min_heapify(priority_queue, hash, 0, n - 1);
    // printf("Dequeued student with roll number %d\n", max_roll);
}

void Enqueue_priorityQ(int priority_queue[], int hash[], int new_roll, int n)
{
    priority_queue[n] = new_roll;
    hash[new_roll] = n;
    heap_decrease_key(priority_queue, hash, n, n + 1);
}

void Dijkstra(struct Vertex vertices[], int source, int n)
{
    int priority_queue[n];
    int hash[n];

    for (int i = 0; i < n; i++)
    {
        vertices[i].distance = INT_MAX;
        vertices[i].parent = INT_MAX;
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
            if(vertices[u].distance == INT_MAX) break;
            int v = current->dest;
            int alt_distance = vertices[u].distance + current->weight;
            if (alt_distance < vertices[v].distance)
            {
                vertices[v].distance = alt_distance;
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
    else if (Vertices[i].parent == INT_MAX)
    {
        return;
    }
    path(Vertices[i].parent, source);
    printf(" -> %d", Vertices[i].name);
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
   // printf("Enter vertex details (Name):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Vertices[i].name);
        Vertices[i].adjList = NULL;
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("%d",source);

   /* printf("Enter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);

    printf("Enter edge details (Source Destination Weight):\n");
    for (int i = 0; i < numEdges; i++)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(Vertices, src, dest, weight);
    }*/
    int src,des,w;
     FILE*  fp=fopen("list.txt","r");
   while(!feof(fp)){
     fscanf(fp,"%d %d %d\n", &src, &des, &w);
       // printf("%d %d %d\n",src ,des,w);
        addEdge(Vertices, src, des, w);
       // addEdge(Vertices, des, src, w);
   }
   fclose(fp);

    Dijkstra(Vertices, source, n);

    printf("Shortest Distances from source vertex %d:\n", Vertices[source].name);
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d ", Vertices[i].name, Vertices[i].distance);
        path(i, source);
        printf("\n");
    }

    return 0;
}