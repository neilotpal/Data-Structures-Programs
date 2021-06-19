#include<stdio.h>
void minheapify(int i);
void createminheap();
void kruskals();

int edge[10],g[10][10],n,e,p[10];
//main function
int main()
{
	int i,j,ch,v1,v2,w;
	printf("\nEnter the number of vertices in the graph: ");
	scanf("%d",&n);
	printf("Graph is 1.directed 2.undirected\nEnter your choice");
	scanf("%d",&ch);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	g[i][j]=999;

	switch(ch)
	{
		case 1: printf("\nEnter the number of edges in the directed graph\n");
				scanf("%d",&e);
				printf("\nEnter the pair of vertices having edge b/w them and their cost: \n");
				for(i=1;i<=e;i++)
				{
					scanf("%d%d%d",&v1,&v2,&w);
					g[v1][v2]=w;
					edge[i]=w;
				}
				break;
		case 2: printf("\nEnter the number of edges in the undirected graph\n");
				scanf("%d",&e);
				printf("\nEnter the pair of vertices having edge b/w them and their cost: \n");
				for(i=1;i<=e;i++)
				{
					scanf("%d%d%d",&v1,&v2,&w);
					g[v1][v2]=w;
					g[v2][v1]=w;
					edge[i]=w;
				}
				break;
		default:printf("\nEnter the correct choice");
	}

	printf("\nMatrix representation\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",g[i][j]);
		}
		printf("\n");
	}
	kruskals();
	return 0;
}
//find function to find the set that contain the element x
int find(int x)
{
	int r=x;
	while(p[r]>0)
	{
		r=p[r];
	}
	return r;
}
//dunion function to find the union of two sets whose roots are j and k
void dunion(int j,int k)
{
	p[j]=k;
}
//delete a mincost edge from the min heap
int mindelete()
{
	int x;
	x=edge[1];
	edge[1]=edge[e];
	e--;
	minheapify(1);
	return x;
}
//kruskal function for MST

void kruskals()
{
	int i=1,t[10][2],j,x,q,w,v1,v2,costmst=0,s,r;
//create min heap
	createminheap();

	printf("\narray after min heap: \n");
	printf("\n");
	for(i=1;i<=n;i++)
		p[i]=-1;
	i=0;
	while(i<n-1 && e>0)
	{
		x=mindelete(); //delete a mincost edge
//find the end vertices of mincost edge from matrix
		for(q=1;q<=n;q++)
		{
		   for(w=1;w<=n;w++)
		  {
			 if(g[q][w]==x)
			 {
				v1=q;
				v2=w;
			 }
		   }
	    }	
	    s=find(v1);
	    r=find(v2);
	    if(s!=r)
	    {
			i++;
			t[i][1]=v1;
			t[i][2]=v2;
			dunion(v1,v2);
			costmst+=g[v1][v2];
	    }
    }
	if(i<n-1)
		printf("\nNo minimum spanning tree");
	else
	{
		printf("\nThe spanning tree edges and cost are: \n");
		for(i=1;i<=n-1;i++)
		{
			printf("edge(%d, %d) cost=%d",t[i][1],t[i][2],g[t[i][1]][t[i][2]]);
			printf("\n");
		}
		printf("\n Cost of MST =%d",costmst);
	}
}
void createminheap()
{
	int i;
	for(i=e/2;i>=1;i--)
		minheapify(i);
}
void minheapify(int i)
{
   int small=i,l,r,temp;
   l=2*i;
   r=2*i+1;
   if(l<=e && (edge[l]<edge[small]))
	 small=l;
   if(r<=e && (edge[r]<edge[small]))
	 small=r;
   if(i!=small)
   {
		temp=edge[i];
		edge[i]=edge[small];
		edge[small]=temp;
		minheapify(small);
   }
}

