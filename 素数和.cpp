#include<stdio.h> 
#include<stdlib.h>
int fun(int x){
	int i;
	for(i=2;x%i!=0;i++);
	if(i==x)
		return 1;
	else
		return 0;
}
int main(void){
	int x,i;
	printf("输入一个大于4的偶数：\n");
	scanf("%d",&x);
	if(x<4||x%2)
		exit(0);
	for(i=2;i<=x/2;i++){
		if(fun(i))
			if(fun(x-i)){
				printf("%d+%d\n",i,x-i);
			}
				
				
	}
	return 0;
}
