#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
typedef pair <int, int> pii;
typedef vector <pii> vpii;
typedef vector <int> vi;

int edgesum = 0, dia = 0, n, k;

int go( int child, int parent, vpii adj[], vi &necessity, vi &req )
{
	int d1 = INT_MIN, d2 = INT_MIN;

	for( int i = 0; i < adj[child].size(); i++ )
	{
		int neigh = adj[child][i].ff;
		int cost = adj[child][i].ss;

		if( neigh == parent )
			continue;

		int tempdia = go( neigh, child, adj, necessity, req );
		necessity[child] += necessity[neigh];

		if( necessity[neigh] != 0 && necessity[neigh] != k )
			edgesum += cost;

		d2 = max( tempdia + cost, d2 );
		if( d1 < d2 )
			swap(d1, d2);
	}

	if( d2 > 0 )
		dia = max(dia, d1 + d2 );
	if( dia > 0 && req[child] )
		dia = max(dia, d1 );
	if( req[child] )
		d1 = max(d1, 0 );
	return d1;

}

int main()
{
	cin>>n>>k;

	vpii adj [n+1];

	vi necessity (n+1, 0);
	vi req (n+1, 0);
	int a, b, w;

	for( int i = 0; i < k; i++ )
	{
		cin>>a;
		necessity[a] = req[a] = 1;
	}
	for( int i = 0; i < n - 1; i++ )
	{
		cin>>a>>b>>w;
		adj[a].push_back(mp(b,w));
		adj[b].push_back(mp(a,w));
	}

	int u = go(1, 1, adj, necessity, req ); 
	cout<<2*edgesum - dia<<endl;
}