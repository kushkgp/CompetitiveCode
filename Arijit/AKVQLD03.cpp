#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

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

long long int BIT [	1000005 ];
int n , q;

ll query ( int index )
{
	if( index == 0 )
		return 0;
	
	ll ans = 0;
	while( index > 0 )
	{
		ans += BIT[index];
		index -= index & (-index);
	}
	return ans;
}

void update( int index, int val )
{
	while( index <= n )
	{
		BIT[index] += val;
		index += index & (-index);
	}
}

int main()
{
	cin>>n>>q;

	string s;
	int a, b;
	for( int i = 0 ; i < q; i++ )
	{
		cin>>s>>a>>b;

		if( s == "add")
			update(a, b);
		else
			cout<<query(b) - query(a-1)<<endl;
	}
	return 0;
}