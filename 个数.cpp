#include<bits/stdc++.h>  
using namespace std;  
#define inf 0x3f3f3f3f3f  
#define mod 1000000007  
int n,m,x;  
int a1[1005],a2[1005];  
long long dp[1005][1005];  
int main()  
{  
    while(cin>>n>>m)  
    {  
        long long ans=0;  
        memset(dp,0,sizeof(dp));  
        for(int i=1; i<=n; i++)  
            cin>>a1[i];  
        for(int i=1; i<=m; i++)  
            cin>>a2[i];  
        for(int i=1; i<=n; i++)  
        {  
            for(int j=1; j<=m; j++)  
            {  
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;;  
                if(a1[i]==a2[j])  
                {  
                    dp[i][j]+=(dp[i-1][j-1]+1)%mod;;  
                }  
            }  
        }  
        cout<<dp[n][m]<<endl;  
    }  
    return 0;  
} 
