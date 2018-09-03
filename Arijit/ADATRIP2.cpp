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

int n, m, q, a, b, w;

int main()
{
	fastInput(n);
	fastInput(m);
	fastInput(q);

	vpi adj [n+2];
	int dist[n+2];
	bool id[n+2];
	pi res[n+2];

	for( int i = 0; i < m; i++ )
	{
		fastInput(a);
		fastInput(b);
		fastInput(w);
		
		if( a == b )
			continue;
		adj[a].pb(mp(b,w));
		adj[b].pb(mp(a,w));
	}

	memset( id, false, sizeof(id) );
	
	for( int i = 0; i < q; i++ )
	{
		fastInput(a);
		if( id[a] )
		{	
			printf("%d %d\n", res[a].ff, res[a].ss);
			continue;
		}

		for( int j = 0; j <= n; j++ )
			dist[j] = INF;

	    priority_queue<pair<int, int>> s;

		s.push(mp(0, a));
		dist[a] = 0;

		while( !s.empty() )
		{
			pi p = s.top();
			s.pop();

			if( p.ff > dist[p.ss] )
				continue;

			int u = p.ss;
			for( auto it = adj[u].begin(); it != adj[u].end(); it++ )
			{
				int v = (*it).ff, temp = (*it).ss;
				if( dist[v] > dist[u] + temp  )
				{
					dist[v] = dist[u] + temp;
					s.push(mp(dist[v], v));
				}
			}
		}

		int maxi = -1, count = 0;
		for( int j = 0; j < n; j++ )
		{
			if( dist[j] == INF )
				continue;
			if( maxi < dist[j] )
			{
				maxi = dist[j];
				count = 1;
			}
			else
				if( maxi == dist[j] )
					count++;
		}

		id[a] = true;
		res[a].ff = maxi , res[a].ss = count;
		printf("%d %d\n", res[a].ff, res[a].ss);
	}

	return 0;
}