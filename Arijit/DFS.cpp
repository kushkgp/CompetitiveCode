#include <bits/stdc++.h>

using namespace std;

vector <int> adj [100005];    
vector <bool> visited(100005, false);
    
 void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }

int main()
{
    int N, M, a, b;
    cin>>N>>M;
    
    
    for( int i = 0; i < M; i++ )
    {
        cin>>a>>b;   
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int head;
    cin>>head;
    dfs(head);
    // stack <int> Q;
    // Q.push(head);
    // visited[head] = true;
    
    // while( !Q.empty() )
    // {
    //     int x = Q.top();
    //     Q.pop();
    //     if( !visited[x] )
    //         visited[x] = true;

    //     for( int i = 0; i < adj[x].size(); i++ )
    //     {
    //         if( visited[adj[x][i]] == false )
    //             Q.push(adj[x][i]);
    //     }
    // }
    
    int count = 0;
    
    for( int i = 1; i <= N; i++ )
        if( visited[i] == false )
            count++;
            
    cout<<count<<endl;
}