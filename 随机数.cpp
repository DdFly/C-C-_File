#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
	int num,n;
	srand((unsigned)time(NULL)); 
	num=rand();
	printf("���������µ�����\n");
	scanf("%d",&n);
	while(n!=num){
		if(n<num)
		  printf("ƫС\n");
		else
		  printf("ƫ��\n");
		scanf("%d",&n);
	}
	return 0;
} 
