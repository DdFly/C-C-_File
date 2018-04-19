#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
	int num,n;
	srand((unsigned)time(NULL)); 
	num=rand();
	printf("请输入您猜的数：\n");
	scanf("%d",&n);
	while(n!=num){
		if(n<num)
		  printf("偏小\n");
		else
		  printf("偏大\n");
		scanf("%d",&n);
	}
	return 0;
} 
