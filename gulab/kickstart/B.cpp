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
typedef pair<int,ll> pill;
typedef vector<pii> vpii;


int main(){
	int t;
	cin>>t;
	int cas = 1;
	while(t--){
		int n;
		cin>>n;
		int m,f=0,ans = 1;
		vi col(n,0);
		vvi v;
		v.resize(n,vi(n));
		char c;
		for (int i = 0; i < n; ++i)
		{
			int m = 0;
			for (int j = 0; j < n; ++j)
			{
				cin>>c;
				if(c=='X'){
					v[i][j]=1;
					m++;
					col[j]++;
					if(m>2)
						ans=0;
				}
			}
			if(!m)
				ans=0;
			if(m==1)
				if(!f)
					f=1;
				else{
					ans = 0;
					
			}
		}
		f=0;
		for (int i = 0; i < n; ++i)
		{
			int m = col[i];
			if(m>2||!m)
				ans=0;
			if(m==1)
				if(!f)
					f=1;
				else
					ans = 0;
		}
		if(ans){
			for (int i = 0; i < n; ++i)
			{
				int f = 0;
				int a,b,c,d;
				int f1 = 0;
				for (int j = 0; j < n; ++j)
				{
					if(v[i][j]){
						if(!f){
							f = 1;
							a = i;
							b = j;
						}
						else{
							f=2;
							for (int k = 0; k < n; ++k)
							{
								if(v[k][j]&&k!=i){
									f1=1;
									c = j;
									d = k;
									break;
								}
							}
							break;
						}
					}
				}
				if(f==2){
					if(!f1){
						ans = 0;
						break;
					}
					else if(!v[d][b]){
							ans = 0;
							break;
					}
					v[a][b] = v[a][c] = v[d][c] = v[d][b] = 0;
				}
			}
		}
		cout<<"Case #"<<cas++<<": ";
		if(ans){
			cout<<"POSSIBLE"<<endl;
		}
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}