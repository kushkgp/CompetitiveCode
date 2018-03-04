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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef v<pii> vpii;

#define N 1000000
int phi[1000001];
ll ans[1000001];
void precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,N){
		if(!phi[i]){
			phi[i] = i-1;
			for(int j = i; j<=N/i; j++)
				phi[i*j] = i;
		}
		else{
			int t = i/phi[i];
			while(!(t%phi[i]))
				t/=phi[i];
			if(t!=1)
				phi[i] = phi[t]*phi[i/t];
			else
				phi[i]*=phi[i/phi[i]];
		}
	}
	fill(begin(ans),end(ans),0);
	F1(i,2,N){
		for(int j = 1; j<=N/i; j++)
			ans[j*i]+=(ll)j*phi[i];
		ans[i]+=ans[i-1];
	}
}

int main(){
	precompute();
	int n;
	cin>>n;
	while(n){
		cout<<ans[n]<<endl;
		cin>>n;
	}
}