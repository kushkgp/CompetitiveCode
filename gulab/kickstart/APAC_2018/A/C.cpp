/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
// #define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
const int mod =  1000000007;

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

ll tmkc[30];
int give_hash(vi &f) {
	int H = 0;
	F1(i, 0, 25) {
		H = (H + tmkc[i] * f[i]) % mod;
	}
	return H;
}

inline void Add(int &H, int x) {
	H = (H + tmkc[x]) % mod;
}
inline void Remove(int &H, int x) {
	H = (H - tmkc[x] + mod) % mod;
}


int main(){
	tmkc[0] = 1;
	F1(i, 1, 28) {
		tmkc[i] = (tmkc[i - 1] * 37) % mod;
	}
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int l;
		cin>>l;
		vpii dict(l);
		vvi dictm(l,vi(26,0));
		vi strsize(l,0);
		string s;

		F1(i,0,l-1){
			cin>>s;
			strsize[i] = s.length();
			dict[i].ff = s[0]-'a';
			dict[i].ss = s[s.length()-1]-'a'; 
			F1(j,0,(int)s.length()-1){
				dictm[i][s[j]-'a']++;
			}
		}
		// cout<<"hi"<<endl;
		char s1,s2;
		cin>>s1>>s2;
		ll n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		vvi str(n,vi(26,0));
		str[0][s1-'a']++;
		str[1][s1-'a']++;
		str[1][s2-'a']++;
		int c1,c2;
		c1 = s2;
		c2 = s1;
		s = s1;
		s+= s2;
		F1(i,2,n-1){
			int x = (a*c1+b*c2+c)%d;
			str[i][x%26]++;
			c2 = c1;
			c1 = x;
			F1(j,0,25)
				str[i][j]+=str[i-1][j];
			s+=(char)(x%26+'a'); 
		}
		// cout<<endl;
		// cout<<s<<endl;
		// return 0;

		vi id(l); iota(all(id), 0);
		sort(all(id), [&](int x, int y) {
			return strsize[x] < strsize[y];
		});
		int yes =0 ;
		F1(i, 0, l - 1) {
			int j = i;
			while (j + 1 < l and strsize[id[j + 1]] == strsize[id[i]]) ++j;
			map<pair<int, pii>, int> mp;
			F1(it, i, j) {
				mp[{give_hash(dictm[id[it]]), dict[id[it]]}]++;
			}
			int len = strsize[id[i]];
			int H = 0;
			F1(it, 0, len - 1) {
				Add(H, s[it] - 'a');
			}
			F1(itt, 0, n - len) {
				if (itt != 0) {
					Add(H, s[itt + len - 1] - 'a');
				}
				if (itt) {
					Remove(H, s[itt - 1] - 'a');
				}
				auto it = mp.find(make_pair(H, pii(s[itt] - 'a', s[itt + len - 1] - 'a')));
				if (it != mp.end()) {
					// cout << it->second;
					yes += it->second;
					mp.erase(it);
				}
			}
			// for(auto itt : mp){
			// 	auto it = itt.first;
			// 	cout<<it.first << " " << it.second.first << " " << it.second.second << " " <<endl;
			// }
			i = j;
		}
		
		printf("Case #%d: %d\n", cnt++, yes);

	}
}