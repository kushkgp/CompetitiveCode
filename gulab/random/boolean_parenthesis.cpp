#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int opresult(int i,int k,int j,string op,int **dp1,int **dp0,int opcode){
	int x1,x0,y1,y0;
	x1=dp1[i][k];
	x0=dp0[i][k];
	y1=dp1[k+1][j];
	y0=dp0[k+1][j];
	if (opcode){
		if (op=="and")
			return x1*y1;
		if (op=="or")
			return x1*y1+x1*y0+x0*y1;
		if (op=="xor")
			return x1*y0+x0*y1;
	}
	else{
		if (op=="and")
			return x0*y0+x1*y0+x0*y1;
		if (op=="or")
			return x0*y0;
		if (op=="xor")
			return x1*y1+x0*y0;
	}
}


int countboolparenth(int *b,string *op,int n){
	int **dp1,**dp0;
	dp1 = new int*[n];
	dp0 = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		dp1[i]=new int[n];
		dp0[i]=new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		dp1[i][i]=1&&b[i];
		dp0[i][i]=1^b[i];
	}
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = i+1; j < n; ++j)
		{
			int sum1=0,sum0=0;
			for (int k = i; k < j; ++k)
			{
				sum1+=opresult(i,k,j,op[k],dp1,dp0,1);
				sum0+=opresult(i,k,j,op[k],dp1,dp0,0);
			}
			dp1[i][j]=sum1;
			dp0[i][j]=sum0;
		}
	}
	int x = dp1[0][n-1];
	for (int i = 0; i < n; ++i)
	{
		delete dp1[i];
		delete dp0[i];
	}
	delete dp1;
	delete dp0;
	return x;
}
int main(){
	int n;
	cin>>n;
	int *b = new int[n];
	string *s = new string[n];
	cin>>b[0];
	for (int i = 1; i < n;i++)
	{
		cin>>s[i-1];
		cin>>b[i];
	}
	// cout<<"hello"<<endl;
	cout<<countboolparenth(b,s,n)<<endl;
	delete[] b;
	delete[] s;
}