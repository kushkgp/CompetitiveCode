#include <bits/stdc++.h>
using namespace std;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X>>;

void findz(string & s, v<int> & z){
	int l = 0, r = 0;
	int n = z.size();
	for(int i = 1; i < n; i++){
		if(r < i){
			l = r = i; 
			while( r < n && s[r-l] == s[r] )
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
				while( r < n && s[r-l] == s[r] )
					r++;
				z[i] = r-l;
				r--;
			}
		}
	}
}

int main(){
	int n1, n2;
	cin>>n1>>n2;
	v<string> p(n1);
	for(int i = 0; i < n1; i++){
		cin>>p[i];
	}
	int m1, m2;
	cin>>m1>>m2;
	v<string> s(m1);
	for(int i = 0; i < m1; i++){
		cin>>s[i];
	}
	int found = 0;
	vv<int> z(n1, v<int> (n2+m2+1,0) );
	for(int i = 0; i < m1 - n1 + 1; i++){
		for(int j = i; j < i+n1; j++){
			string x = p[j-i] + "#" + s[j];
			findz(x, z[j-i]);
		}
		for(int j = 0; j < m2; j++){
			int f = 1;
			for(int k = 0; k < n1; k++)
				if(z[k][j+n2+1]!=n2){
					f = 0;
				}
			if(f){
				found = 1;
				printf("(%d,%d)\n", i+1, j+1);
			}
		}
	}
	if(!found)
		cout<<"NO MATCH FOUND..."<<endl;
	return 0;
}