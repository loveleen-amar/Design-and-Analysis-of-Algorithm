#include<stdio.h>


int main(){
	
	int i,n,key,l,z=1,h,mid;
	
	printf("Enter size");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	printf("Enter element to be searched");
	scanf("%d",&key);
	
	
	l=0;
	h=n;
	
	while(l<=h)
	{
		mid = (l+h)/2;
		if(a[mid]==key)
			{
			printf("Found at %d",mid);
			z=100;
			break;
			}
			
		else if(a[mid]>key)
			h=mid-1;
			
		else if(a[mid]<key)
			l=mid+1;
		
	}
	
	if(z==1)
		printf("Not found");
	
}
