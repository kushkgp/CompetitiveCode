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

int main(){
	int t,C=1;
	cin >> t;
	while(t--){
		int n, K;
		cin >> n >> K;  
		vi inp(n,0);
		F1(i,0,n-1){
			cin >> inp[i];
		}
		vvi zero(n+1,vi(n+1,0));
		vvi ans(n+1,vi(n+1,inf));
		
		F1(i,0,n){
			zero[i][i] = 1;
		}
		F1(i,0,n-1){
			ans[i][i+1] = 1;
		}
		F1(i,0,n-2){
			ans[i][i+2] = 2;
		}

		F1(l,3,n){
			F1(i,0,n-3){
				int j = min(n,i+l) - 1;  //ith kth and jth elements in AP
				F1(k,i+1,j-1){
					if(inp[k]-inp[i]==inp[j]-inp[k] && inp[k]-inp[i]==K){
						if(zero[i+1][k] && zero[k+1][j])
							zero[i][j+1]=1;
					}
				}
				F1(k,i+3,j+1){
					if(zero[i][k] && zero[k][j+1])
						zero[i][j+1] = 1;
				}
			}
		}
		F1(l,3,n){
			F1(i,0,n-3){
				int j = min(n,i+l) - 1;
				F1(k,i+1,j){
					ans[i][j+1] = min(ans[i][j+1], ans[i][k] + ans[k][j+1]);
				}
				if(zero[i][j+1])
					ans[i][j+1] = 0;

			}
		}
		cout << "Case #" << C++ << ": " << ans[0][n] << endl;
	}
}