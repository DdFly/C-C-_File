#include<stdio.h>
#define N 5

int main(void){
	int i,j,k,n,l;
	k=0;
	int a[N];
	for (i=0;i<N;i++){
		scanf("%d",&n);
		if(k==0){
			a[0]=n;
			k++;
		}
		else{
			for(j=0;j<k;j++){
				if(n<=a[j]){
					for(l=k;l>j;l--){
						a[l]=a[l-1];
					}
					a[j]=n;
					k++;
					break;
				}
			}
			if(j==k){
				a[j]=n;
				k++;
			}
		}
		for(j=0;j<k;j++){
			printf("%d ",a[j]);		 
		}
		printf("\n");
		
	} 
} 
