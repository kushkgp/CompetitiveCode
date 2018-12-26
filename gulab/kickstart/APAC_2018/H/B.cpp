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

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007
#define print(test_case, ans) cout << "Case #" << test_case << ": " << ans << "\n"

using namespace std;
typedef unsigned long long int ll;
template <typename x> using v = vector<x>;
template <typename x> using vv = v<v<x> >;

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		ll m = 0;
		int k = ((n+1)>>1);
		ll sum = 0;
		F1(i, 0, n-1){
			sum+=(int)(s[i]-'0');
			if(i>=k)
				sum -= (int)(s[i-k]-'0');
			m = max(m, sum);
			// cout<<sum<<endl;
		}
		print(cnt++, m);
	}
}