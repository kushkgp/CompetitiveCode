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
#define MOD 10000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

int ans(const vector<int> &A) {
	vector<int> v;
	v.resize(32,0);
	for (int i = 0; i < A.size(); ++i)
	{
		int temp = A[i];
		for (int k = 0; k<32 && temp; ++k,temp>>=1)
		{
			if((temp)&1)
				v[k]++;			
		}
	}
	int ans=0;
	for (int i = 0; i < 32; ++i)
	{
		ans+=(v[i]*(A.size()-v[i]))%MOD;
		ans%=MOD;
	}
	ans<<=1;
	ans%=MOD;
	return ans;
}

int main(){
	BOOST;
	int t;
	cin>>t;
	int c = 1;
	while(t--){
		int n;
		cin>>n;
		vi v(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		cout<<"Case "<<(c++)<<": "<<ans(v)<<endl;
	}
}
