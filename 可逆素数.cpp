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
	printf("������һ��������\n");
	scanf("%d",&n);
	if(!fun(n))
		printf("����������\n");
	else{
		while(n){
			m=m*10+n%10;
			n/=10;
		}
		if(fun(m))
			printf("�ǿ���������\n");
		else
			printf("���ǿ���������\n");
	} 
} 
