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

int A[102][102][102];
int n,m,K;

int solve(){
	int ans=INT_MIN;
	F2(i,n,1)
		F2(j,m,1)
			A[i][j][1] = (A[i][j][0])?((i==n||j==1||j==m)?1:min3(A[i+1][j-1][1],A[i+1][j][1],A[i+1][j+1][1])+1):0;
	F2(i,n,1)
		F2(j,m,1){
			A[i][j][1] = A[i][j][1]*A[i][j][1];
			ans = (K==1)?max(ans,A[i][j][1]):ans;
		}
	F2(i,n,1)
		F2(j,m,1){
			F1(k,2,K){
				int lim = sqrt(A[i][j][1]);
				A[i][j][k] = 0;
				F1(h,1,lim && i+h<=n){
					int x = 0;
					F1(z,j-h+1,j+h-1)
						x = max(x,A[i+h][z][k-1]);
					x=x?x+h*h:0;
					A[i][j][k] = max(A[i][j][k],x);
				}
				ans = (k==K)?max(ans,A[i][j][k]):ans;
			}	
		}
	return ans;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>n>>m>>K;
		F1(i,1,n)
			F1(j,1,m){
				char c;
				cin>>c;
				A[i][j][0] = c=='#'?1:0;
			}
		printf("Case #%d: %d\n", cnt++, solve());
	}
}