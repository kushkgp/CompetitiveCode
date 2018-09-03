#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MOD 5000000

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

long long int BIT[51][10005];
long long int dp[51][10005];

void update( int x, int y, int val )
{
	while( y < 10003 )
	{
		BIT[x][y] += val;
		BIT[x][y] %= MOD;
		y += y & (-y);
	}
}

ll query( int x, int y )
{
	long long int ans = 0;
	while( y > 0 )
	{
		ans += BIT[x][y];
		ans %= MOD;
		y -= y & (-y);
	}
	return ans;
}


int main()
{
	int n, k;
	cin>>n>>k;
	memset( BIT, 0, sizeof(BIT));
	memset( dp, 0, sizeof(dp));

	int a;
	vi Array (n,0), Barray(n,0);

	for( int i = 0; i < n; i++ )
	{
		cin>>a;
		Array[i] = Barray[i] = a;
	}

	sort(Barray.begin(), Barray.end());

	for( int i = 0 ; i < n; i++ )
	{
		int x = (int)(lower_bound(Barray.begin(), Barray.end(), Array[i]) - Barray.begin());
		Array[i] = x + 1;
	}

	vector <bool> vis (n+1, false);

	for( int i = 0; i < n; i++ )
	{
		a = Array[i];
		for( int j = 1; j <= k ; j++ )
		{
			int currentSum = ((j > 1 ? query(j - 1, a - 1) : 1) - dp[j][a] + MOD) % MOD;
            update(j, a, currentSum);
            dp[j][a] = (dp[j][a] + currentSum) % MOD;
		}
	}

	cout<<query(k, 10002)<<endl;

	return 0;
}