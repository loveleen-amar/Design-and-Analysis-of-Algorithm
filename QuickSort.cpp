#include<stdio.h>

int n;

partition(int a[],int low,int high)
{
	int p,i,j,k,m;
	p=a[low];
	i=low;
	j=high+1;
	
	while(i<=j)
	{
		do{
			i++;
		}while(p>=a[i]);
		
		do{
			j--;
		}while(p<a[j]);
		
		if(i<j)
		{
			k=a[i];
			a[i]=a[j];
			a[j]=k;	
		}
	}
	
	m=a[j];
	a[j]=a[low];
	a[low]=m;
	
	return j;	
}

quicksort(int a[],int low,int high)
{
	int k;
	
	if(low<high)
	{
		k=partition(a,low,high);
		quicksort(a,low,k-1);
		quicksort(a,k+1,high);
	}
}

int main()
{
	int i;
	
		
	printf("enter size");
	scanf("%d",&n);
	int a[n+1];
	printf("enter array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	a[n]=1000000;
	
	quicksort(a,0,n-1);
	
	printf("\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}


