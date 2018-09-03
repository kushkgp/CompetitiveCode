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
	int n;
	cin>>n;
	string a, b;
	cin>>a>>b;
	int i = 0;
	int cost = 0;
	while( i < n )
	{
		if( a[i] == b[i] )
			i++;
		else
			if( i < n - 1 && a[i+1] != b[i+1] && a[i] != a[i+1] )
			{
				cost += 1;
				swap(a[i], a[i+1]);
				i += 2;
			}
			else
			{
				a[i] = b[i];
				i++;
				cost += 1;
			}
	}
	cout<<cost<<endl;
	return 0;
}