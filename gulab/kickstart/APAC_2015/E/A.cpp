/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int count(string & s, int i){
	vi c(26,0);
	c[s[i]-'a']=1;
	if(i-1>=0)
		c[s[i-1]-'a']=1;
	if(i+1<s.length())
		c[s[i+1]-'a']=1;
	int ans = 0;
	F1(j,0,25)
		ans+=c[j];
	return ans;
}

int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll ans = 1;
		F1(i,0,(s.length()-1)){
			ans*=count(s,i);
			ans%=MOD;
		}
		printf("Case #%d: %lld\n", cnt++, ans);
	}
}