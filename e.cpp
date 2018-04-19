#include<stdio.h>
double fun(int n){
	int mul=1,i;
	for(i=1;i<=n;i++)
		mul*=i;
	return 1.0/mul;
}
int main(void){
	int i=1;
	double n,e=0;
	while((n=fun(i++))>10e-7){
		e+=n;
	}
	printf("%f\n",e);
}
