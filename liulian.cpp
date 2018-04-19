#include<stdio.h>
int main(void){
	int i,j,n;
	scanf("%d",&n);
	printf("*\n");
	for(i=1;i<n/2;i++){
		printf("*");
		for(j=1;j<=2*i-1;j++){
			printf("+");
		}
		printf("*\n");
		
	}
	for(i=n/2;i>0;i--){
		printf("*");
		for(j=1;j<=2*i-1;j++){
			printf("+");
		}
		printf("*\n");
	}
	printf("*\n");
	return 0;
} 
