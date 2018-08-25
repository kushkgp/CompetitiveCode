#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, m, a, b, w;
    cin>>N>>m;
    
    vector <pair<int,int> > adj [N+5];
    vector <bool> visited (N+5, false);
    vector <int> dist (N+5, INT_MAX);
    for( int i = 0; i < m; i++ )
    {
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
    }
    
    priority_queue < pair<int, int>, vector <pair<int, int> >, greater< pair<int, int> > > pq;
    
    pq.push(make_pair(0,1));
    dist[1] = 0;
    pair <int, int> P;
    while(!pq.empty())
    {
        P = pq.top();
        pq.pop();
        
        int v = P.second;

        if( visited[v] )
            continue;
        visited[v] = true;
        
        for( int i = 0; i < adj[v].size(); i++ )
        {
            if( dist[v] + adj[v][i].second < dist[adj[v][i].first] )
            {
                dist[adj[v][i].first] = dist[v] + adj[v][i].second;
                pq.push(make_pair( dist[adj[v][i].first], adj[v][i].first ) );
            }
        }
    }
    
    for( int i = 2; i <= N; i++ )
        cout<<dist[i]<<" ";
    cout<<endl;
}