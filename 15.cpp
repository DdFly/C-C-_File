#include<stdio.h>
int main(void){
	int i,n;
	for(i=0;i<10;i++){
		n=5*10+i;
		if(n%3==0)
			printf("%4d",n);
	}
	for(i=1;i<10;i++){
		n=i*10+5;
		if(n%3==0)
			printf("%4d",n);	
	}
	printf("\n");
	return 0;
}
