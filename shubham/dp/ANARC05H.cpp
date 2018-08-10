#include<bits/stdc++.h>
using namespace std;

int getval(char a)
{
	int t =(int) a - '0';
	return t;
}

int solve(int pre,int l, string s)
{
	if(l==s.size())
		return 1;
	int ans = 0;
	ans+= solve(pre+getval(s[l]),l+1,s);
	if(getval(s[l])>=pre)
		ans += solve(getval(s[l]),l+1,s);
	return ans;
}

int main()
{
	int i=1;
	while(true)
	{
		string s;
		cin>>s;
		if(s=="bye")
			break;
		if(s=="")
		{
			printf("%d. %d\n",i,1 );
			continue;
		}

		printf("%d. %d\n",i,solve(((int)s[0]-'0'),1,s) );
		i+=1;
	}
}