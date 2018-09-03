#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MAXN 100005

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

vi BIT (MAXN, 0 );
vi A (MAXN, 0 );
int n, a;

void update( int i, int k )
{
	for( ; k <= n; k += k & (-k) )
		BIT[k] += i; 
}

int query( int k )
{
	int ans = 0;
	for( ; k > 0 ; k -= k & (-k))
		ans += BIT[k];
	return ans;
}

int main()
{
	cin>>n; 
	for( int i = 1; i <= n; i++ )		
	{
		cin>>a;
		A[i] = a;
		update(a%2, i);
	}

	int q, t, l, r; 
	cin>>q;
	for( int i = 1; i <= q; i++ )
	{
		cin>>t>>l;

		if( t == 1 )
		{
			update(r%2 - A[l]%2, l);
			A[l] = r;
		}
		else
		{
			int u = query(r) - (( l > 1 )? query(l-1):0);

			int total = r - l + 1;

			if( t == 1 )
				cout<<total - u <<endl;
			else
				cout<<u<<endl;
		}
	}
	
	return 0;
}