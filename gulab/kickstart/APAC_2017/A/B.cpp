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

bool dp[2001][2001];

bool check(string & s1, string & s2){
	int n = s1.size(), m = s2.size();
	vi l1(n+1),l2(m+1);
	l1[0] = l2[0] = 0;
	F1(i,1,n)
		l1[i] = s1[i-1]=='*'?l1[i-1]:i;
	F1(i,1,m)
		l2[i] = s2[i-1]=='*'?l2[i-1]:i;
	F1(i,0,n)
		F1(j,0,m)
			dp[i][j] = false;
	dp[0][0] = true;
	F1(i,0,n)
		F1(j,0,m){
			if(i && j){
				if(s1[i-1]!='*' && s2[j-1]!='*'){
					if(s1[i-1]==s2[j-1])
						dp[i][j] = dp[i-1][j-1];
				}
				else{
					if(s1[i-1]=='*'){
						dp[i][j]|=dp[i-1][j];
						for(int k = 1, idx = l2[j]; k<=4 && idx>0; k++, idx = l2[idx-1])
							dp[i][j]|=dp[i-1][idx-1];
					}
					if(s2[j-1]=='*'){
						dp[i][j]|=dp[i][j-1];
						for(int k = 1, idx = l1[i]; k<=4 && idx>0; k++, idx = l1[idx-1])
							dp[i][j]|=dp[idx-1][j-1];
					}
				}
			}
			else{
				if(i && s1[i-1]=='*')
					dp[i][j] = dp[i-1][j];
				if(j && s2[j-1]=='*')
					dp[i][j] = dp[i][j-1];
			}
		}
	return dp[n][m];
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		printf("Case #%d: %s\n", cnt++, check(s1,s2)?"TRUE":"FALSE");
	}
}