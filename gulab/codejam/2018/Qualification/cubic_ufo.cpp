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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(){
	int t, cnt = 1;
	long double  v2 = 2, v3 = 3;
	v2 = sqrt(v2);
	v3 = sqrt(v3);
	cin>>t;
	while(t--){
		long double a;
		cin>>a;
		printf("Case #%d:\n", cnt++);
		if(a>v2){
			// printf("%LF %LF\n", a, v2);
			long double alpha = asin(a/v3) - asin(v2/v3);
			long double cos_alpha = cos(alpha), sin_alpha = sin(alpha);
			printf("%.15LF %.15LF %.15LF\n", cos_alpha*0.5/v2, cos_alpha*0.5/v2, -sin_alpha*0.5);
			printf("%.15LF %.15LF %.15LF\n", -cos_alpha*0.5/v2, cos_alpha*0.5/v2, -sin_alpha*0.5);
			printf("%.15LF %.15LF %.15LF\n", (long double)0, sin_alpha*0.5, cos_alpha*0.5);
		}
		else{
			long double theta = asin(a/v2) - asin(1/v2);
			// printf("%LF %lf\n", theta, M_PI/4);
			long double cos_theta = cos(theta), sin_theta = sin(theta);
			printf("%.15LF %.15LF %.15LF\n", cos_theta*0.5, sin_theta*0.5, (long double)0);
			printf("%.15LF %.15LF %.15LF\n", -sin_theta*0.5, cos_theta*0.5, (long double)0);
			printf("%.15LF %.15LF %.15LF\n", (long double)0, (long double)0, (long double)0.5);
			// printf("%LF\n", cos_theta+sin_theta);
		}
	}
}