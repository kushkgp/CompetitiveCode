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

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	int t;
	cin>>t;
	for(int cnt = 1; cnt<=t; cnt++){
		int b,l,n;
		cin>>b>>l>>n;
		vector<vector<double> > v(2,vector<double>( ( ((l+2)*(l+1))/2 )+1,0));
		v[0][1]=750*b;
		for(int j = 0; j < l; j++){
			int f = j%2;
			int line = 1, glass=1;
			fill(v[!f].begin(),v[!f].end(),0);
			for(int i = 1; i <=((j+1)*(j+2))/2; i++){
				double X = v[f][i];
				v[f][i] = X>=250?250:X;
				X= X>=250?X-250:0;
				v[!f][i]+=X/3;
				v[!f][i+line]+=X/3;
				v[!f][i+line+1]+=X/3;
				++glass;
				if(glass>line)
					++line,glass=1;
			}
		}
		printf("Case #%d: %.7lf\n", cnt, v[(l-1)%2][n]);
	}
}