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

#define MAX 1000000
int phi[1000001];

void precompute(){
	memset(phi,0,sizeof(phi));
	phi[1]=1;
	for(int i = 2; i<=MAX; i++){
		if(!phi[i]){
			phi[i] = i-1;
			if(i*i<=MAX)
				for(int j = i; (ll)j*i<=MAX; j++)
					phi[i*j]=i;
		}
		else{
			int j = i;
			while(!(j%phi[i]))
				j/=phi[i];
			if(j==1)
				phi[i] = i-i/phi[i];
			else
				phi[i] = phi[i/j]*phi[j];
		}
	}
}

int main(){
	BOOST;
	precompute();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<phi[n]<<endl;
	}
}