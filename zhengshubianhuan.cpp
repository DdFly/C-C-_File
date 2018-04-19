#include<stdio.h>
int bestn=1,cn=0,x[100],bestx[100];

void find(int m,int n){
	if(m==n){
		if(cn<bestn){
			bestn=cn;
			for(int i=0;i<bestn;i++)
				bestx[i]=x[i];
		}
		return;
	}
	if(cn<bestn){
		cn++;
		x[cn]=0;
		find(m/2,n);
		x[cn]=1;
		find(m*3,n);
		cn--;
		return;
	}
	else
		return;
}

void output(){
	int i;
	for(i=0;i<bestn;i++){
		if(bestx[i]==0)
			printf("g");
		else
			printf("f"); 
	}
	printf("\n");
}

int main(void){
	int m,n;
	scanf("%d%d",&m,&n);
	find(m,n);
	output();
	return 0;
}
