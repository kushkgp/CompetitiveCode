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
		int n, k;
		cin>>n>>k;

		vi arr (n+5, 0);
		vi prefix (n+5, 0);
		for( int i = 1; i <= n; i++ )
			cin>>arr[i];

		for( int i = 1; i <= n; i++ )
		{
			prefix[i] = prefix[i-1];
			if( arr[i] == 0 )
				prefix[i]++;
		}

		// cout<<"HAAAHA"<<endl;
		// for( int i = 1; i <= n; i++ )
		// 	cout<<prefix[i]<<" ";
		// cout<<"HAAAHA"<<endl;

		int i = 0, j = 1;
		int ans = 0;
		while( j < n )
		{
			if( prefix[j] - prefix[i] <= k )
				j++;
			else
				i++;

			if( prefix[j] - prefix[i] <= k )
			{
				ans = max(ans, j - i );
			}
		}

		cout<<ans<<endl;
	}	
	return 0;
}