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
typedef vector< pii > vpii;

int main(){
	int n,s;
	cin>>n>>s;
	int f = s>=0?0:1;
	if(f)s=-s;
	int sum = n*(n+1);
	sum>>=1;
	if(sum<s||f&&sum<s+2){
		cout<<"Impossible"<<endl;
		return 0;
	}
	sum = sum - s;
	if(sum%2){
		cout<<"Impossible"<<endl;
		return 0;
	}
	else{
		sum>>=1;
		vector<bool> b(n,false);
		for (int i = n-1; i >= 0; --i)
		{
			if(sum>=i+1){
				b[i]=true;
				sum-=(i+1);
			}
		}
		if(f^b[0]){
			for (int i = 0; i < n-1; ++i)
			{
				if(f^b[i]&&f^(b[i+1]^1)){
					// cout<<i<<endl;
					b[i]=b[i]^1;
					b[i+1]=b[i+1]^1;
					if(!i){
						for (int j = 1; j < n; ++j)
						{
							if(j==n){
								cout<<"Impossible"<<endl;
								return 0;
							}
							if(f^b[j+1]&&f^(b[j]^1)){
								b[j]=b[j]^1;
								b[j+1]=b[j+1]^1;
							}
						}
					}
					else
						b[0]=b[0]^1;
					break;
				}
			}
			if(f^b[0]){
								// cout<<"hi"<<endl;
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
		cout<<"1";
		for (int i = 1; i < n; ++i)
		{
			if(f^b[i])
				cout<<"-";
			else
				cout<<"+";
			cout<<i+1;
		}
		cout<<endl;
	}
}