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

void point_update(vi &arr, int x, int val){
	int n = arr.size();
	for(int i=x;i<=n;i+=(i&(-i)))
		arr[i]+=val;
	return;
}

int range_query(vi &arr, int a){
	int ans=0;
	for(int i=a;i>0;i-=(i&(-i)))
		ans+=arr[i];
	return ans;
}

int main(){
	int t;
	cin >> t;
	int cnt=1;
	while(t--){
		int n;
		cin >> n;

		vi bit(5000,0);

		for(int i=0;i<n;i++){
			int a,b;
			cin >> a >> b;
			point_update(bit, a, 1);
			point_update(bit, b+1, -1);
		}
		// for(int i=0;i<n;i++){
		// 	cout << bit[i] << " ";
		// }
		// cout << endl;
		int p;
		cin >> p;
		cout << "Case #" << cnt++ << ":";
		for(int i=0;i<p;i++){
			int a;
			cin >> a;
			cout << " " << range_query(bit,a); 
		}
		cout << endl;
	}
}