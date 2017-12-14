#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

#define vs vector<set<int> >

#define pb push_back

int count_dfs(int crt, vvi &graph, vs &guesses, vi &visited){
    visited[crt]=1;
    int count = 0;
    for(int i=0;i<graph[crt].size();i++){
        int x = graph[crt][i];
        if(!visited[x]){
            if(guesses[crt].find(x)!=guesses[crt].end())
                count++;
            count += count_dfs(x,graph, guesses, visited);
        }
    }
    return count;
}

void ans_dfs(int crt, vvi &graph, vs &guesses, vi &visited, vi &answers){
    visited[crt] = 1;
    for(int i=0;i<graph[crt].size();i++){
        int x = graph[crt][i];
        if(!visited[x]){
            int cnt = 0;
            if(guesses[crt].find(x)!=guesses[crt].end())
                cnt -= 1;
            if(guesses[x].find(crt)!=guesses[x].end())
                cnt += 1;
            answers[x] = answers[crt] + cnt;
            ans_dfs(x,graph,guesses,visited,answers);
        }
    }
}

int gcd(int a, int b)
{
    if(a < b){
        int t = a;
        a = b;
        b = t;
    }
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vi visited(n+1,0);
        vvi graph(n+1);
        vs guesses(n+1);
        for(int a1 = 0; a1 < n-1; a1++){
            int u;
            int v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        int g;
        int k;
        cin >> g >> k;
        for(int a1 = 0; a1 < g; a1++){
            int u;
            int v;
            cin >> u >> v;
            guesses[u].insert(v);
        }
        vi answers(n+1,0);
        answers[1] = count_dfs(1, graph, guesses, visited);
        fill(visited.begin(), visited.end(),0);
        ans_dfs(1,graph, guesses, visited, answers);
        
        int s_cnt = 0;
        for(int i=1;i<=n;i++){
            if(answers[i]>=k)
                s_cnt++;
        }
        int gc = gcd(s_cnt,n);
        cout << s_cnt/gc << "/" << n/gc << endl;
    }
    return 0;
}
