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
	int T;
	cin>>T;
	int tust = 1;
	while(T--)
	{
		int N, K;
		cin>>N>>K;
		vi vec (N, 0);
		int a;
		for( int i = 0; i < N; i++ )
		{
			cin>>a;
			if( a > N )
				vec[N]++;
			else
				vec[a]++;
		}
		
		int j = 0, count = 0;
		for( int i = 1; i < N; i++ )
			vec[i] += vec[i-1];

		for( int i = 0; i < N; i++ )
		{
			if( vec[i] > i*K )
			{
				int temp = vec[i] - i*K - count;
				if ( temp > 0 )
					count += temp;
			}
		}

		cout<<"Case #"<<tust++<<": "<<N-count<<endl;
	}	
	return 0;
}