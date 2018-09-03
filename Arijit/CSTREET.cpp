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

int id[300000];

vppi E;

int find( int i )
{
	while( id[i] != i )
	{
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}

void uni( int i , int j )
{
	id[find(i)] = id[find(j)];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p, n, m;
		cin>>p>>n>>m;
		int a, b, w;
		for( int i = 1; i <= n; i++ )
			id[i] = i;
		for( int i = 0; i < m; i++ )
		{
			cin>>a>>b>>w;
			E.pb(mp(w,mp(a,b)));
		}

		sort(E.begin(), E.end());
		int cost = 0;
		for( int i = 0; i < E.size(); i++ )
		{
			if( find(E[i].ss.ff) != find(E[i].ss.ss ) )
			{	
				uni( E[i].ss.ff, E[i].ss.ss ); 
				cost += E[i].ff;
			}
		}

		cout<<p*cost<<endl;
	}
	return 0;
}