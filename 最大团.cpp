#include<stdio.h> 
#define N 5 
int x[N+1];	//当前解
int cc;	//当前顶点数 
int bestc;	//当前对大顶点数
int bestx[N+1];	//当前最优解 
int a[N+1][N+1];		//邻接矩阵，存储无向图的边信息
 
void inputAjac() { 
	int i,j; 
	printf("输入1表示有边,0表示无边：\n"); 
	for(i=1;i<=N;i++) { 
		for(j=i+1;j<=N;j++) { 
 			printf("请输入第%d顶点到第%d顶点边:",i,j); 
 			scanf("%d",&a[i][j]); 
 			a[j][i]=a[i][j]; 
 		} 
 	} 
} 
void backtrack(int i) 
{ 
	int k=1,j;
 	//遍历第i层的子树
 	if(i>N)  {
	//到达叶子结点
		printf("最大团为:"); 
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
 		//判断顶点1:i-1与i是否有边，若其中有一个顶点与i无边，则k=0 
 		for(j=1;j<i;j++) { 
 			if(x[j]==1&&a[i][j]==0) { 
 				k=0; 
 				break; 
 			} 
 		} 
	} 
 	if(k==1) {	//进入左子树
 		x[i]=1; 
		cc++; 
		backtrack(i+1); 
 		cc--;			//为进入下一层做准备
 	} 
 	if(cc+N-i>bestc) {	//进入右子树
 		x[i]=0; 
 		backtrack(i+1); 
 	} 
 
} 

int maxClique() {  		//初始化
 	cc=0 ;bestc=0; 
	inputAjac(); 
 	backtrack(1); 
	return bestc; 
} 
 
int main(void) { 
 	printf("%d个顶点无向图的最大团个数为：%d\n",N,maxClique()); 
}


