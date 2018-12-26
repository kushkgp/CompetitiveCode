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
typedef long long int ll;
template <typename x> using v = vector<x>;
template <typename x> using vv = v<v<x> >;


int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		v<ll> a(n);
		v<ll> b(n);
		int l = 0, r = n-1;
		F1(i, 0, n-1){
			cin>>a[i];
			if(a[i]>0)
				b[l++] = a[i];
			else
				b[r--] = a[i];
		}
		a = b;
		sort(a.begin(), a.begin()+l);
		unordered_map<ll, ll> ans;
		ll result = 0;
		F1(i, 0, n-1){
			result += ans[a[i]];
			F1(j, 0, i-1){
				ans[a[i]*a[j]]++;
			}
		}
		print(cnt++, result);
	}
}