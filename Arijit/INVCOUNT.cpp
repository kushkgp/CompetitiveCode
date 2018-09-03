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

int BIT [200005];
int n;
int query (int index )
{
	int sum = 0;

	while( index > 0 )
	{
		sum += BIT[index];
		index -= index & (-index);
	}
	return sum;
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
	int t;
	cin>>t;

	while(t--)
	{
		int a;
		cin>>n;

		for( int i = 0; i <= n; i++ )
			BIT[i] = 0;

		vi A (n, 0), B (n, 0);

		for( int i = 0; i < n; i++ )
		{
			cin>>a;
			A[i] = B[i] = a;
		}

		sort( B.begin(), B.end() );

		for( int i = 0; i < n; i++ )
		{
			int idx = (int)(lower_bound( B.begin(), B.end(), A[i] ) - B.begin() );
			A[i] = idx + 1;
		}
		long long int invcount = 0;
		for( int i = n - 1; i >= 0; i-- )
		{
			int x = query( A[i] - 1 );
			invcount += x;
			update(A[i], 1 );
		}

		cout<<invcount<<endl;
	}
	return 0;
}