#include<stdio.h>

int main(void){
	int a[100],b[100];
	int i,j,k,l;
	int m,n;
	scanf("%d,%d",&m,&n); 
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(j=0;j<n;j++)
		scanf("%d",&b[j]);
	k=m;
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			if(b[i]<=a[j]){
				for(l=k;l>j;l--)
					a[l]=a[l-1];
				a[l]=b[i];
				k++;
				break;
			}
		}
		if(j==k){
			a[j]=b[i];
			k++;
		}
	}
	for(i=0;i<k;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
