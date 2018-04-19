#include<stdio.h>
#include<stdlib.h>

int fun(int a[],int n){			//计算储水量 
	int i,j,lmax,rmax,mul;
	for(i=1,mul=0;i<n-1;i++){
		for(j=1,lmax=a[0];j<i;j++){
			if(a[j]>lmax)
				lmax=a[j];
		}
		for(j=n-1,rmax=a[n-1];j>i;j--){
			if(a[j]>rmax)
				rmax=a[j];
		}
		if(a[i]<lmax&&a[i]<rmax)
			mul=mul+((lmax>rmax)?(rmax-a[i]):(lmax-a[i]));
			
	}
	return mul;
}

int main(void){
	int a[]={5,1,2,5,1,2};
	printf("储水量为：%d\n",fun(a,sizeof(a)/sizeof(int)));
	return 0;
} 
