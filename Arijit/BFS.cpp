#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, a, b;
    cin>>N;
    
    vector <int> adj [N+5];
    
    for( int i = 1; i < N; i++ )
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector <int> level (N+5, 0);
    vector <bool> visited(N+5, false);
    
    queue <int> Q;
    Q.push(1);
    level[1] = 1;
    visited[1] = true;
    
    while( !Q.empty() )
    {
        int x = Q.front();
        Q.pop();
        for( int i = 0; i < adj[x].size(); i++ )
        {
            if( visited[adj[x][i]] == false )
            {
                visited[adj[x][i]] = true;
                level[adj[x][i]] = level[x] + 1;
                Q.push(adj[x][i]);
            }
        }
    }
    
    int M, count = 0;
    cin>>M;
    
    for( int i = 0; i < N; i++ )
        cout<<level[i]<<" ";// if( level[i] == M )
        //     count++;
            
    cout<<count<<endl;
}