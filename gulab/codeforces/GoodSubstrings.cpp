#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;

// very good trick, store two hashes
pair<int, int> p;

int main(){
	string s, c;
	cin>>s>>c;
	int k; 
	cin>>k;
	vector<pair<int, int> > v;
	for(int i = 0; i < s.length(); i++){
		ll h1 = 0, h2 = 0;
		ll p1 = 29, p2 = 31;
		int cnt = 0;
		for(int j = i; j < s.length(); j++){
			if(c[s[j]-'a']=='0')
				cnt++;
			if(cnt>k)
				break;
			// s[j]-'a'+1 as otherwise ba and b will get same hashes as contribution of a will be 0
			h1+=(p1*(s[j]-'a'+1))%mod;
			h2+=(p2*(s[j]-'a'+1))%mod;
			h1%=mod, h2%=mod;
			p1*=29,	p2*=31;
			p1%=mod, p2%=mod;
			v.pb(mp(h1, h2));
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	cout<<v.size()<<endl;
	return 0;
}