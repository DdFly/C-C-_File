#include<stdio.h>
#include<String.h>
void sort(char s[],int n[],int k){
	int i,j,t;
	char c;
	int min;
	for(i=0;i<k-1;i++){
		min=i;
		for(j=i+1;j<k;j++){
			if(s[j]<s[min])
				min=j;
		}
		c=s[i];
		s[i]=s[min];
		s[min]=c;
		t=n[min];
		n[min]=n[i];
		n[i]=t;
		
	}

}
void result(char s[],int n[],int k,int d){
	int i,j;
	int b = k-d;
	int t=-1;
	int sum=0;
	for(i=0;i<k&&b>0;i++){
		if(n[i]>t){
			sum=sum*10+(s[i]-'0');
			b--;
			t=n[i];	
		}
			
	}
	printf("%d\n",sum);
}
int main(void){
	char s[100]={'\0'},c;
	int n[100];
	int d,k,i,j,t;
	printf("输入一个数：\n");
	scanf("%s",s);
	printf("输入要删除的个数：\n");
	scanf("%d",&d);
	k=strlen(s);
	for(i=0;i<k;i++){
		n[i]=i;
	}
	sort(s,n,k);
	result(s,n,k,d);
	
}
