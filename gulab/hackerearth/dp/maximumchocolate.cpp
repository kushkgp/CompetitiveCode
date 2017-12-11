#include <bits/stdc++.h>
using namespace std;

int maxchocolate(int **a,int n){
	int dp1[n],dp2[n],temp;
	for (int j = 0; j < n; ++j)
			dp2[j]=dp1[j]=a[0][j];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp = 0;
			if(j)
				temp = dp1[j-1];
			if(j!=n-1)
				temp = max(temp,dp1[j+1]);
			temp = max(temp,dp1[j]);
			dp2[j] = temp+a[i][j];
		}
		// cout<<"asdf "<<endl;
		for (int j = 0; j < n; ++j){
			dp1[j]=dp2[j];
			// cout<<dp2[j]<<" ";
		}
		// cout<<endl;
	}
	temp = 0;
	for (int i = 0; i < n; ++i)
	{
		temp = max(temp,dp2[i]);
	}
	return temp;
}

int main(){
	int n;
	int **a;
	cin>>n;
	a = new int*[n];
	for (int i = 0; i < n; ++i){
		a[i]= new int[n];
		for (int j = 0; j < n; ++j)
		{
			cin>>a[i][j];
		}
	}

	cout<<maxchocolate(a,n)<<endl;

	for (int i = 0; i < n; ++i)
		delete a[i];
	delete a;
}