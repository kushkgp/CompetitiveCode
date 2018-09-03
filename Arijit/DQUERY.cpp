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
		int a, b, k;
		cin>>n;

		vi last(1000005, -1), A(n+1,0); 
		for( int i = 1; i <= n; i++ )
			scanf("%d", &A[i]);

		cin>>k;	
		vi ans( k+1, 0 );	
		for( int i = 0; i < k; i++ )
		{
			scanf("%d%d", &a, &b);
			bri.pb(mp(a,mp(b,i)));
		}

		sort(bri.begin(), bri.end(), cmp );

		for(int i = 1, j = 0; i <= n; i++ )
		{
			if( last[A[i]] != - 1 )
				update(last[A[i]], -1 );

			update(i, 1);
			last[A[i]] = i;
			while( bri[j].ss.ff == i )
			{
				int l = bri[j].ff;
				ans[bri[j].ss.ss] = query(i) - query(l-1);
				j++;
			}
		} 

		for( int i = 0; i < k; i++ )
			printf("%d\n", ans[i]);
	}
	return 0;
}