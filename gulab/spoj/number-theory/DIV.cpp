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

void precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,N){
		if(!phi[i]){
			phi[i] = i;
			for(int j = i; (ll)j*i<=N; j++)
				phi[i*j] = i;
		}
	}

	int prevsum = 0, curr = 0;
	F1(i,2,N){
		int cnt = 0, t = i;
		while(!(t%phi[i]))
			cnt++, t/=phi[i];
		if(t>1){
			int cnt2 = 0, t2 = t;
			while(!(t2%phi[t]))
				cnt2++, t2/=phi[t];
			curr = (t2==1)&&(phi[cnt+1]==cnt+1)&&(phi[cnt2+1]==cnt2+1)&&(cnt!=cnt2);
		}
		else{
			int temp = cnt+1;
			curr = (phi[temp/phi[temp]]==temp/phi[temp])&&(phi[temp]!=phi[temp/phi[temp]]);
		}
		prevsum += curr;
		if(curr&&!(prevsum%9))
			cout<<i<<endl;
	}
}

int main(){
	BOOST;
	precompute();
}