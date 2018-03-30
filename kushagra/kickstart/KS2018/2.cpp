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


int power[26];
ll crt = 41;
for(int i=0,i<=25;i++){
	power[i] = crt;
	crt*=41;
	crt%=mod;
}

void add(int &ans, int x){
	ans += power[x];
	ans %= mod;
}

void remove(int &ans, int x){
	ans -= power[x];
	ans += mod;
	ans %= mod;
}

int hash(vi &freq){
	int ans = 0;
	F1(i,0,25){
		ans += ((ll)power[i]*freq[i])%mod;
	}
}


int main(){
	int C = 1;
	int t; scanf("%d", &t);
	while (t--) {
		int l;
		cin >> l;
		vi len(l);
		vpii wd_pr(l);
		vvi opt(l,vi(26,0));
		F1(i,0,l-1){
			string crt;
			cin >> crt;
			wd_pr[i].ff = crt[0]-'a';
			wd_pr[i].ss = crt[crt.length()-1]-'a';
			len[i] = crt.length();
			F1(j,0,crt.length()-1){
				opt[i][int(crt[j])-97]++;
			}
		}
		ll n,a,b,c,d;
		char s1, s2;
		cin >> s1 >> s2 >> n >> a >> b >> c >> d;

		vector<ll> str(n);
		vvi cum_freq(n,vi(26,0));
		str[0] = s1;
		str[1] = s2;
		cum_freq[0][s1-'a']++;
		cum_freq[1][s1-'a']++;
		cum_freq[1][s2-'a']++;

		F1(i,2,n-1){
			str[i] = (a*str[i-1] + b*str[i-2] + c)%d;
			F1(j,0,25){
				cum_freq[i][j] = cum_freq[i-1][j];
			}
			cum_freq[i][str[i]%26]++;
		}
		str[0] = s1-'a';
		str[1] = s2-'a';

		cout << endl;
		int ans = 0;
		F1(k,0,l-1){
			int cl = len[k];
			F1(i,0,n-cl){
				if((str[i])%26 == wd_pr[k].ff ){
					if((str[i+cl-1])%26==wd_pr[k].ss){
						int yes=1;
						F1(c,0,25){
							if(cum_freq[i+cl-1][c]-(i>0?cum_freq[i-1][c]:0) != opt[k][c]){
								yes=0;
								break;
							}
						}
						if(yes==1){
							ans++;
							break;
						}
					}
				}
			}
		}

		cout << "Case #" << C++ <<": " << ans << endl;

	}
}