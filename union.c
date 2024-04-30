#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int parent;
    int rank;
}g;

void makeset(g* v,int x){
    v[x].parent=x;
    v[x].rank=0;
}

int findset(g v[],int x){
    if(v[x].parent != x){
        v[x].parent=findset(v,v[x].parent);
    }
    return v[x].parent;
}

void link(g *v,int x,int y){
    if(v[x].rank > v[y].rank)
        v[y].parent=x;
    else if(v[x].rank < v[y].rank)
        v[x].rank=y;
    else
    {
        v[x].parent=y;
        v[y].rank++;
    }
}

void unions(g *v,int x,int y){
    if(findset(v,x)!= findset(v,y))
        link(v,x,y);
}

int main()
{   g v[5];
    int n=5;
    for(int i=1;i<=n;i++){
        makeset(v,i);
    }
    unions(v,1,2);
    unions(v,3,4);
    unions(v,1,3);
    printf("%d",v[1].rank);
    return 0;
}