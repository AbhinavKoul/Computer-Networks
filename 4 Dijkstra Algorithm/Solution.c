#include <stdio.h>
#define infinity 999
void dijkstra(int n,int source,int cost[10][10],int dist[10],int visited[10])
{
    int i,j,count,min,u,w;

    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i] = cost[source][i];
    }

    count=2;
    while(count<=n)
    {
      min=99;

      for(w=1;w<=n;w++) //FIND MINIMUM 1ST CONNECTED NOTE
        if(!visited[w] && dist[w]<min)
        {
          min=dist[w];
          u = w;
        }  

      visited[u]=1;
      count++;

      for(w=1;w<=n;w++)
        if(!visited[w] && (dist[u]+cost[u][w]<dist[w]))
          dist[w]=dist[u]+cost[u][w];
    }

}

void main()
{
    int i,j,n,visited[10],source,cost[10][10],dist[10];

    printf("enter no of vertices:");
    scanf("%d",&n);

    printf("enter the cost adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
          scanf("%d",&cost[i][j]);

          if(cost[i][j]==0)
            cost[i][j]=infinity;  
        }
            

    printf("\nenter the source node:");
    scanf("%d",&source);

    dijkstra(n,source,cost,dist,visited);

    printf("\n Shortest path:\n");
    for(i=1;i<=n;i++)
        if(i!=source)
            printf("\n %d -> %d, Cost = %d",source,i,dist[i]);
}

