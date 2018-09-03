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

int main(){
	int C = 1;
	int t; cin >> t;

	while (t--) {
		int n,l;
		cin >> n >> l;
		vector<string> words(n,"");
		F1(i,0,n-1){
			cin >> words[i];
		}
		if(l<2){
			cout << "Case #" << C++ << ": -"  << endl;
			continue;
		}
		int done = 0;
		vector<char> ans;
		int ans_index = -1;
		F1(ind,0,l-2){
			vvi prst(26,vi(26,0));
			vi fst(26,0);
			vi scd(26,0);
			F1(i,0,n-1){
				fst[words[i][ind]-'A'] = 1;
				scd[words[i][ind+1]-'A'] = 1;
				prst[words[i][ind] - 'A'][words[i][ind+1] - 'A'] = 1;
			}

			int frst_cnt = 0;
			F1(i,0,25){
				frst_cnt += fst[i];
			}
			F1(j,0,25){
				int cnt = 0;
				F1(i,0,25){
					cnt+=prst[i][j];
				}
				if(cnt>0 && cnt!=frst_cnt){
					F1(i,0,25){
						if(!prst[i][j] && fst[i] && scd[j]){
							ans.pb('A'+i);
							ans.pb('A'+j);
							break;
						}
					}
					done = 1;
					break;
				}
				if(done)
					break;
			}
			if(done){
				ans_index = ind;
				break;
			}
		}
		// cout <<" -----===--=" << words[0] <<"-0-=--==-=" << endl;

		if(ans_index==-1){
			cout << "Case #" << C++ << ": -"  << endl;
			continue;
		}

		words[0][ans_index] = ans[0];
		words[0][ans_index+1] = ans[1];

		cout << "Case #" << C++ << ": " << words[0] << endl;
	}

	return 0;
}