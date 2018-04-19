#include<stdio.h>
#define N 4
double chazhao(int a[],int b[],int m){
	int i,j,n,t;
	for (i=0,j=0,n=0;n<N;){
		if (a[i]<=b[j]){			
			t=a[i];
			i++;
		}
		else{	
			t=b[j];
			j++;
		}
		n++;
	}
	if(a[i]<=b[j])
		return (a[i]+t)/2.0;
	else
		return (b[j]+t)/2.0;
}

int main(void){
	int a[N];
	int b[N];
	int i;
	double s;
	for(i=0;i<N;i++){
		scanf("%d",a+i);
	}
	for(i=0;i<N;i++){
		scanf("%d",b+i);
	}
	s=chazhao(a,b,N);
	printf("ÖÐÎ»Êý£º%.1f\n",s);
	return 0;
}
