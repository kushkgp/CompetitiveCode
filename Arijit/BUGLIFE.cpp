#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin>>t;
    int count = 1;
    while(t--)
    {
        printf("Scenario #%d:\n", count++);
        int n, m, a, b, w;
        cin>>n>>m;

        vector <int> adj[n+5];

        for( int i = 0; i < m; i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector <bool> visited ( n + 5, false );
        vector <int> color ( n + 5, -1 );
        
        int flag = 0;

        for( int i = 1; i <= n; i++ )
        {
            if( visited[i] )
                continue;

            queue <int> Q;
            color[i] = 0;
            visited[i] = true;
            Q.push(i);


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
                        color[*it] = 1 - color[p];
                    }
                    else
                        if( color[p] == color[*it] )
                            flag = 1;
                }
            }
        }

        if(flag)
            cout<<"Suspicious bugs found!"<<endl;
        else
            cout<<"No suspicious bugs found!"<<endl;
    }
}