#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MAXN 1000005

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

int TRIE [MAXN][10];
int isword[MAXN];
int nxt;

bool insert( string &s )
{
	int v = 0;
	for( int i = 0; i < s.size(); i++ )
	{
		if( isword[v] > 0 )
			return false;
		if( TRIE[v][s[i] - 'a'] == -1 )
			TRIE[v][s[i] - 'a'] = nxt++;
		v = TRIE[v][s[i]-'a'];

	}
	for(int i = 0; i < 10; i++ )
		if( TRIE[v][i] != -1 )
			return false;
	
	if( isword[v] > 0 )
		return false;
	isword[v]++;
	return true;
}

int main()
{
	memset(isword, 0, sizeof(isword));
	memset(TRIE, -1, sizeof(TRIE));
	// isword[0] = 1;
	nxt = 1;
	int n, q;
	string s;
	cin>>n;

	for( int i = 0; i < n; i++ )
	{
		cin>>s;
		if( !insert(s) )
		{
			cout<<"BAD SET"<<endl<<s<<endl;
			return 0;
		}
	}
	cout<<"GOOD SET"<<endl;
	return 0;
}