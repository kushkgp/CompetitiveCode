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

void modify_array(vi & arr){
	int n = arr.size();
	int i=0,j=0;
	
	while(j<n-1&&i<n){
		int flag = 0;
		// while(arr[j++]==0){
		// 	if(j>=n){
		// 		flag = 1;
		// 		break;
		// 	}
		// }
		// if(flag)
		// 	break;
		// j--;
		// int t = arr[j];
		// arr[j++] = 0;
		// arr[i] = t;
		// flag = 0;
		// cout <<i << " " << arr[i] << endl;
		while(arr[++j]==0){
			if(j>=n-1){
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
		// cout << j << " " << arr[j] << endl;
		if(arr[i]==arr[j]){
			arr[i]<<=1;
			arr[j]=0;
		}
		else{
			if(arr[i]==0){
				arr[i] = arr[j];
				arr[j++] = 0;
			}
			else{
				int t=arr[j];
				arr[j]=0;
				arr[++i]=t;
			}
		}
		// cout << arr[0] << "--------------" <<endl;
	}
}

int main(){
	// vi a(6);
	// a[0] = 2;
	// a[1] = 2;
	// a[2] = 2;
	// a[3] = 0;
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