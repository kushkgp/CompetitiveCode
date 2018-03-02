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
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int phi[(int)1e7+1];
int n = 1e7;

int precompute(){
	memset(phi,0,sizeof(phi));
	F1(i,2,n){
		if(!phi[i]){
			phi[i]=i;
			for(int j=i;(ll)j*i<n;j++){
				phi[j*i] = i;
			}
		}
	}
}

int answer(int a, int b, int &depth){
	if(a==1 && b==1)
		return 0;
	depth++;
	if(a<b)
		swap(a,b);
	int bs = phi[a];
	int exp_2 = 0 ;
	while(b%bs==0){
		exp_2++;
		b/=bs;
	}
	int exp1 = 0;
	while(a%bs==0){
		exp1++;
		a/=bs;
	}
	return answer(a,b, depth) + fabs(exp1-exp_2);
}

int main(){
	precompute();
	int a,b;
	cin >> a >> b;
	int C=1;
	while(a||b){
		int d=0;
		cout <<C++ << ". " << d << ":" << answer(a,b,d) << endl;
		cin >> a >> b;
	}
}