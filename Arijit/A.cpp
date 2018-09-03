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

// long long int calc( long long int mid )
// {
// 	return ((ll)(mid*(mid+1))>>1);
// }

int main()
{
	long long int n;
	cin>>n;

	int count = 0;
	
	while(n > 0)
	{
		count++;
		n /= 2;
	}
	cout<<count<<endl;
	return 0;
}