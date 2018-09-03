#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

bool visited [1000005];
int level [1000005];

int main()
{
	int f, s, g, u, d;
	cin>>f>>s>>g>>u>>d;

	for( int i = 0; i <= f; i++ )
	{
		level[i] = -1;
		visited[i] = false;
	}

	queue <int> q;
	q.push(s);
	level[s] = 0;
	visited[s] = true;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		if( u + v <= f && !visited[u+v] )
		{
			q.push(u+v);
			visited[u+v] = true;
			level[u+v] = level[v] + 1;
		}
		
		if( v - d >= 1 && !visited[v-d] )
		{
			q.push(v-d);
			visited[v-d] = true;
			level[v-d] = level[v] + 1;
		}
	}

	if( level[g] == - 1)
		cout<<"use the stairs"<<endl;
	else
	cout<<level[g]<<endl;	
}