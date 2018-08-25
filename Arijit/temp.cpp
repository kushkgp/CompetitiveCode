#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int> >
#define mp make_pair

using namespace std;
int n;

ll cap[5009][5009];
ll flow[5009][5009];
int level[5009];
vector<int> adj[5009];
vector <int> ptr;
int q[5009];
bool bfs()
{
    int u=1;
    memset(level,-1,sizeof(level));
    ptr.assign(n+1, 0);

    level[1]=0;
    int sx,ex;
    sx=0;ex=-1;
    q[++ex]=1;
    while(sx<=ex and sx!=-1)
    {
        u=q[sx++];
        for(int i=0;i<adj[u].size();i++)
        {
            int to=adj[u][i];
            if(level[to]==-1 and cap[u][to]-flow[u][to]>0)
            {
                level[to]=level[u]+1;
                q[++ex]=to;
            }
        }
    }
    return (level[n]!=-1);
}

ll dfs( int u, ll fl )
{
    if( u == n )
        return fl;

    for( ; ptr[u] < adj[u].size(); ++ptr[u] )
    {
        int v = adj[u][ptr[u]];
        if( level[v] == level[u] + 1 && cap[u][v] > flow[u][v] )
        {
            int newflow = min(fl, (long long int )cap[u][v] - flow[u][v]);
            if( newflow > 0 )
            {
                flow[u][v] += newflow;
                flow[v][u] -= newflow;
                return newflow;
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
            adj[u].push_back(v);
            adj[v].push_back(u);
            cap[u][v]+=c;
            cap[v][u]+=c;
        }
    }
    ll ans=0;
        while(bfs())
        {
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
