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

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;

int main(){
	BOOST;
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s.length()>=2 && s.substr(s.length()-2,2)==string("ic")){
			if(s.length()>=5 && s.substr(0,5)==string("hydro"))
				cout<<"non-metal acid";
			else
				cout<<"polyatomic acid";
		}
		else
			cout<<"not an acid";
		cout<<endl;
	}
}