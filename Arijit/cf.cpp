#include <bits/stdc++.h>
#include <iostream>
#include <algorithm> 

using namespace std;

long long int gcd(long long int a, long long int b) {
  while (b != 0)  {
    long long int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main()
{
	int n;
	cin>>n;
	
	long long int a, b;
	cin>>a>>b;
	long long int gcd1 = a*b;
	for( int i = 1; i < n; i++ )
	{
		cin>>a>>b;
		a *= b;
		gcd1 = gcd(gcd1,a);
	}

	if(gcd1==1)
		cout<<"-1"<<endl;
	else
		cout<<gcd1<<endl;
}