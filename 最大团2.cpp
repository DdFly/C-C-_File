#include<stdio.h>
#define N 2
int G[N][N];	//����ͼG
int x[N];
int bextx[N]; 
int n;
int bextn;

void init(){
	int i,j;
	printf("0���ޱߣ�1���б�\n");
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			printf("%d,%d:",i,j);
			scanf("%d",&G[i][j]);
		}
	}
	n=0;bextn=0;
}
void print(){
	int j; 
	printf("�����Ϊ��");
	for(j=0;j<N;j++){
		if(x[j]==1)
		printf("%d ",j);
	}
	printf("\n");
	printf("����ŵĸ���Ϊ��%d\n",n);
}


void backtrack(int i){
	int j,k=1;
	if(i>=N){	
		print();
		bextn=n;
		return;
	}
	else{
		for(j=0;j<i;j++){
			if(x[j]==1&&G[i][j]==0){
				k=0;
				break;
			}
		}
		if(k==1){
			x[i]=1;
			n++;
			backtrack(i+1);
			n--;
		}
		if(N+n-i>bextn){
			x[i]=0;
			backtrack(i+1);
		}
	}
}

int main(void){
	init();
	backtrack(0);
	return 0; 
}
