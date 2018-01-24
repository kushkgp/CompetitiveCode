#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

int main(){
	string s;
	cin>>s;
	int dp1,dp2=0,dp3=0;
	if (s[0]=='a')
		dp1=1;
	else 
		dp1=0;

	for (int i = 1; i < s.length(); ++i)
	{
		switch(s[i]){
			case 'a':dp1=(2*dp1+1)%N;
					break;

			case 'b':dp2=(2*dp2)%N;
					dp2=(dp2+dp1)%N;
					break;

			case 'c':dp3=(2*dp3)%N;
					dp3=(dp3+dp2)%N;
					break;

		}
	}
	cout<<dp3<<endl;
	return 0;
}