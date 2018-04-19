#include<stdio.h>

Quick(int data[],int low,int high){
	if(low>=high-1)
		return;
	int i=low+1;int j=high-1;
	while(i<j-1){
		
	}
}

int main(void){
	int data[]={5,2,3,4,8,7,6,9};
	Quick(data,0,8);
	for(int i=0;i<8;i++){
		printf("%d ",data[i]);
	}
	return 0;
} 
