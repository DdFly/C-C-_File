#include<stdio.h> 
#define N 5
void input(int D[][N]) {
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<=i;j++)
			scanf("%d",&D[i][j]);
	}
}
void sum(int D[][N],int S[][N]){
	int i,j;
	for(i=0;i<N;i++){
		S[N-1][i]=D[N-1][i];
	}
	for(i=N-1;i>0;i--){
		for(j=0;j<i;j++){
			if(S[i][j]<S[i][j+1])
				S[i-1][j]=D[i][j]+S[i][j+1];
			else
				S[i-1][j]=D[i][j]+S[i][j];
		}
	}
	
} 
int main(void){
	int D[N][N],S[N][N];
	input(D);
	sum(D,S);
	printf("%d\n",S[0][0]);
	return 0;
}
