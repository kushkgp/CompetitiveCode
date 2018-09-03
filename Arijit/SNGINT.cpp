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
		int n;
		cin>>n;
		vi count(11, 0);
		if( n==0 )
		{
			cout<<"0"<<endl;
			continue;
		}

		for( int i = 9; i > 1; i-- )
		{
			while( n % i == 0 )
			{
				n /= i;
				count[i]++;
			}
		}

		string  s = "";
		// cout<<n<<endl;
		for( int i = 2; i <= 9 ; i++ )
		{
			while(count[i] != 0 )
			{
				count[i]--;
				s += to_string(i);
			}
		}

		if( n != 1 )
			cout<<"-1"<<endl;
		else
			cout<<s<<endl;
	}	
	return 0;
}