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
vi a(10);

int length(int x){
	int f = 0;
	while(x){
		if(!a[x%10])
			return inf;
		x/=10;
		f++;
	}
	return f; 
}

void find(vi & dp, int x){
	if(dp[x])
		return;
	dp[x] = length(x);
	for(int i = 2; i*i<=x; i++){
		if(x%i) continue;
		find(dp,i);
		find(dp,x/i);
		dp[x] = min(dp[x],dp[i]+dp[x/i]+1);
	}
}

int main(){
	int t, cnt =1;
	cin>>t;
	while(t--){
		F1(i,0,9)
			cin>>a[i];
		int x;
		cin>>x;
		vi dp(x+1,0);
		find(dp,x);
		printf("Case #%d: ", cnt++);
		if(dp[x]==inf||!dp[x])
			cout<<"Impossible";
		else
			cout<<dp[x]+1;
		cout<<endl;
	}
}