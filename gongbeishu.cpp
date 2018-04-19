#include<iostream>
using namespace std;
#define MAXN 100000
char res[MAXN] ={'\0'};
void multi(char*ch,int num)
{
    int i,high=0,temp;
    for(i=0;ch[i];++i)
    {
        temp = num*(ch[i]-48)+high;
        ch[i] = temp%10 + '0' ;
        high = temp /10;
    }
    //针对进位还有剩余的情况
    while(high)
    {
        ch[i++] = high%10+48;
        high /=10;
    }
}
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int mod(char*ch,int b)
{
    int left=0,i;
    for(i=-1;ch[i+1]!='\0';++i);
    for(;i>=0;--i)
    {
        left = left*10+ch[i]-48;
        left %=b;
    }
    return left==0 ? b : gcd(b,left);
}
void solve(int n)
{
    res[0]='1';
    for(int i=2;i!=n+1;++i)
    {
        int temp = mod(res,i);
        multi(res,i/temp);
    }
}
void print(char *ch)
{
    int i;
    for(i=-1;ch[i+1];++i);
    if(i>8)
		i=8;
    for(;i>=0;--i)
    {
        cout <<ch[i] ;
    }
}
int main()
{
    int n;
    cin >> n;
    solve(n);
    print(res);
    return 0;
}
