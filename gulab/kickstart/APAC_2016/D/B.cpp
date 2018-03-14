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

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		map<vi,int> x;
		while(n--){
			cin>>s;
			vi temp(26,0);
			F1(i,0,(int)s.length()-1)
				temp[s[i]-'a']++;
			x[temp]++;
		}
		printf("Case #%d: ", cnt++);
		while(m--){
			cin>>s;
			n = s.length();
			vi dp(n+1,0);
			dp[n] = 1;
			F2(i,n-1,0){
				int u = 0;
				vi temp(26,0);
				F1(j,i,n-1 && j < i+20){
					temp[s[j]-'a']++;
					if(x.find(temp)!=x.end()){
						dp[i]+=((ll)x[temp]*dp[j+1])%MOD;
						dp[i]%=MOD;
					}
				}
			}
			cout<<dp[0]<<" ";
		}
		cout<<endl;
	}
}