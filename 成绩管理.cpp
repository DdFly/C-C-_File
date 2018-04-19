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
 int age;
 int Math;
 int English;
 int Physical;
 long int sum;
}stu[N];
void enter()
{int i,n;
 printf("输入学生个数(1-%d)?:",N);
 scanf("%d",&n);
 printf("\nEnter data now\n\n");
 for(i=0;i<n;i++)
  {printf("\n 输入%d个学生记录.\n",i+1);
   input(i);
  }
 if(i!=0) save(n);
 printf_back();  /* browse or back */
}
void add()
{int i,n,m,k;
 FILE *fp;
 n=load();
 printf("输入添加学生的个数(1-%d)?:",N-n);
 scanf("%d",&m);
 k=m+n;
 for(i=n;i<k;i++)
  {printf("\n 输入第%d个学生记录.\n",i+1);
   input(i);
  }
 if((fp=fopen("score.txt","ab"))==NULL)
  {printf("无法打开文件.\n");
  }
 for(i=n;i<k;i++)
  if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
   printf("文件写入错误.\n");
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
    {if((i!=0)&&(i%10==0))
      {printf("\n\nRemember NO.031073- which needed modify.按任意键继续...");
       getchar();
       puts("\n\n");
      }
     printf_one(i);
     printf("\n");
    }
   do
    {printf("\n\n输入要修改的学生编号!  NO.:031073-");
     scanf("%d",&s.num);
     for(i=0;i<n;i++)
      if(s.num==stu[i].num)
       {k=i;
 s=stu[i];  /* chengji beifei */
       }
      if(k==-1) printf("\n\n不存在！ 重新输入：");
    }
   while(k==-1);
   printf_face();
   printf_one(k);
   w1=modify_data(k,n);
   if(w1==1)
    {printf("\n成功 ^_^.\n\n是否修改其他?\n\n\t1.是 2.返回并保存\t[ ]\b\b");
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
      {printf("\n\nRemember NO.031073- which needed delete.任意键继续...");
       getchar();
       puts("\n\n");
      }
     printf_one(i);
     printf("\n");
    }
   do
    {printf("\n\n输入要删除的学生编号!  NO.:031073-");
     scanf("%d",&s.num);
     for(i=0;i<n;i++)
      if(s.num==stu[i].num)
       {k=i;
 s=stu[i];  /* chengji beifei */
       }
      if(k==-1) printf("\n\n不存在！重新输入：");
    }
   while(k==-1);
   printf_face();
   printf_one(k);
   printf("\n确定?\n\n\t1.是2.放弃并返回 [ ]\b\b");
   scanf("%d",&w1);
   if(w1==1)
    {
     stu[k].sum=0;
     printf("\n成功 ^_^.\n\n是否修改其他?\n\n\t1.是 2.返回并保存\t[ ]\b\b");
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
    {if((i!=0)&&(i%10==0))
      {printf("\n\nRemember NO.031073 which score needed modify.任意键继续...");
       getchar();
       puts("\n\n");
      }
     printf_one(i);
     printf("\n");
    }
   do
    {printf("\n\n输入要修改的学生编号!  NO.:031073-");
     scanf("%d",&s.num);
     for(i=0;i<n;i++)
      if(s.num==stu[i].num)
       {k=i;
 s=stu[i];  /* chengji beifei */
       }
      if(k==-1) printf("\n\n记录不存在!重新");
    }
   while(k==-1);
   printf_face();
   printf_one(k);
   w1=modify_score1(k);
   if(w1==1)
    {printf("\n成功 ^_^.\n\n是否修改其他成绩?\n\n\t1.是 2.返回并保存\t[ ]\b\b");
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
void browse()
{
	int i,j,n;
 	n=load();
 printf_face();
 for(i=0;i<n;i++)
  {if((i!=0)&&(i%10==0))
    {printf("\n\n任意键继续...");
     getchar();
     puts("\n\n");
    }
   printf_one(i);
   printf("\n");
  }
 printf("\tThere are %d record.\n",n);
 printf("\n任意键返回...");
 fflush(stdin);
 getchar();
 menu();
}
void save(int n)
{
	FILE *fp;
 int i;
 if((fp=fopen("score.txt","wb"))==NULL)
  {printf("\n无法打开文件\n");
   return;
  }
 for(i=0;i<n;i++)
  if(stu[i].sum!=0)
   if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
    printf("文件写入出错\n");
 fclose(fp);
}
int load()
{
	FILE *fp;
 int i;
 if((fp=fopen("score.txt","rb"))==NULL)
  {printf("\n无法打开文件\n");
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
     {puts("输入错误! (1-N).请重新输入!\n");
      w1=1;
     }
   if(w1!=1)
     for(k=0;k<n;k++)
      if(k!=i&&(stu[k].num==stu[i].num))
       {puts("记录存在.请重新输入!\n");
 w1=1;break;
       }
   }
  while(w1==1);
}
void enter_score(int i)
{
	printf("数学  英语  物理\n");
 scanf("%d %d %d",&stu[i].Math,&stu[i].English,&stu[i].Physical);
}
void sum(int i)
{
 stu[i].sum=stu[i].Math+stu[i].English+stu[i].Physical;
}
void input(int i)
{
	no_input(i,i);
 printf("姓名:   年龄:\n");
 scanf("%s %d",stu[i].name,&stu[i].age);
 enter_score(i);
 sum(i);
}
int modify_score1(int i)
{
	int c,w1;
 do
  {
   puts("\n修改选项：\n\n 1.数学 2.英语 3.物理 4.所有 5.放弃并返回");
   printf("请选择?:[ ]\b\b");
   scanf("%d",&c);
   if(c>5||c<1)
    {puts("\n错误！请重新选择!");
     getchar();
    }
  }
 while(c>5||c<1);
 do
  {switch(c)
    {
     case 1:printf("Math:");scanf("%d",&stu[i].Math);break;
     case 2:printf("English:");scanf("%d",&stu[i].English);break;
     case 3:printf("Physical:");scanf("%d",&stu[i].Physical);break;
     case 4:enter_score(i);break;
     case 5:break;
    }
  if(c>0&&c<5) sum(i);
  puts("\nNow:\n");
  printf_face();
  printf_one(i);
  printf("\n确定?\n\n\t1.是 2.重新修改3.放弃并返回 [ ]\b\b");
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
   puts("\n修改选项：\n\n 1.编号. 2.姓名 3.年龄 4.数学 5.英语 6.物理 7.所有成绩 8.所有数据 9.返回");
   printf("请选择:[ ]\b\b");
   scanf("%d",&c);
   if(c>9||c<1)
    {puts("\n选择错误!请重新选择：");
     getchar();
    }
  }
 while(c>9||c<1);
 do
  {switch(c)
    {case 1:no_input(i,n);break;
     case 2:printf("姓名:");scanf("%s",stu[i].name);break;
     case 3:printf("年龄:");scanf("%d",&stu[i].age);break;
     case 4:printf("数学:");scanf("%d",&stu[i].Math);break;
     case 5:printf("英语:");scanf("%d",&stu[i].English);break;
     case 6:printf("物理:");scanf("%d",&stu[i].Physical);break;
     case 7:enter_score(i);break;
     case 8:input(i);break;
     case 9:break;
    }
  if(c>3&&c<8) sum(i);
  puts("\nNow:\n");
  printf_face();
  printf_one(i);
  printf("\n确定?\n\n\t1.是 2.否3.放弃并返回 [ ]\b\b");
  scanf("%d",&w1);
 }
 while(w1==2);
 return(w1);
}
void printf_face()
{
	printf("\nNO.031073  姓名   年龄  数学  英语  物理  总成绩\n");
}
void printf_one(int i)
{
 printf("%6d %8s %4d",stu[i].num,stu[i].name,stu[i].age);
 printf("%5d %5d %8d %10d",stu[i].Math,stu[i].English,stu[i].Physical,stu[i].sum);
}
void printf_back()
{int k,w;
 printf("\n\n\t成功.^_^\n\n");
 printf("请选择?\n\n\t1.浏览所有\t2.返回:[ ]\b\b");
 scanf("%d",&w);
 if(w==1) browse();
 else menu();
}
void menu()
{int w1;
 char n;
 do
  {
   puts("\t\t****************MENU****************\n\n");
   puts("\t\t\t\tA.输入数据");
   puts("\t\t\t\tB.添加数据");
   puts("\t\t\t\tC.更新数据");
   puts("\t\t\t\tD.删除数据");
   puts("\t\t\t\tE.修改成绩");
   puts("\t\t\t\tF.按顺序显示");
   puts("\t\t\t\tG.显示全部");
   puts("\t\t\t\tH.Exit");
   puts("\n\n\t\t************************************\n");
   printf("请输入选项(A-H):[ ]\b\b");
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
	printf("\t\t请输入密码:\n\t\t\n\t\t");
 scanf("%s",s);
 if(!strcmp(s,password))
 {
        printf("\n\t\t恭喜你进入学生成绩管理系统\n");
  menu();
 }
    else
 {   
  printf("\t\t 密码错误\n\n");
  main();
 }
}
