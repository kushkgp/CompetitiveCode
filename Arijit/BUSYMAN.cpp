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

bool cmp( pi a, pi b )
{
	return a.ss < b.ss;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, a, b;
		cin>>n;
		vpi act;

		for( int i = 0; i < n; i++ )
		{
			cin>>a>>b;
			act.pb(mp(a,b));
		}

		sort( act.begin(), act.end(), cmp );

		int last = act[0].ss, count = 1;

		for( int i = 1; i < n; i++ )
		{
			if( last <= act[i].ff )
			{
				count++;
				last = act[i].ss;
			}
		}
		cout<<count<<endl;
	}	
	return 0;
}