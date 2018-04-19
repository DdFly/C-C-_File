#include"stdio.h"
#include<string.h>
#include<stdlib.h>
#define N 30
void input(int); 
void save(int); 
void printf_back();
int load();
void modify();
void printf_face();
void printf_one(int);
int modify_data(int,int);
int modify_score1(int);
void menu();
struct student
{
 int num;
 char name[20];
 int Linux;
}stu[N];
void enter()
{int i,n;
 printf("����ѧ������(1-%d)?:",N);
 scanf("%d",&n);
 printf("\n��������\n\n");
 for(i=0;i<n;i++)
  {printf("\n �����%d��ѧ����¼.\n",i+1);
   input(i);
  }
 if(i!=0) save(n);
 printf_back();  /* browse or back */
}
void add()
{int i,n,m,k;
 FILE *fp;
 n=load();
 printf("�������ѧ���ĸ���(1-%d)?:",N-n);
 scanf("%d",&m);
 k=m+n;
 for(i=n;i<k;i++)
  {printf("\n �����%d��ѧ����¼.\n",i+1);
   input(i);
  }
 if((fp=fopen("score.txt","ab"))==NULL)
  {printf("�޷����ļ�.\n");
  }
 for(i=n;i<k;i++)
  if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
   printf("�ļ�д�����.\n");
 fclose(fp);
 printf_back();
}

void modify()
{struct student s;
 FILE *fp;
 int i,n,k,w0=1,w1,w2=0;
 n=load();
 do
  {
   k=-1;
   printf_face();
   for(i=0;i<n;i++)
    {
     printf_one(i);
     printf("\n");
    }
   do
    {printf("\n\n����Ҫ�޸ĵ�ѧ�����!  ѧ��:031073-");
     scanf("%d",&s.num);
     for(i=0;i<n;i++)
      if(s.num==stu[i].num)
       {k=i;
 s=stu[i];  /* chengji beifei */
       }
      if(k==-1) printf("\n\n�����ڣ� �������룺");
    }
   while(k==-1);
   printf_face();
   printf_one(k);
   w1=modify_data(k,n);
   if(w1==1)
    {printf("\n�ɹ� ^_^.\n\n�Ƿ��޸�����?\n\n\t1.�� 2.���ز�����\t[ ]\b\b");
     scanf("%d",&w0);
     w2=1;
    }
   else
    {w0=0;      /* end */
     if(w2==1)
      stu[k]=s;
    }
   if(w0!=1&&w2==1) save(n);  /* w0!=1 return    w2==1 modify */
  }
 while(w0==1);
 menu();
}
void delet()
{struct student s;
 FILE *fp;
 int i,n,k,w1;
 int w0=1;
 int w2=0;
 n=load();
 do
  {
   k=-1;
   printf_face();
   for(i=0;i<n;i++)
    {if((i!=0)&&(i%10==0))
      {printf("\n\nRemember NO.031073- which needed delete.���������...");
       getchar();
       puts("\n\n");
      }
     printf_one(i);
     printf("\n");
    }
   do
    {printf("\n\n����Ҫɾ����ѧ�����!  ѧ��:031073-");
     scanf("%d",&s.num);
     for(i=0;i<n;i++)
      if(s.num==stu[i].num)
       {k=i;
 s=stu[i];  /* chengji beifei */
       }
      if(k==-1) printf("\n\n�����ڣ��������룺");
    }
   while(k==-1);
   printf_face();
   printf_one(k);
   printf("\nȷ��?\n\n\t1.��2.���������� [ ]\b\b");
   scanf("%d",&w1);
   if(w1==1)
    {
     //stu[k].sum=0;
     printf("\n�ɹ� ^_^.\n\n�Ƿ��޸�����?\n\n\t1.�� 2.���ز�����\t[ ]\b\b");
     scanf("%d",&w0);
     w2=1;
    }
   else
    {w0=0;      /* end */
     if(w2==1)
      stu[k]=s;
    }
   if(w0!=1&&w2==1) save(n);
  }
 while(w0==1);
 menu();
}
void modify_score()
{struct student s;
 FILE *fp;
 int i,n,k,w1;
 int w0=1;
 int w2=0;
 n=load();
 do
  {
   k=-1;
   printf_face();
   for(i=0;i<n;i++)
    {

     printf_one(i);
     printf("\n");
    }
   do
    {printf("\n\n����Ҫ�޸ĵ�ѧ�����!  ѧ��:031073-");
     scanf("%d",&s.num);
     for(i=0;i<n;i++)
      if(s.num==stu[i].num)
       {k=i;
 s=stu[i];  /* chengji beifei */
       }
      if(k==-1) printf("\n\n��¼������!����");
    }
   while(k==-1);
   printf_face();
   printf_one(k);
   w1=modify_score1(k);
   if(w1==1)
    {printf("\n�ɹ� ^_^.\n\n�Ƿ��޸������ɼ�?\n\n\t1.�� 2.���ز�����\t[ ]\b\b");
     scanf("%d",&w0);
     w2=1;
    }
   else
    {w0=0;      /* end */
     if(w2==1)
      stu[k]=s;
    }
   if(w0!=1&&w2==1) save(n);  /* w0!=1 return    w2==1 modify */
  }
 while(w0==1);
 menu();
}

void browse()
{
	int i,j,n;
 	n=load();
 printf_face();
 for(i=0;i<n;i++)
  {if((i!=0)&&(i%10==0))
    {printf("\n\n���������...");
     getchar();
     puts("\n\n");
    }
   printf_one(i);
   printf("\n");
  }
 printf("\t�� %d ���ɼ�.\n",n);
 printf("\n���������...");
 fflush(stdin);
 getchar();
 menu();
}

void order()
{
	int i,j,k,n;
 	struct student s;
 	n=load();
 	for(i=0;i<n-1;i++)
  	{	k=i;
   		for(j=i+1;j<n;j++)
    	if(stu[j].num<stu[k].num) k=j;
    s=stu[i];stu[i]=stu[k];stu[k]=s;
  }
 save(n);
 puts("\n\n");
 printf_back();
}

void save(int n)
{
	FILE *fp;
 int i;
 if((fp=fopen("score.txt","wb"))==NULL)
  {printf("\n�޷����ļ�\n");
   return;
  }
 for(i=0;i<n;i++)
  if(stu[i].Linux!=0)
   if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
    printf("�ļ�д�����\n");
 fclose(fp);
}
int load()
{
	FILE *fp;
 int i;
 if((fp=fopen("score.txt","rb"))==NULL)
  {printf("\n�޷����ļ�\n");
   return -1;
  }
 for(i=0;!feof(fp);i++)
  fread(&stu[i],sizeof(struct student),1,fp);
 fclose(fp);
 return(i-1);
}
void no_input(int i,int n)
{int k,w1;
 do
  {w1=0;
   printf("NO.:031073-");
   scanf("%d",&stu[i].num);
   if(stu[i].num<1 || stu[i].num>N)
     {puts("�������! (1-N).����������!\n");
      w1=1;
     }
   if(w1!=1)
     for(k=0;k<n;k++)
      if(k!=i&&(stu[k].num==stu[i].num))
       {puts("��¼����.����������!\n");
 w1=1;break;
       }
   }
  while(w1==1);
}
void enter_score(int i)
{
	printf("�ɼ���\n");
 scanf("%d",&stu[i].Linux);
}

void input(int i)
{
	no_input(i,i);
 printf("����:\n");
 scanf("%s",stu[i].name);
 enter_score(i);
}
int modify_score1(int i)
{
	int c,w1;
 do
  {

  printf("�ɼ�:");scanf("%d",&stu[i].Linux);
  puts("\nNow:\n");
  printf_face();
  printf_one(i);
  printf("\nȷ��?\n\n\t1.�� 2.�����޸�3.���������� [ ]\b\b");
  scanf("%d",&w1);
 }
 while(w1==2);
 return(w1);
}
int modify_data(int i,int n)
{
	int c,w1;
 do
  {
   puts("\n�޸�ѡ�\n\n 1.���. 2.���� 3.�ɼ� 4.�������� 5.����");
   printf("��ѡ��:[ ]\b\b");
   scanf("%d",&c);
   if(c>9||c<1)
    {puts("\nѡ�����!������ѡ��");
     getchar();
    }
  }
 while(c>9||c<1);
 do
  {switch(c)
    {case 1:no_input(i,n);break;
     case 2:printf("����:");scanf("%s",stu[i].name);break;
     case 3:printf("�ɼ�:");scanf("%d",&stu[i].Linux);break;
     case 4:input(i);break;
     case 5:break;
    }
//  if(c>3&&c<8) sum(i);
  puts("\nNow:\n");
  printf_face();
  printf_one(i);
  printf("\nȷ��?\n\n\t1.�� 2.��3.���������� [ ]\b\b");
  scanf("%d",&w1);
 }
 while(w1==2);
 return(w1);
}
void printf_face()
{
	printf("\nNO.031073  ����   Linux\n");
}
void printf_one(int i)
{
 printf("%6d %8s",stu[i].num,stu[i].name);
 printf("%5d ",stu[i].Linux);
}
void printf_back()
{int k,w;
 printf("\n\n\t�ɹ�.^_^\n\n");
 printf("��ѡ��?\n\n\t1.�������\t2.����:[ ]\b\b");
 scanf("%d",&w);
 if(w==1) browse();
 else menu();
}
void menu()
{
	int w1;
 	char n;
 do
  {
   puts("\t\t****************MENU****************\n\n");
   puts("\t\t\t\tA.��������");
   puts("\t\t\t\tB.�������");
   puts("\t\t\t\tC.��������");
   puts("\t\t\t\tD.ɾ������");
   puts("\t\t\t\tE.�޸ĳɼ�");
   puts("\t\t\t\tF.��˳����ʾ");
   puts("\t\t\t\tG.��ʾȫ��");
   puts("\t\t\t\tH.Exit");
   puts("\n\n\t\t************************************\n");
   printf("������ѡ��(A-H):[ ]\b\b");
   fflush(stdin);
   n=getchar();
   printf("\n");
   if(n<'A'||n>'H')
      w1=1;
   else w1=0;
  }
 while(w1==1);
 switch(n)
  {case 'A':enter();break;
   case 'B':add();break;
   case 'C':modify();break;
   case 'D':delet();break;
   case 'E':modify_score();break;
   case 'F':order();break;
   case 'G':browse();break;
   case 'H':exit(0);
  }
}
char password[7]="123456";
main()
{   
 	char s[7];
	printf("\t\t����������:\n\t\t\n\t\t");
	scanf("%s",s);
 if(!strcmp(s,password))
 {
        printf("\n\t\t��ϲ�����ѧ���ɼ�����ϵͳ\n");
  menu();
 }
    else
 {   
  printf("\t\t �������\n\n");
  main();
 }
}
