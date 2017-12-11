#include <bits/stdc++.h>
using namespace std;
int f(int n){
	bitset<32> b(n);
	string s = b.to_string();
	string s0 = s.substr(0,8);
	string s1 = s.substr(8,8);
	string s2 = s.substr(16,8);
	string s3 = s.substr(24,8);
	return (bitset<32>(s3+s2+s1+s0)).to_ulong();
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		cout<<n<<" converts to "<<f(n)<<endl;
	}
	return 0;
}
