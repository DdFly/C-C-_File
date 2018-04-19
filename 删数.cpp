#include<stdio.h>
#include<string.h>
int main(void){
	int i,t,k,n,min,sum=0;
	char s[100]={'\0'};
	scanf("%s",s);
	scanf("%d",&n);
	k = strlen(s);
	i=0;t=0;
	while(i<k){
		if(s[i]<s[i+1]){
			sum=sum*10+(s[i]-'0');
			i++;
		}
		else{
			if(t<n){
				i++;
				t++;
			}
			else{
				sum=sum*10+(s[i]-'0');
				i++;
			}
		}
	} 
//	for(i=0,j=0;i<k-n;i++){
//		min=j;
//		for(j=min+1;j<=k-n+i;j++){
//			if(s[j]<s[min])
//				min=j;
//		}
//		sum=sum*10+(s[min]-'0');
//	}
	printf("%d\n",sum);
	return 0;
}

