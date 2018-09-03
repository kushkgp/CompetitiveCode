		#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF (1<<30)

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

int BIT [500005];
int n;
int query( int index )
{
	int ans = INF;
	while( index > 0 )
	{
		ans = min( ans, BIT[index]);
		index -= index & (-index);
	}
	return ans;
}

void update( int index, int val )
{
	while( index <= n)
	{
		BIT[index] = min( BIT[index], val );
		index += index & (-index);
	}
}

int main()
{
	int t = 1;
	// scanf("%d", &t);
	while(t--)
	{
		int a, b, c;
		scanf("%d", &n);
		vppi person (n);		
		
		int ans = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf("%d", &person[i].ff);
			BIT[i] = INF;
		}
		BIT[n] = INF;
		for( int i = 0; i < n; i++ )
			scanf("%d", &person[i].ss.ff);

		for( int i = 0; i < n; i++ )
			scanf("%d", &person[i].ss.ss);
		
		sort( person.begin(), person.end());

		for( int i = 0; i < n; i++ )
		{
			int curr = query(person[i].ss.ff);
			if( curr > person[i].ss.ss )
				ans++;

			update(person[i].ss.ff, person[i].ss.ss);
		}

		cout<<ans<<endl;
	}
	return 0;
}