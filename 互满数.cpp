#include<stdio.h>
int fun(int n){
	int sum=0;
	int i;
	for(i=1;i<n;i++){
		if(n%i==0)
			sum+=i;
	}
	return sum;
}

int main(void){
	int x,y;
	for(x=1;x<=10000;x++){
		y=fun(x);
		if(x==fun(y))
			printf("%8d%8d\n",x,y);
	}
}
