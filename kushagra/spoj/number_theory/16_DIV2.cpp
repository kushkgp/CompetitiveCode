/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;

int phi[(int)1e6+1];
int n = (int)1e6+1;

int precompute(){
	memset(phi,0,sizeof(phi));
	phi[0]=phi[1]=1;
	F1(i,2,n){
		if(!phi[i]){
			for(int j=i;(ll)j*i<=n;j++){
				if(phi[j*i]!=2)
					phi[j*i]=(j%i)?1:2;
			}
		}
	}
	return 1;
}
int print_answer(){
	int CNT=0;
	F1(i,2,n){
		if(phi[i]==1){
			CNT++;
			if(CNT%108==0)
				cout << i << endl;
		}
	}
}

int main(){
	precompute();
	print_answer();
}