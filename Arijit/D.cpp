#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

multiset < int > adj[200005];

int n , cnt = 0 , check = 0 , order[200005];
queue < int > q;
bool vis[200005];
int p[200005];

void bfs(int u)
{
    q.push(u);
    vis[u] = 1;
    cnt = 1;

    while( !q.empty() )
    {
        u = q.front();
        q.pop();

        // if(cnt >= n)
        	// return;
        for(auto A : adj[u])
        {
            if(A == p[u])
            	continue;
            // if(cnt >= n)
            	// return;
            int v = order[cnt];
            if( adj[u].find( v ) != adj[u].end() )
            {
                if(vis[v])
                {
                    check = 1;
                    return;
                }
                cnt++;
                vis[v] = 1;
                p[v] = u;
                q.push(v);
            }
            else
            {
                check = 1;
                return;
            }
        }
    }
}

int main()
{
    scanf("%d" , &n);
    int u , v;
    for(int i = 1 ; i < n ; i ++)
    {
        scanf("%d %d" , &u , &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i = 0 ; i < n ; i ++)
    	cin>>order[i];

    if(order[0] != 1)
    	check = 1;
    else 
    	bfs( order[0] );

    if(check)
        printf("No\n");
    else 
    	printf("Yes\n");
}
