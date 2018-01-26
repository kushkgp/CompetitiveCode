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

ll ans(const vi & v, int n){
	int left[n],right[n];
	left[0] = -1;
	stack<pii> s;
	s.push(mp(v[0],0));
	for (int i = 1; i < n; ++i)
	{
		while(!s.empty()&&s.top().ff>=v[i]){
			s.pop();
		}
		if(s.empty())
			left[i] = -1;
		else
			left[i] = s.top().ss;
		s.push(mp(v[i],i));
	}
	while(!s.empty()){
		s.pop();
	}
	right[n-1] = n;
	s.push(mp(v[n-1],n-1));
	for (int i = n-2; i >= 0; --i)
	{
		while(!s.empty()&&s.top().ff>=v[i]){
			s.pop();
		}
		if(s.empty())
			right[i] = n;
		else
			right[i] = s.top().ss;
		s.push(mp(v[i],i));
	}
	ll result = 0;
	for (int i = 0; i < n; ++i)
	{
		result = max(result,(ll)v[i]*(right[i] - left[i]-1));
	}
	return result;
}

int main(){
	int n;
	cin>>n;
	while(n){
		vi v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		cout<<ans(v,n)<<endl;
		cin>>n;
	}
	return 0;
}