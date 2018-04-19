#include<stdio.h>
int s;
void dealwith(int *a,int n,int *b,int r){
	b[0]=0;
	int l=n-r;
	 s=0;
    int sit=0;
	int min;
	int i;
	while(l--){
		if(s==0){
		 min=a[0];
			for(i=1;i<r+1;i++){
				if(min>a[i]){
					min=a[i];
					sit=i;
				}
			}
			b[s]=sit;
			s+=1;
			r=r+1;
		}else{
			sit+=1;
			min=a[sit];
			for(int i=sit+1;i<=r;i++){
				
				if(min>a[i]){
					min=a[i];
					sit=i;
				}
			}
		
			b[s]=sit;
			s+=1;
			r=r+1;
		}
	}
} 
main(){
	int a[]={3,7,8,5,4,2};
	int b[10];
	int t=4;
	dealwith(a,6,b,t);
	for(int i=0;i<s;i++){
		printf("%d",a[b[i]]);
	}
}
