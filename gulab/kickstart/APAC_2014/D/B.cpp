/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MAX 5000
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

class BITree{
	vi A;
	int size;
public:
	BITree(int n):A(n+1,0),size(n){}
	int rangequery(int a){
		int ans = 0;
		for(int i = a; i > 0; i-=(i&(-i)))
			ans+=A[i];
		return ans;
	}
	void rangeupdate(int a, int x){
		for(int i = a; i <= size; i+=(i&(-i)))
			A[i]+=x;
	}
	int pointquery(int a){
		return rangequery(a);
	}
	void rangeupdate(int a, int b, int c){
		rangeupdate(a,c);
		rangeupdate(b+1,0-c);
	}
};


int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		BITree T(MAX);
		for(int i = 0; i < n; i++){
			int a,b;
			cin>>a>>b;
			T.rangeupdate(a,b,1);
		}
		int p;
		cin>>p;
		printf("Case #%d: ", cnt++);
		while(p--){
			int a;
			cin>>a;
			cout<<T.pointquery(a)<<" ";

		}
		cout<<endl;
	}
}