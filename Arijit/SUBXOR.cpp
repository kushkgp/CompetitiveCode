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

int TRIE [MAXN][2];
long long int isword[MAXN];
int nxt;

void ins( string &s )
{
	int v = 0;
	for( int i = 0; i < s.size(); i++ )
	{
		if( TRIE[v][s[i] - '0'] == -1 )
			TRIE[v][s[i] - '0'] = nxt++;
		isword[v]++;
		v = TRIE[v][s[i] - '0'];
	}
	isword[v]++;
}

string bin( int a )
{
	string k = "";
	while( a )
	{
		k += to_string(a%2);
		a /= 2;
	}
	int u = k.length();
	for( int i = 0; i < 17 - u; i++ )
		k += "0";
	reverse(k.begin(), k.end() );
	return k;
}

long long int query( string &k, string &prefix )
{	
	int v = 0;
	long long int ans = 0, p, q;
	for( int i = 0; i < 17; i++ )
	{
		q = k[i] - '0';
		p = prefix[i] - '0';
		// cout<<q<<" "<<p<<endl;
		if( q > 0 )
		{
			if( p == 0 )
			{
				if( TRIE[v][0] != -1 )
					ans += isword[TRIE[v][0]];
				if( TRIE[v][1] != -1 )
					v = TRIE[v][1];
				else
					return ans;
			}
			else
			{
				if( TRIE[v][1] != -1 )
					ans += isword[TRIE[v][1]];
				if( TRIE[v][0] != -1 )
					v = TRIE[v][0];
				else
					return ans;
			}
		}
		else
		{
			if( p == 0 )
			{
				if( TRIE[v][0] != -1 )
					v = TRIE[v][0];
				else
					return ans;
			}
			else
			{
				if( TRIE[v][1] != -1 )
					v = TRIE[v][1];
				else
					return ans;
			}
		}
	}
	// ans += isword[v];
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, a, k;
		cin>>n>>k;
		memset(isword, 0, sizeof(isword));
		memset(TRIE, -1, sizeof(TRIE));
		isword[0] = 1;
		nxt = 1;
		string s;
		string u = bin(0);
		ins(u);
		int pre = 0; 
		long long int ans = 0;
		string k1 = bin(k);
		for( int i = 0; i < n; i++ )
		{
			scanf("%d", &a);
			pre ^= a;
			string u = bin(pre);
			ans += query( k1, u );
			ins(u);
		}
		cout<<ans<<endl;
	}
	return 0;
}