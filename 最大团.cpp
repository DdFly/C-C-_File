#include<stdio.h> 
#define N 5 
int x[N+1];	//��ǰ��
int cc;	//��ǰ������ 
int bestc;	//��ǰ�Դ󶥵���
int bestx[N+1];	//��ǰ���Ž� 
int a[N+1][N+1];		//�ڽӾ��󣬴洢����ͼ�ı���Ϣ
 
void inputAjac() { 
	int i,j; 
	printf("����1��ʾ�б�,0��ʾ�ޱߣ�\n"); 
	for(i=1;i<=N;i++) { 
		for(j=i+1;j<=N;j++) { 
 			printf("�������%d���㵽��%d�����:",i,j); 
 			scanf("%d",&a[i][j]); 
 			a[j][i]=a[i][j]; 
 		} 
 	} 
} 
void backtrack(int i) 
{ 
	int k=1,j;
 	//������i�������
 	if(i>N)  {
	//����Ҷ�ӽ��
		printf("�����Ϊ:"); 
 		for(j=1;j<=N;j++) {  
			if(x[j]==1) 
			printf("%3d",j);//bestx[j]=x[j]; 
		} 
 		bestc=cc; 
 		printf("\n");
		return; 
	} 
	else 
	{
 		//�ж϶���1:i-1��i�Ƿ��бߣ���������һ��������i�ޱߣ���k=0 
 		for(j=1;j<i;j++) { 
 			if(x[j]==1&&a[i][j]==0) { 
 				k=0; 
 				break; 
 			} 
 		} 
	} 
 	if(k==1) {	//����������
 		x[i]=1; 
		cc++; 
		backtrack(i+1); 
 		cc--;			//Ϊ������һ����׼��
 	} 
 	if(cc+N-i>bestc) {	//����������
 		x[i]=0; 
 		backtrack(i+1); 
 	} 
 
} 

int maxClique() {  		//��ʼ��
 	cc=0 ;bestc=0; 
	inputAjac(); 
 	backtrack(1); 
	return bestc; 
} 
 
int main(void) { 
 	printf("%d����������ͼ������Ÿ���Ϊ��%d\n",N,maxClique()); 
}


