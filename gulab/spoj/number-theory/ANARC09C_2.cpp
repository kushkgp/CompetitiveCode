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
vector<map<int,int> > vm(1000001);

void precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,N){
		if(!phi[i]){
			vm[i][i]++;
			for(int j = i; (ll)j*i<=N; j++)
				phi[i*j] = i;
		}
		else{
			vm[i] = vm[i/phi[i]];
			vm[i][phi[i]]++;
		}
	}
}


int main(){
	precompute();
	int cnt = 1;
	while(1){
		int a,b;
		cin>>a>>b;
		if(!a)
			break;
		int dim = 0, d = 0;
		F1(i,0,1){
			for(auto it : vm[a]){
				if(vm[b].find(it.ff)==vm[b].end()){
					d+=it.ss;
				}
				else if(i){
					dim--;
					d+=abs(it.ss-vm[b][it.ff]);
				}
				dim++;	
			}
			swap(a,b);
		}
		printf("%d. %d:%d\n", cnt++, dim, d);
	}
}