#include <bits/stdc++.h>
// #include
using namespace std;

#define mod 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vp ;
typedef vector<vp> vvp;

int main(){
	int t;
	cin >> t;
	double ans[2][200001];
	int cnt = 1;

	while(t--){
		
		int B,L,N;
		cin >> B >> L >> N;
		int crt = 0;
		ans[crt][1] = B*750;
		int id = 0;
		for(int l=1;l<L;l++){
			crt++;
			crt=crt%2;
			id = 0;
			for(int r=1;r<=l+1;r++){
				for(int i=0;i<r;i++){
						id++;
						ans[crt][id] = 0;
				}
			}
			id = 0;
			for(int r=1;r<=l;r++){
				for(int i=0;i<r;i++){
					id++;
					int x = id;
					int y = id + r;
					int z = id + r + 1;
					double left = ans[(crt+1)%2][id] - 250;
					if(left>0){
						ans[crt][x] += left/3;
						ans[crt][y] += left/3;
						ans[crt][z] += left/3;
					}
				}
			}
		}
		std::cout << std::fixed;
		cout << "Case #" << cnt << ": " << setprecision(7) << min(ans[crt][N],250.0) << endl;
		cnt++;
	}
}