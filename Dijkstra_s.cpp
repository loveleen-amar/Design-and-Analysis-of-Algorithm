#include<bits/stdc++.h>
#include<limits.h>


void paths(int path[],int j)
{
	if (path[j]==-1)
	{
		printf("%d ",j);
		return ;
	}
	
	else
	{
		paths(path,path[j]);
		printf("%d ",j);
	}
	
}

int main()
{
	int n,i,j,k,min=INT_MAX,p,q;
	
	printf("Enter no. of vertices\n");
	scanf("%d",&n);
	
	long long int a[n][n];
	int s[n],v[n],path[n];
	
	printf("Enter adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0&&i!=j)
			{
				a[i][j]=INT_MAX;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		v[i]=0;
		path[i]=0;
		s[i]=a[0][i];
		
	}
	path[0]=-1;
	
	v[0]=1;
		
	for(k=0;k<n-1;k++)
	{
		min=INT_MAX;   //to cal min afte each stage
		for(i=0;i<n;i++)
		{
			if(v[i]==1)
			{
				continue;
			}
			else
			{
				if(min>s[i])
				{
					min=s[i];
					q=i;
				}
			}
			
		}
		
		v[q]=1;
		
		for(i=0;i<n;i++)
		{
			if(v[i]==1)
			{
				continue;
			}
			
			else
			{
				int l=s[i]<=(s[q]+a[q][i])?0:1;
				if(l==1)
				{
					s[i]=s[q]+a[q][i];
					path[i]=q;
				}
			}
		}
		
	}
	
	for(i=0;i<n;i++)
	{
		printf("%lld ",s[i]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("%lld ",path[i]);
	}
	
	printf("\n");
	for(i=0;i<n;i++)
	{
		paths(path,i);
		printf("\n");
		
	}
	
}
/*
0 2 3 0 0
5 0 0 7 4
7 1 0 6 0
0 0 1 0 5
0 0 0 3 0

output 0 2 3 9 6
ab.ac.abd.abe*/
