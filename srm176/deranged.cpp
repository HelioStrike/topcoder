#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 16
using namespace std;

int n,a[N],dp[1<<N];

ll solve(int m,int d)
{
    if(m==0) return 1;
    if(dp[m]!=-1) return dp[m];
    dp[m]=0; int pr=-1;
    FOR(i,0,n)
    {
        if(m&(1<<i) && pr!=a[i])
        {
            pr=a[i];
            if(a[i]!=a[d]) dp[m]+=solve(m^(1<<i),d+1);
        }
    }
    return dp[m];
}

int main()
{
    cin>>n; FOR(i,0,n) cin>>a[i];
    sort(a,a+n); memset(dp,-1,sizeof(dp));
    cout<<solve((1<<n)-1,0)<<'\n';
    return 0;
}