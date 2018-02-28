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

#define N 100000
int phi[100001];
vi comp;

inline void numbers(int & n, vi & ret){
	string s = to_string(n);
	F1(i,0,(int)s.length()-1)
		ret.push_back(stoi(s.substr(0,i)+s.substr(i+1)));
}

void precompute(){
	memset(phi,0,sizeof(phi));
	phi[1] = 1;
	phi[0] = 1;
	for(int i = 2; i<=N; i++){
		if(!phi[i]){
			for(int j = i; (ll)j*i<=N; j++)
				phi[i*j] = 1;
		}
		else{
			if(i>9){
				vi x;
				numbers(i,x);
				F1(j,0,(int)x.size()-1){
					if(!phi[x[j]]){
						phi[i] = 0;
						break;
					}
				}
			}
		}
	}
	F1(i,1,N)
		if(phi[i])
			comp.pb(i);
}

int main(){
	BOOST;
	precompute();
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		int x = upper_bound(all(comp),b) - upper_bound(all(comp),a-1);
		cout<<x<<endl;
	}
}