#include<stdio.h>
#include<string.h>

int aaa(char s1[],char s2[]){
	int i = 0; // ������λ
	int j = 0; // ģʽ����λ��
	int k=0;
	int n=0;
	int f=0;
//	for(i=0;i<strlen(s2);i++){
//		if(s2[i]=='?)
//			f++;	
//	}
//	printf("%d %d\n",strlen(s1),strlen(s2));
	while(k<strlen(s1)-strlen(s2)){
    	while (s1[i]!='\0' && s2[j]!='\0') {
          if ((s1[i] == s2[j]) || (s2[j]=='?')) {
                 //�������ǰ�ַ�ƥ��ɹ�����s[i]==p[j]������i++��j++
              i++;
              j++;
          } else {
                 //�����ʧ�ܣ���s[i]!=p[j]������i=i-j+1��j=0
              i = k+1;
              j = 0;
              k++;
          }
    	}
    	if (j == strlen(s2)) {
          n++;
          k++;
    	} 
  	}
  	return n;
	
}

int main(void){
	int n;
	char s1[50],s2[50];
	gets(s1);
	gets(s2);
	n=aaa(s1,s2);
	printf("%d",n);
	return 0;
}
