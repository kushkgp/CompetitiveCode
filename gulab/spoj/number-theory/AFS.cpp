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
unsigned long long int phi[1000001];

void precompute(){
	fill(begin(phi),end(phi),1);
	phi[0] = phi[1] = 0;
	F1(i,2,N){
		if(phi[i]==1){
			for(int j = 2; j<=N/i; j+=1){
				ll x = 1+i, y = i;
				while(!(j%y)){
					y*=i;
					x+=y;
				}
				phi[i*j]*=x;
			}
		}
	}
	F1(i,2,N){
		if(phi[i]!=1)
			phi[i]-=i;
		phi[i]+=phi[i-1];
	}
}

int main(){
	precompute();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<phi[n]<<endl;
	}
}