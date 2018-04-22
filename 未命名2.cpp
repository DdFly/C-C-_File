#include<stdio.h> 
#include<math.h>
int fun(int n){
	int i=0;
	while(n){
		i++;
		n/=10;
	}
	return i;
} 
int main(void){
	int a,b,i,k,sum,cnt;
	sum=0;cnt=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++){
		k=fun(i);
		sum=sum*pow(10,k)+i;
		if(sum%3==0)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
