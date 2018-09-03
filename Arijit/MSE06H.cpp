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

long long int BIT [	1005 ];
int n , m, k;

bool cmp( pi a, pi b )
{
	if( a.ff != b.ff )
		return a.ff < b.ff;
	return a.ss < b.ss;
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
	while( index <= m )
	{
		BIT[index] += val;
		index += index & (-index);
	}
}

int main()
{
	int t;
	cin>>t;
	int count = 1;
	while(t--)
	{
		memset(BIT, 0, sizeof(BIT));
		vpi bri;
		int a, b;
		cin>>n>>m>>k;

		for( int i = 0; i < k; i++ )
		{
			cin>>a>>b;
			bri.pb(mp(a,b));
		}
		sort(bri.begin(), bri.end(), cmp );
		
		long long int cross = 0;

		for( int i = 0 ; i < k; i++ )
		{
			cross += i - query(bri[i].ss);
			update(bri[i].ss, 1);
		}

		cout<<"Test case "<<count++<<": "<<cross<<endl;
	}
	return 0;
}