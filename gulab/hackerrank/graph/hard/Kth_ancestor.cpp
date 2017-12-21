/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define N 100001
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int t[N];
int p[N][20];

void preprocess(){
	for(int j = 0; j < 20; j++)
		for(int i = 0; i < N; i++)
			p[i][j] = j?p[p[i][j-1]][j-1]:t[i];
}

void set_parents(int i){
	for (int j = 0; j < 20; ++j)
		p[i][j] = j?p[p[i][j-1]][j-1]:t[i];
}

int find(int i, int k){
	for(int x = 0; k; x++){
		if(k&(1<<x)){
			i = p[i][x];
			k = k&(~(1<<x));
		}
	}
	return i;
}

int main(){
	BOOST;
	int tmp;
	cin>>tmp;
	while(tmp--){
		fill(t,t+N,0);
		int p,q;
		cin>>p;
		for(int i = 0; i < p; i++){
			int u,v;
			cin>>u>>v;
			t[u] = v;
		}
		preprocess();
		cin>>q;
		while(q--){
			int f;
			cin>>f;
			int x,y,k;
			if(f==0){
				cin>>y>>x;
				t[x] = y;
				set_parents(x);
			}
			else if(f==1){
				cin>>x;
				t[x] = 0;
				set_parents(x);
			}
			else{
				cin>>x>>k;
				cout<<find(x,k)<<endl;
			}
		}
	}
}