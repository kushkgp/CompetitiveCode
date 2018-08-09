
#include <bits/stdc++.h>

using namespace std;

int recur( string s, int pos, int prev )
{
	int ans = 0;
	
	if( pos == -1 )
		return 1;
	int sum = 0;
	for( int i = pos; i >= 0; i-- )
	{
		sum = sum + s[i] -'0';

		if( sum <= prev )
			ans += recur(s,i-1,sum);
	}

	return(ans);
}



int main()
{
	int t = 0;

	while(1)
	{
		t = t+1;
		string s;
		cin>>s;
		if( s == "bye" )
			return 0;

		cout<<t<<". "<<recur(s,s.length()-1,INT_MAX)<<endl;
	}
}

