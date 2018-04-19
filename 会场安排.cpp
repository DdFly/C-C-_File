#include<stdio.h>
#define N 5

int min(int F[],int S[],int E[]){
	int i,j,k;
	E[0]=F[0];
	for(i=1,k=1;i<N;i++){
		for(j=0;j<k;j++){
			if(E[j]<=S[i]){
				E[j]=F[i];
				break;
			}
		}	
		if(j==k){
			k++;
			E[j]=F[i];
		}	
	}
	
	return k;
}

int main(void){
	int F[]={23,28,35,80,50},S[]={1,12,25,27,36},E[N]={0};
	printf("%d\n",min(F,S,E));
	
	return 0;
} 
