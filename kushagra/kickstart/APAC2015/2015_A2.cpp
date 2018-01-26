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
typedef vector<double> vd;

void point_update(vd &arr, int x, int val){
	int n = arr.size();
	for(int i=x;i<=n;i+=(i&(-i))){
		arr[i]*=pow(1.0*val, (double)1.0/(i&(-i)));
	}
}

double prefix_query(vd &arr, int a){
	double ans = 1.0;
	for(int i=a;i>0;i-=(i&(-i))){
		ans*=pow(arr[i], (double)(i&(-i))/(1.0*a));
	}
	return ans;
}

double range_query(vd &arr, int a, int b){
	double ans = 1.0;
	int cnt = b-a+1;
	ans *= pow(prefix_query(arr, b),(double)b/(1.0*cnt));
	ans /= pow(prefix_query(arr, a-1),(double)(a-1)/(1.0*cnt));
	return ans;
}

int main(){
	int t;
	cin >> t;
	int cnt= 1;
	while(t--){
		int n,m;
		cin >> n >> m;
		vd bit(n+1,1.0);
		for(int i=1;i<=n;i++){
			int k;
			cin >> k;
			point_update(bit, i, k);
		}
		cout << "Case #"<<cnt++<<":"<<endl;
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			a++;b++;
			cout << fixed << setprecision(10) << range_query(bit, a,b) << endl;
		}
	}
}