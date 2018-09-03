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

vpi cow;
bool comp( pi a, pi b )
{
	if( a.ff != b.ff )
		return a.ff > b.ff;
	return a.ss < b.ss;
}
int main()
{
	int N, g, d;
	cin>>N;
	for( int i = 0 ; i < N; i++ )
	{
		cin>>g>>d;
		cow.pb(mp(g,d));
	}

	sort( cow.begin(), cow.end(), comp );

	int milk = 0;
	vector <bool>  TIME (N, false);

	for( int i = 0; i < N; i++)
	{
		for( int j = min(N,cow[i].ss)-1; j >= 0; j-- )
		{
			if( !TIME[j]  )
			{
				TIME[j] = true;
				milk += cow[i].ff;
				break;
			}
		}
	}

	cout<<milk<<endl;
	return 0;
}