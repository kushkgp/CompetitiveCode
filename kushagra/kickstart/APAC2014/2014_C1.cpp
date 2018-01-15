#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

#define rep(i,n) for(int i=0;i<n;i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;

// int disclose_req(vvi &count, int i, int j, int n){
// 	if(i>0){
// 		if(j>0){
// 			count[i-1][j-1]++;
// 		}
// 		count[i-1][j]++;
// 		if(j<n-1){
// 			count[i-1][j+1]++;
// 		}
// 	}
// 	if(j>0){
// 		count[i][j-1]++;
// 		if(i<n-1){
// 			count[i+1][j-1]++;
// 		}
// 	}
// 	if(i<n-1){
// 		count[i+1][j]++;
// 		if(j<n-1){
// 			count[i+1][j+1]++;
// 		}
// 	}
// 	if(j<n-1){
// 		count[i][j+1]++;
// 	}
// 	return;
// }

void increment(vvi &count, int i, int j, int n){
	if(i>0){
		if(j>0)
			count[i-1][j-1]++;
		count[i-1][j]++;
		if(j<n-1)
			count[i-1][j+1]++;
	}
	if(j>0){
		count[i][j-1]++;
		if(i<n-1)
			count[i+1][j-1]++;
	}
	if(i<n-1){
		count[i+1][j]++;
		if(j<n-1)
			count[i+1][j+1]++;
	}
	if(j<n-1){
		count[i][j+1]++;
	}
	return;
}

int dfs(vvi &count, vvi &visited, int i, int j, int n){
	visited[i][j]=1;
	if(count[i][j] == 0){
		// cout << "yes" << endl;
		for(int p=-1;p<2;p++){
			for(int q=-1;q<2;q++){
				if(i+p>=0 && i+p<n && j+q>=0 && j+q<n){
					// cout << i+p << " " << j+q << endl;
					if(!visited[i+p][j+q]){
						// cout << i+p << " " << j+q << endl;
						dfs(count, visited, i+p, j+q, n);
					}
				}
			}
		}
	}
	return 1;
}
int dfs_util(vvi &count, vvi &visited, int n){
	int answer = 0;
	rep(i,n){
		rep(j,n){
			if(count[i][j]==0 && !visited[i][j]){
				// cout << i << " " << j << "------------\n";
				answer++;
				dfs(count, visited, i, j,n);
				// cout << i << " " << j << "------------\n";
			}

		}
	}
	rep(i,n){
		rep(j,n){
			if(count[i][j]>0 && !visited[i][j]){
				answer++;
				dfs(count, visited, i, j,n);
			}
		}
	}	
	return answer;
}
int main(){
	int t;
	cin >> t;
	int cnt = 1;
	while(t--){
		int n;
		cin >> n;
		char mine[300][300];
		vvi visited(n,vi(n));
		vvi count(n,vi(n));
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				count[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char c;
				cin >> mine[i][j];
				if(mine[i][j]=='*'){
					count[i][j] = -20;
					increment(count, i, j, n);
				}
			}
		}
		cout << "Case #" << cnt++ << ": " << dfs_util(count, visited,n) << endl;
	}
}