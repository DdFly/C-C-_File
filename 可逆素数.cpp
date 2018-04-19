#include<stdio.h>
int fun(int n){
	int i;
	for(i=2;n%i;i++);
	if(n==i)
		return 1;
	else
		return 0;
}

int main(void){
	int m=0,n;
	printf("请输入一个素数：\n");
	scanf("%d",&n);
	if(!fun(n))
		printf("不是素数！\n");
	else{
		while(n){
			m=m*10+n%10;
			n/=10;
		}
		if(fun(m))
			printf("是可逆素数！\n");
		else
			printf("不是可逆素数！\n");
	} 
} 
