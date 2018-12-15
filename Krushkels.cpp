#include<stdio.h>
#include<limits.h>
int main()
{
	long long int n,i,j,k,min=INT_MAX,p,q;
	
	printf("Enter no. of vertices\n");
	scanf("%d",&n);
	
	long long int a[n][n],s[n],v[n];
	
	printf("Enter adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0)
			{
				a[i][j]=INT_MAX;
			}
			if(a[i][j]<min)
			{
				min=a[i][j];
				p=i;
				q=j;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		s[i]=i;
		v[i]=0;
	}
	
	s[q]=s[p];
	v[q]=v[p]=1;
	printf("%c %c\n",'A'+p,'A'+q);
	for(k=0;k<n-2;k++)
	{
		min=INT_MAX;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(min>a[i][j]&&s[i]!=s[j])
				{
					min=a[i][j];
					p=i;q=j;
				}
				
			}
		}
		
		printf("%d \n",min);
		
		printf("%c %c\n",'A'+p,'A'+q);
		int ss;
		for(ss=0;ss<n;ss++){
			if(s[ss]==s[q])
				s[ss]=s[p];	
		}
		
		v[q]=1;v[p]=1;
		
		
	}
	
	
}

/*
0 10 0 30 45 0
10 0 50 0 40 25
0 50 0 0 35 15
30 0 0 0 0 20
45 40 35 0 0 35
0 0 15 20 35 0
*/
