#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m, a, b, w;

    cin>>n>>m;

    vector <int> adj[n+5];

    for( int i = 0; i < n - 1; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector <bool> visited ( n + 5, false );
    
    for( int i = 1; i <= n; i++ )
    {
        if( visited[i] )
            continue;

        stack <int> Q;

        Q.push(i);

        while( !Q.empty() )
        {
            int p = Q.top();
            Q.pop();

            if( visited[p] )
                continue;
            visited[p] = true;

            int count = 0;
            for( auto it = adj[p].begin(); it != adj[p].end(); it++ )
            {
                if( !visited[*it] )
                    Q.push(*it);
                else
                    count++;
            }

            if( count > 1 )
            {
                cout<<"NO"<<endl;
                return 0;
            }

        }
        
    }

    cout<<"YES"<<endl;
}