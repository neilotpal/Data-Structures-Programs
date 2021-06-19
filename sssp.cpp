/* Neilotpal Singh 
   1913029
   Btech CS sec - B 
   BTBTC19091
   Subject - Design and Analysis of Algorithms LAB (CS-213L)
C program to implement the Single source shortest path to print path from source to all other vertices and 
also print the path for a directed graph */
#include<stdio.h>
#include<conio.h>
void printPath(int parent[], int j);
int main()
{
	int i,e,n,C[20][20],j,k,GR[20][20],min,w;
	int v,u,dist[20],s[20],parent[20];
	printf("\nEnter total number of vertices in the graph: ");
	scanf("%d",&n);
	//adjacency_matrix
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			GR[i][j]=0;
	printf("\nEnter total no.of Edges in the graph: ");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
		for(j=1;j<=e;j++)
		{
			if(i==j)
				C[i][j]=0;
			else
				C[i][j]=1000;
		}
	for(k=1;k<=e;k++)
	{
		printf("\nEnter two vertices for edge-%d and its cost: ",k);
		scanf("%d%d",&i,&j);
		GR[i][j]=1; //GR[j][i]=1;
		scanf("%d",&C[i][j]);
	}
	printf("\n The Adjacency Matrix is : ");
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
			printf("%d \t",GR[i][j]);
	}
	printf("\n The Cost Matrix is : ");
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
			printf("%d \t",C[i][j]);
	}
	printf("\n Enter the Source vertex: ");
	scanf("%d",&v);
	for(i=1;i<=n;i++)
	{
		s[i]=0;
		dist[i]=C[v][i];
		parent[0]=-1;
	}
	s[v]=1;
	dist[v]=0;
	u=v;
	for(k=2;k<=n;k++)
	{
		min=1000;
		for(i=1;i<=n;i++)
		{
			if((s[i]!=1) && (dist[i]<min))
			{
				min=dist[i];
				u=i;
			}
		}
		s[u]=1;
		for(w=1;w<=n;w++)
		{
			if(!s[w])
			{
				if(dist[w]>(dist[u]+C[u][w]))
				{
					parent[w] = u;
					dist[w]=dist[u]+C[u][w];
				}
			}
		}
		printf("\n Distance of : %d---->%d is: %d \n Path is :: %d",v,u,dist[u],v);
		printPath(parent, u);
	}
	getch();
	return 0;
}
void printPath(int parent[], int j)
{ 
    if (parent[j] == - 1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d ", j);
}
