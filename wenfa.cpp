#include<stdio.h> 
#include<iostream> 
#include<string.h> 
#define  Vtn     8 
#define  Vnn     5 
#define  Pn      10 
#define  Pmaxlen 20 
#define  MaxStLength 50 
#define  MaxStackDepth 50  
char Vn[Vnn]={'E','e','T','t','F'};  
char Vt[Vtn]={'i','+','-','*','/','(',')','$'};  
char Pstr[Pn][Pmaxlen]={        "E->Te",        "e->+Te",        "e->-Te",        "e->��",
"T->Ft",        "t->*Ft",        "t->/Ft",        "t->��",        "F->(E)",        "F->i"       };  
int Prlen[Pn]={2,3,3,1,2,3,3,1,3,1};  
int Pint[Pn][3]={  {102,101},  {1,102,101},  {2,102,101},  {-1}, 
 {104,103},  {3,104,103},  {4,104,103},  {-1}, 
 {5,100,6},  {0} };  
int analyseTable[Vnn][Vtn+1];  
int analyseStack[MaxStackDepth+1];   
int topAnalyse;                      
char st[MaxStLength];                //Ҫ�����ķ��Ŵ�  
/* ----------------------��ʼ��----------------------------*/  
void InitanalyseTable() { 
/*---Ԥ��������Ÿ�������ʽ�ı�ţ�-1��ʾ�Ҳ�����ƥ��Ĳ���ʽ---*/    
	for(int i=0;i<Vnn;i++)    
		for(int j=0;j<Vtn;j++)     
			analyseTable[i][j]=-1;     
	analyseTable[0][0]=0;     
	analyseTable[0][5]=0;     
	analyseTable[1][1]=1;     
	analyseTable[1][2]=2;     
	analyseTable[1][6]=3;     
	analyseTable[1][7]=3;	 
	analyseTable[2][0]=4;     
	analyseTable[2][5]=4;     
	analyseTable[3][1]=7;     
	analyseTable[3][2]=7;     
	analyseTable[3][3]=5;     
	analyseTable[3][4]=6;     
	analyseTable[3][6]=7;     
	analyseTable[3][7]=7;     
	analyseTable[4][0]=9;     
	analyseTable[4][5]=8;     }  
void Init() { 
  //����ջ�ĳ�ʼ�� 
  analyseStack[0]=7;      //��ջ                         
  analyseStack[1]=100;     //��ʼ����ջ   
  topAnalyse=1;  
  //��ʼ���Ŵ�   
  int i; 
  for(i = 0; i < MaxStLength;i++)   
	  st[i] = '\0'; 
}  
void Pop() { 
	topAnalyse--; 
}  
/*--------------------����ʽ��ջ����----------------------*/  
void Push(int r) { 
	int i,len;   
	Pop(); 
	len=Prlen[r];  
//Ϊ��ʱ 
	if((len==1)&&(Pint[r][0]==-1))    
		return;  
//��Ϊ��ʱ
	topAnalyse+=len;   
	for(i=0;i<len;i++) 
    analyseStack[topAnalyse-i]=Pint[r][i];   //������ջ  
} 
void ShowStack() { 
	int i; 
	for(i =0;i<=topAnalyse;i++)   { 
		if(analyseStack[i]>=100) 
			printf("%c",Vn[analyseStack[i]-100]);
		else   
			printf("%c", Vt[analyseStack[i]]);          
	} 
} 
/*----------------------���ر��е�λ�ã�-1��ʾδ�ҵ�----------*/ 
int Index(char c)  { 
	int i=0; 
		while((i<Vtn)&&(c!= Vt[i]))    
			i++; 
	if((i<Vtn)&&(c==Vt[i])) 
		return i;   
	else 
		return -1; 
} 
void Identify() { 
	int current,step,r;      
	printf("\n%s��\n\n", st);   
	step = 0; 
	current = 0;          
	printf("%d\t",step);  
	ShowStack(); 
	printf("\t\t%s\t\t- -\n", st+current);     
	while(1)  {   
		if(analyseStack[topAnalyse]<100)               {    
			if(Vt[analyseStack[topAnalyse]]==st[current])    { 
                Pop();
				current++;     
				step++;     
				printf("%d\t",step);     
				ShowStack();     
				printf("\t\t%s\t\t��ջ������\n", st+current);    
			}              
			else    {    
				printf("�ַ� %c ���ַ� %c ��ƥ�䣡", Vt[analyseStack[topAnalyse]], st[current]);     
				printf("�˴����Ǵ��ķ��ľ���\n");     
				return;    
			}   
		}   
		else  { 
            int n,m;   
			n=analyseStack[topAnalyse] - 100;             
			m=Index(st[current]);    
			if(m==-1)    { 
                printf(" %c �ַ����������룬�������" ,st[current]);     
				printf("�˴����Ǵ��ķ��ľ���\n");     
				return;    
			}       
			r = analyseTable[n][m];             
			if( r!=-1)                {     
				Push(r);          
				step++;     
				printf("%d\t", step);     
				ShowStack();    
				printf("\t\t%s\t\t%s\n", st+current,Pstr[r]);   
			}             
			else    {     
				printf("�޿��ò���ʽ���˴����Ǵ��ķ��ľ��ӣ�\n");     
				return;    
			}   
		}   
		if(topAnalyse==0&&st[current]=='$') 
			break;  
	} 
}
int main(void) { 
	InitanalyseTable();     
	while(1)    { 
		Init(); 
		printf("��������Ŵ�(��$����) : ");     
		int i=0;     
		char c; 
		c=getchar(); 
		while(i<MaxStLength)     {		
			if(c=='$')      {       
				st[i]='$';       
				break;            
			}      
			else if(c!=' '&&c!='\n')       
				st[i++]=c;          
			c=getchar();      
			if(c=='\n')      {       
				printf("����$������");       
				c=getchar();      
			}     
		} 
		if(i<MaxStLength)      
			Identify(); 
		else 
			printf("����ķ��Ŵ����������");    
	} 
	return 0;
}
