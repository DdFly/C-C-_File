#include<stdio.h>

void LCSLength(int m,int n,char X[],char Y[],int b[][9],int c[][9]){
	int i,j; 
	for (i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			if(X[i-1]==Y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
}
void LCS(int i,int j,char X[],int b[][9]){
	if (i==0 || j==0)
		return;
	if(b[i][j]==1){
		LCS(i-1,j-1,X,b);
		printf("%c ",X[i-1]);
	}
	else if(b[i][j]==2)
		LCS(i-1,j,X,b);
	else
		LCS(i,j-1,X,b);
}
int main(void){
	char X[]={'a','s','d','f','g','h'};
	char Y[]={'a','w','s','d','r','f','g','h'};
	int b[7][9]={0},c[7][9]={0};
	LCSLength(6,8,X,Y,b,c);
	LCS(6,8,X,b);
	printf("\n");
	return 0;
} 
