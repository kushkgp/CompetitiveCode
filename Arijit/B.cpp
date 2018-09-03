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
	int n, s, a;
	cin>>n>>s;
	vi less, grt;
	int cnt = 0;
	for( int i = 0; i < n; i++ )
	{
		cin>>a;
		if ( a > s )
			grt.pb(a);
		else
			if( a < s )
				less.pb(a);
			else
				cnt++;
	}

	int median = (n+1)/2;

	if( less.size() < median && less.size() + cnt >= median )
	{
		cout<<0<<endl;
		return 0;
	}
	else
		if( grt.size() < median && grt.size() + cnt >= median )
		{
			cout<<0<<endl;
			return 0;
		}

	long long int ans = 0;
	if( less.size() >= median )
	{
		int tot = less.size() - median + 1;
		sort(less.begin(), less.end());

		for( int i = less.size() - 1; tot > 0 ; i--, tot-- )
			ans += abs(s - less[i]);
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		int tot = grt.size() - median + 1;

		sort(grt.begin(), grt.end());
		for( int i = 0; tot > 0 ; i++, tot-- )
			ans += abs(s - grt[i]);
		cout<<ans<<endl;
	}
	return 0;
}