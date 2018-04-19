#include<stdio.h>

int main(void){
	int i,j,k[8];
	int a[8][8]={0};
	int b[8]={0};
	int c[15]={0};
	int d[15]={0};
	j=0;
	for(i=0;i<8;){
		for(;j<8;j++){
			if(b[j]!=0 || c[i+j]!=0 || d[i-j+7]!=0){
				continue;
			}
			else{
				a[i][j]=1;
				b[j]=1;
				c[i+j]=1;
				d[i-j+7]=1;
				k[i]=j;
				j=0;
				i++;
				break;
			}
			
		}
		if(j==8){
			i--;
			j=k[i];
			k[i]=0;
			a[i][j]=0;
			b[j]=0;
			c[i+j]=0;
			d[i-j+7]=0;
			j++;
						
		}
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			printf("%2d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
