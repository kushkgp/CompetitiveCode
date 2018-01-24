#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;


int find_next_nonzero(vi &arr, int s){
	int n = arr.size();
	while(s<n){
		if(arr[s]!=0)
			return s;
		s++;
	}
	return -1;
}
void modify_array(vi & arr){
	int n = arr.size();
	int i=0,j=0;
	int crt = 1;
	int flag = 1;
	while(crt<n){
		// if(flag){
		// 	crt = find_next_nonzero(arr, crt);
		// 	i = crt;
		// 	crt++;
		// }
		crt = find_next_nonzero(arr,crt);
		if(crt<0)
			break;
		j = crt;
		crt++;
		// cout << i << " " << j << endl;
		if(arr[i]==arr[j]){
			arr[i]<<=1;
			arr[j] = 0;
		}
		else{
			if(arr[i]==0){
				int t = arr[j];
				arr[j] = 0;
				arr[i] = t;
				i--;
			}
			else{
				int t = arr[j];
				arr[j] = 0;
				arr[i+1] = t;
			}
		}
		i++;
	}
}

int main(){
	// vi a(6);
	// a[0] = 2;
	// a[1] = 2;
	// a[2] = 2;
	// a[3] = 2;
	// a[4] = 0;
	// a[5] = 0;
	// modify_array(a);
	// cout << a[0] << a[1] << a[2] << a[3] << a[4] <<a[5] << endl;
	int t;
	cin >> t;
	int cnt= 1;
	while(t--){
		int n;
		cin >> n;
		vvi adj(n,vi(n,0));
		string dir;
		cin >> dir;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int crt;
				cin >> crt;
				if(dir=="right" || dir=="left")
					adj[i][j] = crt;
				else
					adj[j][i] = crt;
			}
		}
		for(int i=0;i<n;i++){
			if(dir=="right" || dir=="down")
				reverse(adj[i].begin(),adj[i].end());
			modify_array(adj[i]);
			if(dir=="right" || dir=="down")
				reverse(adj[i].begin(),adj[i].end());
		}
		if(!(dir=="right" || dir=="left")){
			for(int i=0;i<n;i++){
				for(int j=0;j<i;j++){
					int temp = adj[i][j];
					adj[i][j] = adj[j][i];
					adj[j][i] = temp;
				}
			}
		}
		cout << "Case #"<<cnt++<<":"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}
}