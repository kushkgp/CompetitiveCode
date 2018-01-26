#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

int dp[2001][2001][2];

int rec(int one, int two, int ban)
{
    if(one==0 && two==0)
        return 1;
    int& ret=dp[one][two][ban];
    if(ret!=-1)
        return ret;
    ret=0;
    if(one>0)
        ret=(ret+1LL*rec(one-1, two, 0)*(one-ban))%MOD;
    if(two>0)
        ret=(ret+1LL*rec(one+1, two-1, 1)*two)%MOD;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int N;
        scanf("%d", &N);
        map<int, int> m;
        for(int i=0; i<N; i++)
        {
            int a;
            scanf("%d", &a);
            m[a]++;
        }
        int one=0, two=0;
        for(auto& it: m)
        {
            if(it.second==1)
                one++;
            else
                two++;
        }
        printf("%d\n", rec(one, two, 0));
    }
    return 0;
}