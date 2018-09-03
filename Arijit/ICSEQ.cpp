#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MOD 5000000

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

long long int BIT[51][100005];

void update( int x, int y, int val )
{
	while( y < 100003 )
	{
		BIT[x][y] += val;
		BIT[x][y] %= MOD;
		y += y & (-y);
	}
}

ll query( int x, int y )
{
	long long int ans = 0;
	while( y > 0 )
	{
		ans += BIT[x][y];
		ans %= MOD;
		y -= y & (-y);
	}
	return ans;
}


int main()
{
	int n, k;
	cin>>n>>k;
	memset( BIT, 0, sizeof(BIT));
	int a;
	for( int i = 0; i < n; i++ )
	{
		cin>>a;
		a++;
		update(1, a, 1);

		for( int j = 2; j <= k ; j++ )
			update(j, a, query(j-1, a - 1));
	}

	cout<<query(k, 100002)<<endl;

	return 0;
}