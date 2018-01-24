#include <bits/stdc++.h>
using namespace std;

long int balance_building(int *x,int n,int max_xi,long int S,long int M,long int P){
	long int dp[max_xi];
	// cout<<max_xi<<endl;
	long int currmax=0,prevmax=0;
	for (int i = 0; i < max_xi; ++i)
	{
		if(x[0]>i)
			dp[i] = 0-M*(x[0]-i);
		else
			dp[i] = 0-P*(i-x[0]);
	}
	for (int i = 1; i < n; ++i)
	{
		currmax = 0;
		// cout<<i<<"   asdkf"<<endl;
		for (int j = 0; j < max_xi; ++j)
		{
			long int initcost=0;
			if(j<x[i])
				initcost -= M*(x[i]-j);
			else
				initcost -= P*(j-x[i]);
			dp[j] = initcost + max(dp[j]+S,prevmax);
			if(currmax<dp[j])
				currmax = dp[j];
		}
		prevmax = currmax;
	}

	return currmax;
}


int main(){
	int n;
	long int S,M,P;
	cin>>n>>S>>M>>P;
	int *x;
	x = new int[n];
	int max = 0;
	int min = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i];
		if(max<x[i])
			max = x[i];
		if(min>x[i])
			min = x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		x[i]-=min;
	}
	cout<<balance_building(x,n,max-min+1,S,M,P)<<endl;
	delete x;
}