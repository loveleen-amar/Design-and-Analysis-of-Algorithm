#include<bits/stdc++.h>
#include<limits.h>



int main()
{
	int n,i,j,k,min=INT_MAX,p,q;
	
	printf("Enter no. of vertices\n");
	scanf("%d",&n);
	
	int a[n][n],s[n];
	
	printf("Enter adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
				a[i][j]=INT_MAX;
			if(a[i][j]<min)
			{
				min=a[i][j];
				p=i;
				q=j;
			}
		}
	}
	
	for(i=0;i<n;i++)	//Intialising visited vertex as 0
	{
		s[i]=0;
	}
	
	s[p]=1;
	s[q]=1;
	
	printf("%c %c\n",'A'+p,'A'+q);
	
	for(k=0;k<n-2;k++)
	{
		min=INT_MAX;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(s[i]==1&&s[j]==0)
				{
					if(min>a[i][j])
					{
						min=a[i][j];
						p=i;q=j;
					}
				}
			}
		}
		
		printf("%c %c\n",'A'+p,'A'+q);
		 
		s[p]=1;
		s[q]=1;
		
	}
	
}


/*
0 10 0 30 45 0
10 0 50 0 40 25
0 50 0 0 35 15
30 0 0 0 0 20
45 40 35 0 0 35
0 0 15 20 35 0

ab.bf,fc,fd,ce
*/
