/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define min3(a,b,c) (min(min(a,b),c))
#define max3(a,b,c) (max(max(a,b),c))
#define mod 1000000007
#define inf INT_MAX

#define F2(x,y,z) for(int x = y; x >= z; x--)
#define F1(x,y,z) for(int x = y; x <= z; x++)
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define ss second
#define ff first
#define mp make_pair
#define pb push_back

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;


int main(){
	int C = 1;
	int t; scanf("%d", &t);
	while (t--) {
		long double A;
		cin >> A;
		long double rt2=2,rt3=3;
		rt3 = sqrt(rt3),rt2 = sqrt(rt2);
		if(A<=rt2){
			long double theta = asin(A/rt2) - asin(1/rt2);
			long double cost = cos(theta), sint = sin(theta);
			cout << "Case #" << C++ << ":" << endl;
			cout << setprecision(15) << 0.5*cost << " " << 0.5*sint << " " << 0 << endl;
			cout << setprecision(15) << -0.5*sint << " " << 0.5*cost << " " << 0 << endl;
			cout << setprecision(15) << 0 << " " << 0 << " " << 0.5 <<  endl;
		}
		else{
			long double alpha = asin(A/rt3) - asin(rt2/rt3);
			cout << "Case #" << C++ << ":" << endl;
			long double cosa = cos(alpha), sina = sin(alpha);
			cout << setprecision(15) << 0.5*cosa/rt2 << " " << 0.5*cosa/rt2 << " " << -0.5*sina << endl;
			cout << setprecision(15) << -0.5*cosa/rt2 << " " << 0.5*cosa/rt2 << " " << -0.5*sina << endl;
			cout << setprecision(15) << 0 << " " << 0.5*sina << " " << 0.5*cosa <<  endl;
		}
	}	

	return 0;
}