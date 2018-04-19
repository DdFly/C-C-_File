#include<stdio.h>
int m,n;

double select(int a[],int b[]){
	int i,j,x,y,t,l;
//	if(a[0]<b[0]){
//		x=a[0];
//	}else{
//		x=b[0];
//	}
	for(i=0,j=0,l=0;l<=(m+n)/2;){
		if(i==m){
			y=x;x=b[j];j++;l++;
		}else if(j==n){
			y=x;x=a[i];i++;l++;
		}else if(a[i]>b[j]){
			y=x;x=b[j];j++;l++;
		}else{
			y=x;x=a[i];i++;l++;
		}
	}
	if((m+n)%2)
		return x;
	else
		return (x+y)/2.0;
}

int main(void){
	int a[100],b[100];
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		scanf("%d",a+i);
	for(int j=0;j<n;j++)
		scanf("%d",b+j);
	printf("%f\n",select(a,b));
	return 0;
	
}
