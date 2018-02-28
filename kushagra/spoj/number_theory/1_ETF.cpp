/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
	int t;
	cin >> t;

	vi tot(1e6+1,1);
	vi iscomp(1e6+1,0);
	
	int n = 1e6+1;
	
	tot[0]=tot[1] = 1;
	F1(i,2,n){
		if(!iscomp[i]){
			for(int j=i;(ll)j*i<=n;j++){
				iscomp[j*i]=i;
			}
			tot[i] = i-1;
		}
		else{
			int p_fact = iscomp[i], val = i;
			tot[i] = 1;
			while(val%p_fact==0){
				tot[i] *= p_fact;
				val/=p_fact;
			}
			//tot[i] = p_fact^k;
			tot[i] = tot[i] - tot[i]/p_fact;
			tot[i]*=tot[val];
		}
	}
	while(t--){
		int n;
		cin >> n;
		cout << tot[n] << endl;
	}
}