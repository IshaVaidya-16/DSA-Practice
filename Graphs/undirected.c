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
    
    printf("no. of edges:");
    scanf("%d",&e);
    printf("enter edges (u v):");
    for(int i=0;i<e;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a][b]=1;
        adj[b][a]=1;
    }
}

int main()
{
    int graph[100][100],rows,cols;
    adjMatr(graph);
    printf("following is adjacancey matrix:\n");
    printMatrix(graph);
    return 0;
}