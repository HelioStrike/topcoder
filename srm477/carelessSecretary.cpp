#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 5010
#define K 15
using namespace std;

int n,k;
ll fac[N],dp[K][N];

ll solve(int d,int m)
{
    if(dp[d][m]>=0) return dp[d][m];
    if(d==k) return dp[d][m]=fac[n-k];
    ll res=0;
    FOR(i,0,k) if(!(m&(1<<i)) && d!=i) res=(res+solve(d+1,m^(1<<i)))%M;
    int j=n-k-d; FOR(i,0,k) if(m&(1<<i)) j++;
    if(j>=0) res=(res+solve(d+1,m)*j)%M;
    return dp[d][m]=res;
}

int main()
{
    cin>>n>>k;
    fac[0]=1; FOR(i,1,N) fac[i]=(i*fac[i-1])%M;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<'\n';
    return 0;
}