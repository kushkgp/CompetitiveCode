#include <bits/stdc++.h>

using namespace std;

vector <int> adj[10005];
bool visited[10005] = {false};
int stackin[10005] = {false};
int n, m;
stack <int> st;

bool fail = false;
int cunt = 0;

void dfs( int vertex, int count)
{
    visited[vertex] = true;
    stackin[vertex] = count;

    for( auto it = adj[vertex].begin(); it != adj[vertex].end(); it++ )
        if( !visited[*it] )
            dfs(*it, count);
        else
            if( stackin[*it]==count )
                fail = true;

    st.push(vertex);
    cunt++;
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


    for(int i=1;i<=n;i++)
    {
        sort(adj[i].rbegin(),adj[i].rend());
    }


    for( int i = n; i >= 1; i-- )
    {
        if( !visited[i] )    
            dfs(i, i);
    }

    if( fail || cunt < n )
    {
        cout<<"Sandro fails."<<endl;
        return 0 ;
    }

    while( !st.empty() )
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}  
