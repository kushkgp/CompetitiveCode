/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <message.h>
#include "again.h"

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(auto x = y; x <= z; x++)
#define F2(x,y,z) for(auto x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int n = NumberOfNodes();
const int id = MyNodeId();

pii GetSegment(ll size){
	return mp(size*id/n, size*(id+1)/n-1);
}
// only implement sum(a[i]*b[j]) for all i,j
// required sum(a[i]*b[j]) where (i+j)%n!=0
int main(){
	int size = GetN();
	pii segment = GetSegment(size);
	int b = 0;
	{
		int a = 0;
		F1(i, segment.ff, segment.ss){
			a+=GetA(i)%MOD;
			b+=GetB(i)%MOD;
			a%=MOD;
			b%=MOD;
		}
		PutInt(0, a);
		Send(0);
	}
	if(id==0){
		int a = 0;
		F1(i, 0, n-1){
			Receive(i);
			a+=GetInt(i);
			a%=MOD;
		}
		F1(i, 0, n-1){
			PutInt(i, a);
			Send(i);
		}
	}
	{
		Receive(0);
		int a = GetInt(0);
		ll ans = (ll)a*b;
		ans%=MOD;
		PutInt(0, ans);
		Send(0);
	}
	if(id==0){
		int ans = 0;
		F1(i, 0, n-1){
			Receive(i);
			ans+=GetInt(i);
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
}