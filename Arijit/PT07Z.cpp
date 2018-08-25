#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m, a, b, w;

    cin>>n;

    vector <int> adj[n+5];

    for( int i = 0; i < n - 1; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector <int> level ( n+5 );
    vector <bool> visited ( n + 5, false );
    queue <int> Q;

    level[1] = 0;
    visited[1] = true;
    Q.push(1);

    while( !Q.empty() )
    {
        int p = Q.front();
        Q.pop();

        for( auto it = adj[p].begin(); it != adj[p].end(); it++ )
        {
            if( !visited[*it] )
            {
                Q.push(*it);
                visited[*it] = true;
                level[*it] = level[p] + 1;
            }
        }
    }

    int max_level = -1, target;
    for( int i = 1; i <= n; i++ )
    {
        if( max_level < level[i] )
        {
            max_level = level[i];
            target = i;
        }
    }

    level.assign(n+5, 0);
    visited.assign(n+5, false);
    level[target] = 0;
    visited[target] = true;
    Q.push(target);

    while( !Q.empty() )
    {
        int p = Q.front();
        Q.pop();

        for( auto it = adj[p].begin(); it != adj[p].end(); it++ )
        {
            if( !visited[*it] )
            {
                Q.push(*it);
                visited[*it] = true;
                level[*it] = level[p] + 1;
            }
        }
    }
    max_level = -1;
    for( int i = 1; i <= n; i++ )
        max_level = max(level[i], max_level);

    cout<<max_level<<endl;

}