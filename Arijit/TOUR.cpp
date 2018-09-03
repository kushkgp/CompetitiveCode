#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200005], radj[200005];
vector <int> vec[200005];
bool visited[200005] = {false};
vector <int> low (200005);
vector <int> disc (200005);
int stackmember [200005] = {false};
int scc_index [200005] = {0};

int t = 0;
long long int odd = 0;
int n, m;
stack <int> st;

void dfs( int vertex, int parent )
{
    disc[vertex] = low[vertex] = t + 1;
    t++;
    st.push(vertex);    
    visited[vertex] = stackmember[vertex] = true;

    for( int i = 0; i < adj[vertex].size(); i++ )
    {
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
            vec[odd].push_back(v);
            scc_index[v] = odd;
            st.pop();
        }
        while (vertex != v);
        odd++;
    }

}

void dfs1( int u )
{
    visited[u] = true;
    for( int i = 0; i < radj[u].size(); i++ )
        if( !visited[radj[u][i]] )
            dfs1(radj[u][i]);
}

int main() 
{
    int a, b, T;
    cin>>T;

    while(T--)
    {
        cin>>n;
        
        for( int i = 0; i <= n; i++ )
        {
            visited[i] = false;
            vec[i].clear();
            scc_index[i] = -1;
            stackmember[i] = false;
            adj[i].clear();
            radj[i].clear();
            low[i] = disc[i] = -1;
            odd = 0;
        }

        for( int i = 1; i <= n; i++ )
        {
            cin>>m;
            for( int j = 0; j < m; j++)
            {
                cin>>a;
                adj[i].push_back(a);
                radj[a].push_back(i);
            }
        }

        for( int i = 1; i <= n; i++ )
            if( !visited[i] )
                dfs(i, -1);

        int i, j;

        // vector <int> outdeg(odd, 0);

        // for( i = 0; i < odd; i++ )
        // {
        //     for( j = 0; j < vec[i].size(); j++ )
        //     {
        //         int u = vec[i][j];
        //         for( int k = 0; k < adj[u].size(); k++ )
        //             if( scc_index[adj[u][k]] != i )
        //                 outdeg[i]++;
        //     }
        // }
        // int first = 0, count = 0;

        // for( int i = 0; i < odd; i++ )
        //     if( outdeg[i] == 0 )
        //     {
        //         first = i;
        //         count++;
        //     }
        // if( count != 1 )
        //     cout<<"0"<<endl;
        // else
        //     cout<<vec[first].size()<<endl;

        if(vec[0].size()){
            for(int i = 1; i <= n; i++)
                visited[i] = 0;
            dfs1(vec[0][0]);
            int f = 1;
            for(int i = 1; i <= n; i++)
                if(!visited[i])
                    f = 0;

            if(f){
                cout<<vec[0].size()<<endl;
            }
            else
                cout<<0<<endl;
        }
        else
            cout<<0<<endl;
    }  
}  