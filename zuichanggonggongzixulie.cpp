#include<stdio.h>
int m,n;

void LCSLength(int a[],int b[],int x[][100]){
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(a[i-1]==b[j-1])}
				x[i][j]=x[i-1][j-1];
				y[i][j]=1;
			}else if(x[i-1][j]>=x[i][j-1]){
				x[i][j]=x[i-1][j];
				y[i][j]=2;
			}else{
				x[i][j]=x[i][j-1];
				y[i][j]=3;
			}	
		}
	}
}

void LCS(int a[],int y[][100]){
	
}

int main(void){
	int a[100],b[100];
	int x[100][100]={0},y[100][100]={0};
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(int j=0;j<n;j++)
		scanf("%d",&b[j]);
	LCSLength(a,b,x,y);
	LCS(a,y);
	return 0;
} 
