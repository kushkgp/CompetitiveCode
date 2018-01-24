#include <bits/stdc++.h>
// #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
using namespace std;
typedef pair<int,int> pi;
typedef pair< pi, pi > ppi;

int pflag(const pi & a,const pi & b){
	if(a.first == b.first)				// Y vertical line
		return 0;						
	return 1;							// X horizontal line
}

int check(const ppi & a,const ppi & b){	// a--Y b--X
	int a1 = a.first.second;
	int a2 = a.second.second;
	int b1 = b.first.first;
	int b2 = b.second.first;
	if(a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second)	// there is one common endpoint
			return 1;
	return 0;
}

int check1(int a1, int a2, int b1, int b2){	// either x coordinates or y coordinates
	int x = max(a1,a2);
	int y = min(a1,a2);
	if(b1<=x && b1>=y)
		return 1;
	if(b2<=x && b2>=y)
		return 1;
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ppi a,b;
		cin>>a.first.first>>a.first.second>>a.second.first>>a.second.second;
		cin>>b.first.first>>b.first.second>>b.second.first>>b.second.second;
		int f1 = pflag(a.first,a.second);
		int f2 = pflag(b.first,b.second);
		cout<<t<<" "<<f1<<" "<<f2<<endl;
		int x;
		if(f1^f2){ 
			if(f1) x = check(a,b);		// Y and X
			else x = check(b,a);		// X and Y
		}
		else{
			if(f1) if(a.first.first == b.first.first)		// same x
				x = check1(a.first.second,a.second.second,b.first.second,b.second.second);	// Y and Y
			else if(a.first.second == b.first.second)		// same y
				x = check1(a.first.first,a.second.first,b.first.first,b.second.first);			// X and X
		}
		if(x) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}