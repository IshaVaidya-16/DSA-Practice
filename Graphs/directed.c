#include<stdio.h>
int v;
void printMatrix(int adj[100][100])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}

void adjMatr(int adj[100][100])
{
    int e,a,b;
    printf("enter number of vertices:");
    scanf("%d",&v);
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            adj[i][j]=0;
        }
    }
    int weight;
    printf("no. of edges:");
    scanf("%d",&e);
    printf("enter edges (u v weight):");
    for(int i=0;i<e;i++)
    {
        scanf("%d %d %d",&a,&b,&weight);
        adj[a][b]=weight;
    }
}

int main()
{
    int graph[100][100],rows,cols;
    adjMatr(graph);
    printf("following is adjacency weighted directed matrix:\n");
    printMatrix(graph);
    return 0;
}