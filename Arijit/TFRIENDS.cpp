#include <bits/stdc++.h>

using namespace std;

vector <int> low (105);
vector <int> disc (105);
bool visited[105] = {false};
int n, m;

int t = 0;
stack <int> st;
int stackmember [105] = {false};
int odd = 0;

int adj[105][105];

void dfs( int vertex, int parent )
{
    disc[vertex] = t + 1;
    low[vertex] = t + 1;
    t++;
    visited[vertex] = true;
    int count = 0;
    st.push(vertex);
    stackmember[vertex] = true;

    for( int i = 1; i <= n; i++ )
    {
        if( adj[vertex][i] != 1 )
            continue;

        if( parent == -1)
            count++;

        int u = i;
        
        if( stackmember[u] )
            low[vertex] = min(low[vertex], disc[u]);
        else if( !visited[u] )
        {
            dfs(u, vertex);
            low[vertex] = min(low[vertex], low[u]);

            // if( low[u] > disc[vertex] )
            // {
            //     int v;
            //     int count = 0;
            //     do
            //     {
            //         v = st.top();
            //         stackmember[v] = false;
            //         count++;
            //         st.pop();
            //     }
            //     while (u != v);
            //     odd++;
            // }
        }
    }

    if( low[vertex] == disc[vertex] )
    {
        int v;
        int count = 0;
        do
        {
            v = st.top();
            stackmember[v] = false;
            count++;
            st.pop();
        }
        while (vertex != v);
        odd++;
    }

}

int main() 
{
    char a;
    int T;
    cin>>T;
    while(T--)
    {
        odd = 0;
        for( int i = 0; i < 105; i++ )
        {
            low[i] = disc[i] = 0;
            visited[i] = stackmember[i] = false;
        }

        cin>>n;

        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                cin>>a;
                if( a == 'N' )
                    adj[i][j] = 0;
                else
                    adj[i][j] = 1;
            }
        }

        for( int i = 1; i <= n; i++ )
            if( !visited[i] )    
                dfs(i,-1);

        cout<<odd<<endl;
    }
}  
