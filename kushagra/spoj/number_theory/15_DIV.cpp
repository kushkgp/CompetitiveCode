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
				if(!phi[j*i])
					phi[j*i]=i;
			}
		}
	}
	return 1;
}

int print_answer(){
	int CNT=0;
	F1(i,2,n){
		int bs1 = !phi[i]?i:phi[i];
		int cnt1 = 0,cnt2=0, val=i;
		while(val%bs1==0)
			val/=bs1,cnt1++;
		if(val!=1){
			bs1 = !phi[val]?val:phi[val];
			while(val%bs1==0)
				val/=bs1,cnt2++;
		}
		if(val==1){ 
			if( (phi[cnt1+1]==0 && phi[cnt2+1]==0 && cnt1!=cnt2) || (phi[cnt1+1]!=0 && phi[(cnt1+1)/phi[cnt1+1]]==0 && ((cnt1+1)/phi[cnt1+1] != phi[cnt1+1]) && cnt2==0)){
				CNT++;
				if(CNT%9==0)
					cout << i << endl;
			}
		}
	}
}

int main(){
	precompute();
	print_answer();
}