#include<stdio.h>
#define N 5
void sum(int D[][N],int S[][N]){
	int i,j;
	for(i=N-1;i>0;i--)
		for(j=0;j<i;j++){
			if(S[i][j]>S[i][j+1])
				S[i-1][j]=S[i][j]+D[i-1][j];
			else
				S[i-1][j]=S[i][j+1]+D[i-1][j];
		}
}
int main(void){
	int i,j;
	int D[N][N],S[N][N];
	for(i=0;i<N;i++){
		for(j=0;j<=i;j++)
			scanf("%d",&D[i][j]);
	}
	for(i=0;i<N;i++)
		S[N-1][i]=D[N-1][i];
	sum(D,S);
	printf("%d",S[0][0]);
	return 0;
}
