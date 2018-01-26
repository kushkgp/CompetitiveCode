#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	int n1,n2;
	cin>>s1>>n1;
	int x = 0;
	for (int i = s1.length() - 1; i>=0 ; i-- )
	{
		x+= (s1[i]-'0')*n1;
		
	}
}