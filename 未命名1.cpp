#include<stdio.h>
int main(void){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(n%i!=0)
			printf("*");
		if (n>=2*i+1)
			k=2*(i-1)-1;
		else
			k=2*(n-i)-1; 
		for(;k>0;k--){
			printf("+");
		}
		printf("*\n");
	}

	return 0;
} 
