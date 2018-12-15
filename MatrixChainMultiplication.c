#include<stdio.h>
int main(){
	int n,i,j,k,g;
	printf("Enter no. of matrices");
	scanf("%d",&n);
	int p[50];
	printf("Enter dimensions");
	for(i=1;i<=n+1;i++){
		scanf("%d",&p[i]);
	}
	int M[n][n];
	int K[n][n];
	int C[n][n];
	
	for(i=1;i<=n;i++){
		for( j=1;j<=n;j++){
			K[i][j]=0;			//k=0 initialize sbme

		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			M[i][j]=1000000;		//m[][] me big value initialize sbme

		}
	}
	
	for(g=0;g<n;g++){
		for(i=1;i<=n;i++){
			j=i+g;
			if(i==j){
				M[i][j]=0;
			}
			else{
				int min_cost=1000000;
				for (k=i;k<=j-1;k++){				//loop to cal min for diff values of k
					if(M[i][k]+M[k+1][j]+p[i]*p[k+1]*p[j+1]<min_cost){
						min_cost=M[i][k]+M[k+1][j]+p[i]*p[k+1]*p[j+1];
						K[i][j]=k;
					}
				}
			M[i][j]=min_cost;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",K[i][j]);
		}
		printf("\n");
	}
	printf("Minimum no. of scalar multiplication is  %d",M[1][n]);	
		
		
}


/*
Enter no. of matrices4
Enter dimensions5 4 6 2 7
0       120     88      158
1000000 0       48      104
1000000 1000000 0       84
1000000 0       1000000 0

0       1       1       3
0       0       2       3
0       0       0       3
0       3       0       0
Minimum no. of scalar multiplication is  158*/

