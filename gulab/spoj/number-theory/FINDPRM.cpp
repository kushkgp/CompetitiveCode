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
typedef vector<pii> vpii;

#define N 10000000
int phi[10000001];

void precompute(){
	memset(phi,0,sizeof(phi));
	phi[2] = 1;
	for(int i = 3; i<=N; i++){
		if((i+1)%2)
			phi[i] = 1;
		if(!phi[i])
			for(int j = i; (ll)j*i<=N; j+=2)
				phi[i*j] = 1;
		phi[i]=!phi[i];
		phi[i]+=phi[i-1];
	}
}

int main(){
	precompute();
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		cout<<phi[n]-phi[n/2]<<endl;
	}
}