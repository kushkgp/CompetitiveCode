#include<bits/stdc++.h>
using namespace std;

map<int,long long> m;


long long result(int n)
{
	if(m.find(n) != m.end())
		return m[n];
	long long ans;
	ans = max((long long)n,result(n/2)+result(n/3)+result(n/4));
	m[n] = ans;
	return ans;
}

int main()
{
	string s;
	getline(cin,s);
	while(!s.empty())
	{
		int x;
		m.clear();
		m[0] = 0;
		stringstream ss(s);
		ss>>x;
		printf("%lld\n", result(x));
		getline(cin,s);
	}
}