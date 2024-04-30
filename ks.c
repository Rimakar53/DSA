#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

void merge(struct Edge* arr,int p,int q,int r){
    int i,j;int id1,id2;
    int n1=q-p+2;//q is the mid and p,r is the starting nad ending index;
    int n2=r-q+1;
    struct Edge l[n1];
    struct Edge ri[n2];
    for( i=0;i<n1-1;i++){
        l[i]=arr[p+i];
    }
    l[i].weight=9999;
    for( j=0;j<n2-1;j++){
        ri[j]=arr[q+j+1];
    }
    ri[j].weight=9999;
     id1=0;
     id2=0;
    for(int k=p;k<=r;k++){
        if(l[id1].weight<ri[id2].weight){
            arr[k]=l[id1];
            id1++;
        }
        else{
            arr[k]=ri[id2];
            id2++;
        }
    }

}

void mergesort(struct Edge*arr,int p,int r){
   if(p<r){
        int q=(p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
   }
}

int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compare(const void* a, const void* b);
void KruskalMST(struct Edge edges[], int V, int E);

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("Enter edges in the format 'source destination weight':\n");
    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    KruskalMST(edges, V, E);

    free(edges);
    return 0;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(struct Edge edges[], int V, int E) {
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    mergesort(edges,0,E-1);

   // qsort(edges, E, sizeof(edges[0]), compare);

    struct Edge* result = (struct Edge*)malloc(V * sizeof(struct Edge));
    int e = 0;  

    int i = 0;

    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the edges of MST
    printf("Edges of the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
    free(result);
}
