#include<stdio.h>
#include<stdlib.h>
int main(void){
	int a[1000]={0};
	int c[1000]={0};
	int n,k,i,j,t,cnt=0;
	int max=0;
	scanf("%d",&n);
	if(n<1||n>1000)
		exit(1);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		if(k<1||k>1000)
			exit(1);
		for(j=0;j<k;j++){
			scanf("%d",&t);
			if(c[t]==0){
				cnt++;
				a[t]=1;
			}
			if(c[t]==1){
				cnt--;
				a[t]=0;
			}			
				
		}
		if(max<cnt){
			for(j=0;j<1000;j++)
				c[j]=a[j];
			max=cnt;
		}
	}
	printf("%d",max);
	return 0;
} 
