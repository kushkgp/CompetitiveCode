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

long long int BIT [	100005 ];
int n , m, k;

bool cmp( ppi a, ppi b )
{
	if( a.ff != b.ff )
		return a.ff < b.ff;
	return a.ss.ff < b.ss.ff;
}

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
	while( index <= 100005 )
	{
		BIT[index] += val;
		index += index & (-index);
	}
}

int main()
{
	int t = 1;
	while(t--)
	{
		memset(BIT, 0, sizeof(BIT));
		vppi bri;
		int a, b;
		cin>>n;

		for( int i = 0; i < n; i++ )
		{
			cin>>a>>b;
			bri.pb(mp(a,mp(b,i)));
		}

		sort(bri.begin(), bri.end(), cmp );
		vi ans(n,0);
		for( int i = 0 ; i < n; i++ )
		{
			if( i > 0 && bri[i].ff == bri[i-1].ff && bri[i].ss.ff == bri[i-1].ss.ff )
			{
				ans[bri[i].ss.ss] = ans[bri[i-1].ss.ss];
				update(bri[i].ss.ff,1);
				continue;
			}
			
			ans[bri[i].ss.ss] = query(bri[i].ss.ff);
			update(bri[i].ss.ff, 1);
		}

		for( int i = 0; i < n; i++ )
			cout<<ans[i]<<endl;
	}
	return 0;
}