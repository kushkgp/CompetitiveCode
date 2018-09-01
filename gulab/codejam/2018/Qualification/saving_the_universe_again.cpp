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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int d;
		string p;
		cin>>d>>p;
		int tot = 0, gun = 1;
		vi no_c(p.length());
		F1(i, 0, p.length()-1){
			if(p[i]=='C')
				gun<<=1, no_c[i]++;
			else
				tot+=gun;
			no_c[i]+=i?no_c[i-1]:0;
		}
		int ans = 0;
		int last_index = p.length()-1;
		while(tot>d){
			int f = 1;
			F2(i, min(last_index,(int)p.length()-1), 1 && f){
				if(p[i-1]=='C' && p[i]=='S'){
					f = 0;
					p[i] = 'C', p[i-1] = 'S';
					tot -= 1<<(no_c[i]-1);
					no_c[i-1]--;
					last_index = i+1;
				}
			}
			if(f)
				break;
			ans++;
		}
		printf("Case #%d: %s\n", cnt++, tot>d?"IMPOSSIBLE":to_string(ans).c_str());
	}
}