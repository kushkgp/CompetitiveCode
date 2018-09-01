#include <bits/stdc++.h>
using namespace std;
template <typename X> using v = vector<X>;

void findz(string &s, v<int> & z){
	int n = s.size();
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i>r){
			l = r = i;
			while(r < n && s[r]==s[r-l])
				r++;
			z[i] = r-l;
			r--;
		}
		else{
			int k = i - l;
			if(z[k] < r-i+1)
				z[i] = z[k];
			else{
				l = i;
				while(r < n && s[r] == s[r-l])
					r++;
				z[i] = r-l;
				r--;
			}
		}
	}
}

int main(){
	string s;
	cin>>s;
	while(s!="*"){
		int n = s.size();
		v<int> z(n);
		findz(s, z);
		int f = 1;
		for(int i = 1; i < n; i++){
			if(z[i] == n-i && n%i == 0){
				cout<<n/i<<endl, f = 0;
				break;
			}
		}
		if(f)
			cout<<1<<endl;
		cin>>s;
	}
	return 0;
}