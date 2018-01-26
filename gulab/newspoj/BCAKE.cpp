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

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int ans(const vector<string> & v, int n, int c, int cake){
	int a[n][c];
	int result=-1;
	FOR(i,n)
		FOR(j,c){
			a[i][j] = v[i][j]=='C'?1:0;
			if(i) a[i][j]+=a[i-1][j];
			if(j) a[i][j]+=a[i][j-1];
			if(i&&j) a[i][j]-=a[i-1][j-1];
		}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			map<int,int> m;
			m[0] = -1;
			for (int k = 0; k < c; ++k)
			{
				int sum = a[i][k];
				if(j)
					sum-=a[j-1][k];
				if(present(m,sum-cake))
					if(result==-1){
						result = (k-m[sum-cake])*(i-(j-1));
					}
					else{
						result = min(result,(k-m[sum-cake])*(i-(j-1)));
					}
				m[sum] = k;
			}
		}
	}
	return result;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vector<string> s;
		s.resize(n);
		for (int i = 0; i < n; ++i){
			cin>>s[i];
		}
		cout<<ans(s,n,m,k)<<endl;
	}
}