#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007

typedef long long int ll;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;
typedef pair <ll, ll > pl;
typedef vector <pl> vpl;

int A[1005][1005];
vpi cities;
int n, p, a, b;

double distance( pi a, pi b )
{
	return (ceil)(p*sqrt((double)(a.ff - b.ff)*(a.ff - b.ff) + (double)(a.ss - b.ss)*(a.ss - b.ss)));
}

int main()
{
	int T;
	cin>>T;
	int cunt = 1;
	while(T--)
	{
		cin>>n>>p;
		cities.clear();
		for( int i = 0 ; i < n; i++ )
		{
			cin>>a>>b;
			cities.pb(mp(a,b));
		}

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				A[i+1][j+1] = distance(cities[i], cities[j]);

		// for( int i = 1; i <= n; i++ )
		// {	for( int j = 1; j <= n; j++ )
		// 		cout<<A[i][j]<<" ";
		// 	cout<<endl;
		// }

		long long int cost = 0;
		vector <bool> visited (n+1, false);
		vector <long long int> dist (n+1, INT_MAX);
		vi parent (n+1, INT_MAX);
		priority_queue < pl, vpl, greater<pl>> q;
		q.push(mp(0, 1));
		dist[1] = 0;
		parent[1] = -1;

		while( !q.empty() )
		{
			pi p = q.top();
			q.pop();

			if( visited[p.ss] )
				continue;
			visited[p.ss] = true;
			cost += p.ff;
			cost %= MOD;
			int u = p.ss;
			for( int i = 1; i <= n; i++ )
			{
				if( !visited[i] && A[u][i] < dist[i] )
				{
					dist[i] = A[u][i];
					dist[i] %= MOD;
					parent[i] = u;
					q.push(mp(dist[i], i));
				}
			}			
		}

		printf("Scenario #%d: %d\n",cunt++, (int)ceil(cost) );
	}
	return 0;
}