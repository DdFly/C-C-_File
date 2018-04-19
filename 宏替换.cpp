#include<stdio.h>
#define S(x,y) (x)>(y)?(x):(y)
//#define R(S(x,y),z) 
int main(void){
	int a,b,c;
	printf("输入三个数：\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",S(a,S(b,c)));
	return 0;
}
