#include<stdio.h>
int m,n,k;
bool found;
int result[100]={0};

int fg(int n,int i){
	if(i==0)
		return n/2;
	else
		return n*3;
}
bool search(int dep,int n){ 
    if(dep>k){
    	return false;
    } 
		  
 	for(int i=0;i<2;i++){  
  		int n1 = fg(n,i);  
		result[dep]=i;    
  		if(n1==m|| search(dep+1,n1)){   
   			found = true;        
   			return true;   
    	}   
	} 
	return false;
} 

void compute(){  
	k=1;
	found=false;
	while(!search(1,n)){  
 		k++;
 	}    
 }    
void output(int k){
	for(int i=0;i<k;i++){
		if(result[i]==0){
			printf("%s","f");
		}
		else
			printf("%s","g");
	}
	printf("\n");
}
int main(void){
	scanf("%d%d",&m,&n);
	compute();
	output(k); 
} 
