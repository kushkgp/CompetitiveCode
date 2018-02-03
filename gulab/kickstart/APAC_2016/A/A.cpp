/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

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

int different(string & s){
	vi c(26,0);
	F1(i,0,s.length()-1)
		if(s[i]!=' ')
			c[s[i]-'A']++;
	int ans = 0;
	F1(i,0,25)
		if(c[i])
			ans++;
	return ans;
}

bool less_than(string & a, string & b){
	int ad = different(a), bd = different(b);
	if(ad>bd)
		return true;
	else if(ad<bd)
		return false;
	return a<b;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		string a,b;
		int n;
		cin>>n;
		getline(cin, a);
		getline(cin, a);
		F1(i,1,n-1){
			getline(cin, b);
			if(less_than(b,a))
				swap(a,b);
		}
		printf("Case #%d: ", cnt++);
		cout<<a<<endl;
	}
}