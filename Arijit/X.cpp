
#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int> >
#define mp make_pair
#define chk(a)	cout<<#a<<" : "<<a<<"\n";
#define chk2(a,b) cout<<#a<<" : "<<a<<", "<<#b<<" : "<<b<<"\n";
#define chk3(a,b,c) cout<<#a<<" : "<<a<<", "<<#b<<" : "<<b<<", "<<#c<<" : "<<c<<"\n";
#define chk4(a,b,c,d) cout<<#a<<" : "<<a<<", "<<#b<<" : "<<b<<", "<<#c<<" : "<<c<<", "<<#d<<" : "<<d<<"\n";
#define M 1000000007
#define F first
#define S second
using namespace std;
int n;

ll cap[5009][5009];
ll flow[5009][5009];
int d[5009];
vector<int> gph[5009];
int q[5009];
bool bfs()
{
    int u=1;
    memset(d,-1,sizeof(d));

    d[1]=0;
    int sx,ex;
    sx=0;ex=-1;
    q[++ex]=1;
    while(sx<=ex and sx!=-1)
    {
        u=q[sx++];
        for(int i=0;i<gph[u].size();i++)
        {
            int to=gph[u][i];
            if(d[to]==-1 and cap[u][to]-flow[u][to]>0)
            {
                d[to]=d[u]+1;
                q[++ex]=to;
            }
        }
    }
    return (d[n]!=-1);
}

ll dfs(int u,ll fl)
{
    if(u==n)
        return fl;
    for(int i=0;i<gph[u].size();i++)
    {
        int to=gph[u][i];
        if(cap[u][to]-flow[u][to]>0 and d[to]==d[u]+1)
        {
            fl=min(fl,cap[u][to]-flow[u][to]);
            int df=dfs(to,fl);
            if(df>0)
            {
                
                flow[u][to]+=df;
                flow[to][u]-=df;
                return df;
            }
        }
    }
    return 0;
}
int main()
{
    int m,i,u,v,c;
    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        if(cap[u][v])
        {
            cap[u][v]+=c;
            cap[v][u]+=c;
        }
        else if(u!=v)
        {
            gph[u].push_back(v);
            gph[v].push_back(u);
            cap[u][v]+=c;
            cap[v][u]+=c;
        }
    }
    ll ans=0;
        while(bfs())
        {
            for( int i = 1 ; i <= n; i++ )
                cout<<d[i]<<" ";
            cout<<endl;
            while(true)
            {
                int df=dfs(1,1e15);

                if(df==0)
                    break;
                ans+=df;
            }
        }
        printf("%lld\n",ans);
        return 0;
}
