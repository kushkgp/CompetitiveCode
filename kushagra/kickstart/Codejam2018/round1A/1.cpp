/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define min3(a,b,c) (min(min(a,b),c))
#define max3(a,b,c) (max(max(a,b),c))
#define mod 1000000007
#define inf INT_MAX

#define F2(x,y,z) for(int x = y; x >= z; x--)
#define F1(x,y,z) for(int x = y; x <= z; x++)
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define ss second
#define ff first
#define mp make_pair
#define pb push_back

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;

int check(vi &row, int k, vi &cuts){
	int n = row.size();
	int sum = 0;
	F1(i,0,n-1){
		sum += row[i];
	}
	if(sum%k!=0)
		return 0;
	int req_sum = sum/k;
	int crt_sum=0;
	int cut_cnt = 1;
	F1(i,0,n-1){
		crt_sum+=row[i];
		if(crt_sum==req_sum){
			crt_sum=0; 
			if(cut_cnt>k)
				return 0;
			cuts[cut_cnt++]=i;
		}
		if(crt_sum>req_sum)
			return 0;
	}
	return cut_cnt==k+1;
}

int main(){
	int C = 1;
	int t; cin >> t;
	while (t--) {
		cout << "Case #" << C++ << ": ";
		int r,c,h,v;
		cin >> r >> c >> h >> v;
		vvi adj(r,vi(c,0));
		string inp;
		F1(i,0,r-1){
			cin >> inp;
			F1(j,0,c-1){
				if(inp[j] == '@')
					adj[i][j] = 1;
			}
		}
		vi rowsum(r,0);
		vi colsum(c,0);
		int total_sum = 0;
		F1(i,0,r-1){
			int crt_sum=0;
			F1(j,0,c-1){
				crt_sum += adj[i][j];
			}
			rowsum[i] = crt_sum;
			total_sum += rowsum[i];
		}
		F1(i,0,r-1){
			F1(j,0,c-1){
				colsum[j] += adj[i][j];
			}
		}
		int ans = 1;
		int req_sum = total_sum/((h+1)*(v+1));
		// cout << total_sum << endl;
		vi cuth(h+2,-1);
		vi cutv(v+2,-1);
		if(total_sum==0){
			cout << "POSSIBLE" << endl;
			continue;
		}
		if(check(colsum,v+1,cutv) && check(rowsum, h+1, cuth) && total_sum%((h+1)*(v+1))==0){
			// cout << "okok" << endl;
			F1(a,0,h){
				F1(b,0,v){
					int r1 = cuth[a];
					int r2 = cuth[a+1];
					int c1 = cutv[b];
					int c2 = cutv[b+1];
					int crt_sum = 0;
					// cout << r1 << " " << r2 << " " << c1 << " " << c2 << endl;
					F1(i,r1+1,r2){
						F1(j,c1+1,c2){
							crt_sum += adj[i][j];
						}
					}
					if(crt_sum!=req_sum){
						ans = 0;
						break;
					}
				}
				if(ans == 0)
					break;
			}
		}
		else
			ans = 0;
		cout << (ans==1?"POSSIBLE":"IMPOSSIBLE") << endl;
	}	

	return 0;
}