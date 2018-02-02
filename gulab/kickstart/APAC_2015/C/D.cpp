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
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int n,k;

int add(deque<pii> & q, int a){
	int curr = q.empty()?1:q.back().ss+1;
	while(!q.empty() && q.back().ff<a)
		q.pop_back();
	q.push_back(mp(a,curr));
	if(curr-q.front().ss>=k)
		q.pop_front();
	return curr>=k?q.front().ff:0;
}


int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int c,x;
		cin>>n>>k>>c>>x;
		vi a(n), b(n);
		F1(i,0,n-1)
			cin>>a[i];
		F1(i,0,n-1)
			cin>>b[i];
		vector<deque<pii> > q(n-k+1);
		ll res = 0;
		F1(i,0,n-1){
			deque<pii> dtemp;
			F1(j,0,n-1){
				int arr = ((i+1)*a[i]+(j+1)*b[j]+c)%x;
				int temp = add(dtemp,arr);
				if(j>=k-1)
					res+=add(q[j-k+1],temp);
			}
		}
		printf("Case #%d: %lld\n", cnt++, res);
	}
}