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

vi phi(1e6+1,0);
int n = 1e6;
int precompute(){
	F1(i,2,n){
		if(!phi[i]){
			for(int j=i;(ll)j*i<=n;j++){
				phi[j*i]=1;
			}
		}
	}

	phi[0] = 1;
	phi[1] = 1;

	F1(i,2,n){
		if(phi[i]){
			if(i>10){
				string num = to_string(i);
				for(int j=0;j<num.size();j++){
					string s = num.substr(0,j) + num.substr(j+1);
					stringstream ss(s);
					int temp;
					ss >> temp;
					if(!phi[temp]){
						phi[i] = 0;
						break;
					}
				}
			}
		}
	}

	F1(i,1,n){
		phi[i]+=phi[i-1];
	}

}

int main(){
	precompute();
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		if(m>n)
			swap(m,n);
		cout << phi[n] - phi[m-1] << endl;
	}
}