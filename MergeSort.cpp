#include<stdio.h>

int n,c[50];

merging(int a[],int low,int mid,int high)
{
	int i,j,k,z;
	i=low;
	j=mid+1;
	k=0;
	
	while((i<=mid)&&(j<=high))
	{
		if(a[i]<=a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	
	/*for(z=low;z<high;z++){
		printf("%d ",c[z]);
		a[z]=c[z];
	}*/
	
	for(z=0;z<k;z++)
	{
		a[low+z] = c[z];
	}
	
	
}

mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merging(a,low,mid,high);
	}
		
}


int main(){
	int i;
	printf("enter array size");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter array");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	mergesort(a,0,n-1);
	
	printf("\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
