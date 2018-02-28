/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

void dfs(vector<string> &inp, vi &visited, int r, int c, int index){
	visited[index] = 1;
	int i = index/c;
	int j = index%c;
	if(i>0 && !visited[index-c] && inp[i-1][j]=='1')
		dfs(inp, visited, r, c, index-c);
	if(i<r-1 && !visited[index+c] && inp[i+1][j]=='1')
		dfs(inp, visited, r, c, index+c);
	if(j>0 && !visited[index-1] && inp[i][j-1]=='1')
		dfs(inp, visited, r, c, index-1);
	if(j<c-1 && !visited[index+1] && inp[i][j+1]=='1')
		dfs(inp, visited, r, c, index+1);
}

int dfs_util(vector<string> &inp, int r, int c){
	vi visited(r*c, 0);
	int answer = 0;
	F1(i,0,r-1){
		F1(j,0,c-1){
			int index = i*c+j;
			if(!visited[index] && inp[i][j]=='1'){
				answer++;
				dfs(inp, visited, r, c, index);
			}
		}
	}
	return answer;
}

int main(){
	int t,C=1;
	cin >> t;
	// cout << endl;
	while(t--){
		int r,c;
		cin >> r >> c;
		vector<string> inp(r);
		cout << "Case #"<<C++ << ":" << endl;
		F1(i,0,r-1){
			cin >> inp[i];
		}
		int q;
		cin >> q;
		F1(i,0,q-1){
			char op;
			cin >> op;
			if(op=='Q')
				cout << dfs_util(inp, r, c) << endl;
			else{
				int i,j;
				char k;
				cin >> i >> j >> k;
				inp[i][j] = k;
			}
		}
	}
}