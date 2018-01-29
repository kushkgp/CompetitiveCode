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

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<vvi> m(4,vvi(250,vi(250,0)));
		int ans = 0;
		m[0][0][0]=1;
		F1(i,0,(int)s.length()-1){
			char c = s[i];
			if(c=='a'){
				F2(i,248,0){
					m[0][i+1][0]+=m[0][i][0];
					m[0][i+1][0]%=MOD;
				}
			}
			else if(c=='b'){
				F2(j,248,1)
					F1(i,1,249){
						m[1][i][j+1]+=m[1][i][j];
						m[1][i][j+1]%=MOD;
					}
				F1(i,1,249){
					m[1][i][1]+=m[0][i][0];
					m[1][i][1]%=MOD;
				}
			}
			else if(c=='c'){
				F1(i,0,248)
					F2(j,249,1){
						m[2][i][j]+=(m[2][i+1][j]+m[1][i+1][j])%MOD;
						m[2][i][j]%=MOD;
					}
			}
			else{
				F1(j,0,248){
					m[3][0][j]+=(m[3][0][j+1]+m[2][0][j+1])%MOD;
					m[3][0][j]%=MOD;
				}
				m[0][0][0]+=m[3][0][0];
				m[0][0][0]%=MOD;
				ans+=m[3][0][0];
				ans%=MOD;
				m[3][0][0]=0;
			}
		}
		printf("Case #%d: %d\n", cnt++, ans);
	}
}