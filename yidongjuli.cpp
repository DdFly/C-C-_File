#include<stdio.h>
int main(void){
	int w,m,n;
	int x1,x2,y1,y2;
	scanf("%d%d%d",&w,&m,&n);
	y1=m/(w+1);y2=n/(w+1);
	if(!y1%2){
		x1=m%w;
	}
	else
		x1=w-m%(w+1);
	if(!y2%2)
		x2=n%w;
	else
		x2=w-n%(w+1);
	printf("%d",(x2>x1?x2-x1:x1-x2)+(y2>y1?y2-y1:y1-y2));
	return 0;
} 
