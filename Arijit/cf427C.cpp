#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

vector <int> adj [100005];
vector <int> cost (100005);
vector <int> scc_count (100005);

vector <int> low (100005);
vector <int> disc (100005);
bool visited[100005] = {false};
int n, m;

int t = 0;
long long int min_cost = 0;

stack <int> st;
int stackmember [100005] = {false};
long long int odd = 0;


void dfs( int vertex, int parent )
{
    disc[vertex] = t + 1;
    low[vertex] = t + 1;
    t++;
    visited[vertex] = true;
    int count = 0;
    st.push(vertex);
    stackmember[vertex] = true;

    for( int i = 0; i < adj[vertex].size(); i++ )
    {

        if( parent == -1)
            count++;

        int u = adj[vertex][i];
        
        if( stackmember[u] )
            low[vertex] = min(low[vertex], disc[u]);
        else if( !visited[u] )
        {
            dfs(u, vertex);
            low[vertex] = min(low[vertex], low[u]);
        }
    }

    if( low[vertex] == disc[vertex] )
    {
        int v;
        long long int count = INT_MAX;
        do
        {
            v = st.top();
            stackmember[v] = false;
            if( cost[v] < count )
            {
                count = cost[v];
                scc_count[odd] = 1;
            }
            else
                if( cost[v] == count )
                    scc_count[odd]++;

            st.pop();
        }
        while (vertex != v);
        odd++;
        min_cost += count;
    }

}

int main() 
{
    int a, b;
    cin>>n;

    for( int i = 1; i <= n; i++ )
        cin>>cost[i];
    
    cin>>m;
    for( int i = 1; i <= m; i++ )
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for( int i = 1; i <= n; i++ )
        if( !visited[i] )    
            dfs(i,-1);

    cout<<min_cost<<" ";

    long long int ans = 1;
    for( int i = 0; i < odd; i++ )
    { 
        ans *= scc_count[i];
        ans %= mod;
    }

    cout<<ans<<endl;
} 
