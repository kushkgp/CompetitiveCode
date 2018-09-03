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

long long int BIT [	500005 ];
int n , p;

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
	cin>>n>>p;
	memset( BIT, 0, sizeof(BIT));
	vector <long long int> A( n+1, 0 ), B (n, 0);
	int a, b;
	for( int i = 1 ; i <= n; i++ )
	{
		cin>>a;
		A[i] = B[i-1] = a;
	}

	sort( B.begin(), B.end() );

	for( int i = 1; i <= n; i++ )
	{
		b = (int)(lower_bound( B.begin(), B.end(), A[i]) - B.begin());
		A[i] = b + 1;
	}

	long long int invcount = 0, maxinv = -1, index = -1;
	for( int i = 1; i <= n; i++ )
	{
		if ( i > p )
		{
			invcount -= query(A[i-p] - 1);
			update(A[i-p], -1);
		}

		update(A[i],1);
		invcount += min(i,p) - query(A[i]);

		if( invcount > maxinv )
		{
			maxinv = invcount;
			index = i-p+1;
		}
	}
	cout<<index<<" "<<maxinv<<endl;
	return 0;
}