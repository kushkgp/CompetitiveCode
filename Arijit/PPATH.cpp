#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

bool sieve[10005];
int level [10005];
vector <int> adj [10005];
vector <int> prime;

bool hd( int i , int j )
{
	int flag = true;	
	int count = 0;

	while( i != 0 || j != 0 )
	{
		if( (i % 10) != (j % 10) )
			count++;
		i = i / 10;
		j = j / 10;
	}

	if( count > 1 )
		flag = false;

	return flag;
}

int main()
{
	int T;
	cin>>T;
	sieve[0] = sieve[1] = false;
	memset( sieve, true, sizeof(sieve) );
	for( int i = 2; i < 10000; i++ )
	{
		if( sieve[i] )
			for( int j = 2; j*i < 10000; j++ )
				sieve[j*i] = false;
	}

	for( int i = 1000; i < 10000; i++ )
		if( sieve[i])
			prime.pb(i);

	for( int i = 0; i < prime.size(); i++ )
	{
		for( int j = i + 1;  j < prime.size(); j++ )
		{
			if( hd(prime[i],prime[j]) )
			{
				adj[prime[i]].pb(prime[j]);
				adj[prime[j]].pb(prime[i]);
			}
		}
	}

	while(T--)
	{
		int n, m;
		cin>>n>>m;

		if( n == m )
		{
			cout<<"0"<<endl;
			continue;
		}
		memset( level, -1, sizeof(level) );
		queue <int> Q;
		Q.push(n);
		level[n] = 0;

		int brake = 1;
		while( !Q.empty() && brake == 1 )
		{
			int v = Q.front();
			Q.pop();

			for( int i = 0; i < adj[v].size(); i++ )
			{
				int u = adj[v][i];
				if( level[u] == - 1 )
				{
					level[u] = level[v] + 1;
					Q.push(u);
					if( u == m )
					{
						brake = 0;
						break;
					}
				}
			}
		}

		cout<<level[m]<<endl;
	}
}