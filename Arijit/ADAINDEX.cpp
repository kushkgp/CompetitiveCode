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

int TRIE [MAXN][26];
int isword[MAXN];
int nxt;

void insert( string &s )
{
	int v = 0;
	for( int i = 0; i < s.size(); i++ )
	{
		if( TRIE[v][s[i] - 'a'] == -1 )
			TRIE[v][s[i] - 'a'] = nxt++;
		isword[v]++;
		v = TRIE[v][s[i]-'a'];
	}
	isword[v]++;
}

int search( string &s )
{
	int v = 0;
	for( int i = 0; i < s.size(); i++ )
	{
		if( TRIE[v][s[i] - 'a'] == -1 )
			return false;
		v = TRIE[v][s[i]-'a'];
	}
	return isword[v];
}

int main()
{
	memset(isword, 0, sizeof(isword));
	memset(TRIE, -1, sizeof(TRIE));
	isword[0] = 1;
	nxt = 1;
	int n, q;
	string s;
	cin>>n>>q;

	for( int i = 0; i < n; i++ )
	{
		cin>>s;
		insert(s);
	}

	for( int i = 0; i < q; i++ )
	{
		cin>>s;
		printf("%d\n", search(s));
	}
	
	return 0;
}