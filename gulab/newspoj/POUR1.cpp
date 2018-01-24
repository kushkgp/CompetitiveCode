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

int gcd(int a, int b){
	if(!b)
		return a;
	return gcd(b,a%b);
}

int solve(int a, int b, int c){
	int x = 0, y = 0;
	int ans=0;
	while(x!=c&&y!=c){
		if(!x)
			x = a;
		else if(y==b)
			y = 0;
		else{
			y += x;
			x = 0;
			if(y>b){
				x = y-b;
				y = b;
			}
		}
		ans++;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(c>max(a,b)){
			cout<<"-1"<<endl;
			continue;
		}
		if(a<b)
			swap(a,b);
		int g = gcd(a,b);
		if(c%g){
			cout<<"-1"<<endl;
			continue;	
		}
		cout<<min(solve(a,b,c),solve(b,a,c))<<endl;
	}
}