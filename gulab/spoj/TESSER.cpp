#include <bits/stdc++.h>
using namespace std;
template <typename X> using v = vector<X>;

void findkmp(string & s, v<int> & kmp){
	kmp[0] = 0;
	for(int i = 1; i < s.size(); i++){
		int j = kmp[i-1];
		while(j > 0 && s[i] != s[j])
			j = kmp[j-1];
		if(s[i] == s[j])
			j++;
		kmp[i] = j;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s("");	
		int prev, curr;
		cin>>prev;
		for(int i = 1; i < n; i++){
			cin>>curr;
			if(curr>prev)
				s+="G";
			if(curr<prev)
				s+="L";
			if(curr==prev)
				s+="E";
			prev = curr;
		}
		string p;
		cin>>p;
		int x = p.size();
		p += "$"+s;
		v<int> kmp(p.size());
		findkmp(p, kmp);
		int f = 0;
		for(int i = x; i < p.size(); i++)
			if(kmp[i] == x){
				f = 1;
				break;
			}
		cout<<(f?"YES":"NO")<<endl;
	}
}