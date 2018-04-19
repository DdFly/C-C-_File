#include<stdio.h>

int fun(int a[],int n){
	int pl,pr,i,j,sum;
	pl=0;	pr=n-1;
	i=1;	j=n-2;
	sum=0;
	do{
		if(a[i]<a[pl]&&a[i]<a[pr]){
			sum+=(a[pl]<a[pr]?(a[pl]-a[i]):(a[pr]-a[i]));
			i++;
		}else if(a[i]>a[pl])
			pl=i;
		if(a[j]<a[pl]&&a[j]<a[pr]){
			sum+=(a[pl]<a[pr]?(a[pl]-a[j]):(a[pr]-a[j]));
			j--;
		}else if(a[j]>a[pr])
			pr=j;
			
		
	}while(i!=j);
	return sum;
}

int main(void){
	int a[]={5,1,2,5,1,2};
	printf("´¢Ë®Á¿Îª£º%d\n",fun(a,sizeof(a)/sizeof(int)));
	return 0;
} 
