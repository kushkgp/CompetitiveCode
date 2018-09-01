#include <bits/stdc++.h>
using namespace std;
template <typename X> using v = vector<X>;

void findkmp(string &s, v<int> & kmp){
	int n = s.size();
	kmp[0] = 0;
	for(int i = 1; i < n; i++){
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
	int c = 1;
	while(t--){
		string s;
		cin>>s;
		cin>>s;
		int n = s.size();
		v<int> kmp(n);
		findkmp(s, kmp);
		cout<<"Test case #"<<c++<<endl;
		for(int i = 1; i < s.size(); i++){
			if((i+1)%(i+1-kmp[i]) == 0 && kmp[i]){
				cout<<i+1<<" "<<(i+1)/(i+1-kmp[i])<<endl;
			}
		}
	}
	return 0;
}