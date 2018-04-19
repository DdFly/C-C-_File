#include<stdio.h>
#define N 10
int find(int a[],int b[]){
	int i,j,c;
	for(i=1,j=0;i<N-1;i++){
		if(a[i-1]>a[i]){
			b[j]=i;
			j++;
		}
	}
}
void sort(int a[],int b[],int n){
	int i,j;
	for(i=0;i<n;i+=2){
		if(b[i]<b[i+1]){
			paixu(a,b[i+1]);
		}
	}
}
void print(int a[]){
	
}
int main(void){
	int a[100]={12,4,9,11,25,24,6,15,17,22};
	int b[100]={0};
	sort(a,b,find(a,b));
	print(a);
	return 0;
} 
