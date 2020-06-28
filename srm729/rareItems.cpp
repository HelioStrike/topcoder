#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 20
#define ld long double
using namespace std;

int n;
ld a[N],dp[1<<N],tot;

int main()
{
    cin>>n;
    FOR(i,0,n) cin>>a[i],tot+=a[i];
    FOR(i,0,n) a[i]/=tot;
    FOR(i,1,1<<n)
    {
        ld s1=0,s2=0;
        FOR(j,0,n)
        {
            if(i&(1<<j)) s1+=a[j]*dp[i^(1<<j)];
            else s2+=a[j];
        }
        dp[i]=(1+s1)/(1-s2);
    }
    cout<<setprecision(18)<<dp[(1<<n)-1]<<'\n';
    return 0;
}