#include<stdio.h>
int a[100];
void mergeSort(int,int);
void Merge(int,int,int);
int main(void){
	int size;
	printf("请输入元素个数：");
	scanf("%d",&size);
	printf("输入%d个元素：\n",size);
	for(int i=0;i<size;i++){
		scanf("%d",a+i);
	}
	mergeSort(0,size);
	for(int i=0;i<size;i++)
		printf("%d ",a[i]);
	return 0;
} 
void  mergeSort(int low,int high){
	if(low+1==high)
		return;
	int mid = (low+high)/2;
	mergeSort(low,mid);
	mergeSort(mid,high);
	Merge(low,mid,high);
}

void Merge(int low,int mid,int high){
	int c[100];
	int *p=a+low;
	int *q=a+mid;
	int i=low;int j=mid;int k=low;
	while(i<mid || j<high){
		if(i==mid || (j<high&&p[i]>q[j]))
			c[k++]=q[j++];
		else
			c[k++]=p[i++];
	}
	for(i=low;i<high;i++){
		a[i]=c[i];
	}
}
