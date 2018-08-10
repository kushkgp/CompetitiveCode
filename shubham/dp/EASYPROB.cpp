#include<bits/stdc++.h>
using namespace std;

string solve(int n,string in)
{
	string ans=in;
	ans += "=";
	stack<int> s;
	s.push(n);
	while(!s.empty())
	{
		// cout<<s.size()<<endl;
		int val = s.top();
		s.pop();
		if(val == 1)
		{
			ans +=("+2 (0) ");
			continue;
		}
		if(val == 0)
			continue;
		if(val == 2)
		{
			ans+="+2";
			continue;
		}
		if(val == -1)
		{
			ans+= ") ";
			continue;
		}
		int t = log2(val);
		cout<<val<<" "<<t<<endl;
		int rem = val - 1<<t ;
		cout<<rem<<endl;
		s.push(rem);
		s.push(-1);
		s.push(t);
		ans+="2 (";
	}

	return ans;
}

int main()
{
	cout<<solve(137,"2")<<endl;
}