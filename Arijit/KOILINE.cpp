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

int BIT [100005];
int n;
int query( int index )
{
	if( index == 0 )
		return 0;

	int ans = 0;
	while( index > 0 )
	{
		ans = ans + BIT[index];
		index -= index & (-index);
	}
	return ans;
}

void update( int index, int val )
{
	while( index <= n)
	{
		BIT[index] = BIT[index] + val;
		index += index & (-index);
	}
}

int bin( int l, int r, int req )
{
	if( l >= r )
		return l;
	int mid = (l+r)>>1;
	int left = query(mid) - query(l-1);
	int right = query(r) - query(mid);
	int ans;
	if( req > left )
		ans = bin( mid + 1, r, req - left );
	else
		ans = bin( l, mid, req );
	return ans;
}

int main()
{
	int t = 1;
	while(t--)
	{
	 	scanf("%d",&n);
	 	for( int i = 1; i <= n; i++ )
	 		update(i,1);
	 	int curr = 0, free = 0, req;

	 	vi ans(n+1,0), in(n+1), help(n+1);

	 	for( int i = 1; i <= n; i++ )
	 		scanf("%d", &help[i]);

	 	for( int i = 1; i <= n; i++ )
	 		scanf("%d", &in[i]);

	 	sort( help.begin(), help.end() );
	 	for( int i = n; i >= 1; i-- )
	 	{
	 		ans[i] = bin(1, n, in[i] + 1);
	 		update( ans[i], -1 );
	 	}

	 	for( int i = 1; i <= n; i++ )
	 		printf("%d ", help[ans[i]]);
	 	printf("\n");
	}
}