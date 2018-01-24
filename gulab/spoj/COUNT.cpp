/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define size1 5001
#define MOD 1988
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int dp[size1][size1];

void ans(){
	for (int i = 1; i < size1; ++i)
	{
		dp[0][i] = 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i < size1; ++i)
	{
		for (int j = 1; j < size1; ++j)
		{
			dp[i][j] = 0;
			if(i>=j){
				dp[i][j] = dp[i-1][j-1];
				if(i>=j<<1){
					dp[i][j]+=dp[i-j][j];
					dp[i][j]%=MOD;
				}
			}
		}
	}
}

int main(){
	int n,k;
	ans();
	cin>>n>>k;
	while(n||k){
		cout<<dp[n][k]<<endl;
		cin>>n>>k;
	}
}