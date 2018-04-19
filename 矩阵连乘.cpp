#include<stdio.h>

void print(int m[][7],int s[][7]){
	int i,j;
	for (i=1;i<7;i++){
		for(j=i;j<7;j++)
			printf("%8d",m[i][j]);
		printf("\n");
	}
	printf("\n");
	for (i=1;i<7;i++){
		for(j=i;j<7;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
}

void Matrix(int *p,int n,int m[][7],int s[][7]){
	int i,j,k,r;
	for(i=1;i<n;i++){
		m[i][i]=0;s[i][i]=0;
	}
	for(r=2;r<n;r++){
		for(i=1;i<n-r+1;i++){
			j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			//printf("%d ",m[i][j]);
			s[i][j]=i; 
			for(k=i+1;k<j;k++){
				int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				//printf("%d  ",t);
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
}

void TraceBack(int i,int j,int s[][7]){
	if(i==j)
		return;
	TraceBack(i,s[i][j],s);
	TraceBack(s[i][j]+1,j,s);
	printf("(A%d,%d),(A%d,%d)\n",i,s[i][j],s[i][j]+1,j);
} 

int main(void){
	
	int p[7]={30,35,15,5,10,20,25};
	int m[7][7],s[7][7];
	Matrix(p,7,m,s);
	TraceBack(1,6,s);
	//print(m,s);
	return 0;
	
} 
