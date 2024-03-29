/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

void printarr(int n, int sigma){
	if(!n)
		return;
	while(n){
		cout<<sigma<<" "<<-sigma<<" ";
		n-=2;
	}
}

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n,sigma;
		cin>>n>>sigma;
		if(n==1){
			if(!sigma) cout<<"0"<<endl;
			else cout<<"-1"<<endl;
			continue;
		}
		if(n%2){
			printarr(n-3,sigma);
			double x = sqrt(double(2));
			cout<<-sigma/x<<" "<<-sigma/x<<" "<<x*sigma<<endl;
		}
		else{
			printarr(n,sigma);
			cout<<endl;
		}
	}
	return 0;
}