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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, u;
		scanf("%d%d", &n, &u );

		vi arr (n+1, 0);
		int q;
		for( int i = 0; i < u; i++ )
		{
			int l, r, val;
			scanf("%d%d%d", &l, &r, &val );
			arr[l] += val;
			arr[r+1] -= val;
		}

		vi final( n+1,  0);
		int curr = 0;
		for( int i = 0; i < n; i++ )
		{
			curr += arr[i];
			final[i] = curr;
		}

		scanf("%d", &q);
		int a ;
		for( int i = 0; i < q; i++ )
		{
			scanf("%d", &a);
			printf("%d\n",final[a]);
		}
	}	
	return 0;
}