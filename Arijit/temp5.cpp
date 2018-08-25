#include <bits/stdc++.h>

using namespace std;

vector <int> adj[16];
vector <int> low (16);
vector <int> disc (16);
bool visited[16] = {false};
int n, m;

int t = 0;
stack <int> st;
int stackmember [16] = {false};
int odd = 0, even = 0;

void dfs( int vertex, int parent )
{
    disc[vertex] = t + 1;
    low[vertex] = t + 1;
    t++;
    visited[vertex] = true;
    int count = 0;
    st.push(vertex);
    stackmember[vertex] = true;

    for( auto it = adj[vertex].begin(); it != adj[vertex].end(); it++)
    {
        if( parent == -1)
            count++;

        int u = (*it);
        
        if( stackmember[u] )
            low[vertex] = min(low[vertex], low[u]);
        else if( !visited[u] )
        {
            dfs(u, vertex);
            low[vertex] = min(low[vertex], low[u]);

            if( low[u] > disc[vertex] )
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
                while (u != v);
                if( count % 2 == 0 )
                    even += count;
                else
                    odd += count;
            }
        }
    }

    if( parent == - 1 )
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
    
        if( count % 2 == 0 )
            even += count;
        else
            odd += count;
    }

}

int main() 
{
    int a, b;
    cin>>n>>m;

    for( int i = 1; i <= m; i++ )
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for( int i = 1; i <= n; i++ )
        if( !visited[i] )    
            dfs(i,-1);

    cout<<odd-even<<endl;

}  
