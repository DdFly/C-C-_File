#include<stdio.h>
#include<String.h>

int main(void){
	int i,j,k;
	char s[100]={'\0'};
	int d;
	printf("����һ������\n");
	scanf("%s",s);
	printf("����Ҫɾ���ĸ�����\n");
	scanf("%d",&d);
	k=strlen(s);
	while(d>0){
		for(i=0;i<k-1&&d>0;){
			if(s[i]>s[i+1]){
					for(j=i;j<k-1;j++){
						s[j]=s[j+1];
					}
					s[j]='\0';
					k--;
					d--;
			}
			else
				i++;
		}	
	} 
	printf("%s\n",s);
	return 0;
} 
