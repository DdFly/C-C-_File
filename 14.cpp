#include<stdio.h>
double fun(int n){
	int i,sum=0,mul=1;
	for(i=1;i<=2*n;i++){
		if(i%2)
			mul*=i;
		else
			sum+=i;
	}
	return mul*1.0/sum;
}

int main(void){
	int x,n;
	printf("ÇëÊäÈën:\n");
	scanf("%d",&n);
	return 0;
}
