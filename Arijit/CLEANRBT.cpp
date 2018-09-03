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
typedef set<pi> spi;
typedef set<ppi> sppi;

int dist[50][50][35000];
char maze[50][50];
int clean[50][50];

vpi places;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main()
{
	while(1)
	{
		int n, m;
		cin>>m>>n;
		if( n == 0 || m == 0 )
			return 0;

		pi start;
		places.clear();

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
			{
				cin>>maze[i][j];
				if( maze[i][j] == '*' )
					places.pb(mp(i,j));
				else
					if( maze[i][j] == 'o' )
					{
						start.ff = i;
						start.ss = j;
					}
			}

		for( int i = 0; i <= n; i++ )
			for( int j = 0; j <= m; j++ )
				for( int k = 0; k <= 2048; k++ )
					dist[i][j][k] = INT_MAX;

		memset( clean, 0, sizeof(clean) );
		
		for( int i = 0; i < places.size(); i++ )
			clean[places[i].ff][places[i].ss] = (1 << i);

		set <pppi> Q;
		Q.insert(mp(0, mp( clean[start.ff][start.ss], start) ) );
		int UZ = clean[start.ff][start.ss];
		dist[start.ff][start.ss][clean[start.ff][start.ss]] = 0;

		while( !Q.empty() )
		{
			pppi u = *Q.begin();
			Q.erase(Q.begin());

			int u_dis = u.ff, u_x = u.ss.ss.ff, u_y = u.ss.ss.ss, u_clean = u.ss.ff;

			for( int i = 0; i < 4; i++ )
			{
				int v_x = u_x + dx[i], v_y = u_y + dy[i];
				if( v_x < 0 || v_y < 0 || v_x >= n || v_y >= m ) 
					continue;
				if ( maze[v_x][v_y] == 'x' )
					continue;

				if( dist[v_x][v_y][ u_clean | clean[v_x][v_y] ] > dist[u_x][u_y][u_clean] + 1 )
				{
					dist[v_x][v_y][ u_clean | clean[v_x][v_y] ] = dist[u_x][u_y][u_clean] + 1;
					Q.insert(mp(dist[v_x][v_y][ u_clean | clean[v_x][v_y]], mp(u_clean | clean[v_x][v_y], mp(v_x, v_y))));
				}
			}
		}

		int FINAL = pow(2, places.size()) - 1, ans = INT_MAX;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				ans = min( ans, dist[i][j][FINAL]);

		if( ans != INT_MAX )
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
	}
}