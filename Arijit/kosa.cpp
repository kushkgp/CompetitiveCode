#include <bits/stdc++.h>

using namespace std;

vector <int> adj[16];
vector <int> adj2[16];
bool visited[16] = {false};
bool visited2[16] = {false};

int n, m;

stack <int> st;
int odd = 0, even = 0;

void dfs( int vertex )
{
    visited[vertex] = true;

    for( auto it = adj[vertex].begin(); it != adj[vertex].end(); it++)
    {
        if( !visited[*it] )
            dfs(*it);
    }

    st.push(vertex);

}

void dfs2( int vertex, int* count )
{
    visited2[vertex] = true;
    count++;

    for( auto it = adj2[vertex].begin(); it != adj2[vertex].end(); it++)
    {
        if( !visited2[*it] )
            dfs(*it);
    }
    
    st.push(vertex);
}

int main() 
{
    int a, b;
    cin>>n>>m;

    for( int i = 1; i <= m; i++ )
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    for( int i = 1; i <= n; i++ )
        if( !visited[i] )    
        {
            dfs(i);
            while(!st.empty())
            {
                int u = st.top();
                st.pop();
                int* count = 0;
                if( !visited2[u] )
                    dfs2(u, count);
                if( *count > 0 )
                {
                    if( *count % 2 == 0 )
                        even += *count;
                    else
                        odd += *count;
                }
            }
        }

    cout<<odd<<" "<<even<<endl;
}  
