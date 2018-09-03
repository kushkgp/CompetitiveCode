#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF (1<<30)
#define MAXN 500005

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

int n, m, q, a, b, w;

template <class T> void fastInput(T &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {
        
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

list <int> Q [10*MAXN];
pair <int, list <int>::iterator> dist[MAXN];
unordered_map <int, int> adj [MAXN];

int main()
{
	fastInput(n);
	fastInput(m);
	fastInput(q);

	for( int i = 0; i < m; i++ )
	{
		fastInput(a);
		fastInput(b);
		fastInput(w);
		
		if( adj[a].find(b) != adj[a].end() )
		{
			adj[a][b] = min(adj[a][b], w );
			adj[b][a] = min(adj[b][a], w );
		}
		else
		{
			adj[a][b] = w;
			adj[b][a] = w;
		}
	}

	for( int i = 0; i < q; i++ )
	{
		fastInput(a);

		for( int j = 0; j <= n; j++ )
			dist[j].ff = INF;

		dist[a].ff = 0;
		int idx = 0;
		Q[0].pb(a);

		while( 1 )
		{
			while (Q[idx].empty() && idx < 10*n)
            	idx++;

            if( idx == 10*n )
            	break;

			int u = Q[idx].front();
			Q[idx].pop_front();

			for( auto it = adj[u].begin(); it != adj[u].end(); it++ )
			{
				int v = it->first, temp = it->second;
				if( dist[v].ff > dist[u].ff + temp  )
				{
					if( dist[v].ff != INF )
						Q[dist[v].ff].erase(dist[v].ss);
					dist[v].ff = dist[u].ff + temp;
					Q[idx].pb(v);
					dist[v].ss = Q[idx].end();
				}
			}
		}

		int maxi = -1, count = 0;
		for( int j = 0; j < n; j++ )
		{
			if( dist[j].ff == INF )
				continue;
			if( maxi < dist[j].ff )
			{
				maxi = dist[j].ff;
				count = 1;
			}
			else
				if( maxi == dist[j].ff )
					count++;
		}

		cout<<maxi<<" "<<count<<endl;
	}

	return 0;
}