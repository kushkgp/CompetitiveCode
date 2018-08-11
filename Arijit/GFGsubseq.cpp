#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int memo[61][61][61];
int res(string x,string y,string z,int a,int b,int c)
{
	if(c<0)
		return 1;
	if(a<-1)a=-1;
	if(b<-1)b=-1;
	if(memo[a+1][b+1][c+1]!=-1)
		return memo[a+1][b+1][c+1];
	
	cout<<a<<b<<c<<endl;
	long ans=0;

	if( a >= 0)
	{
		if( z[c] == x[a] )
		ans = ans + res(x,y,z,a-1,b,c);
	else
		ans = ans + res(x,y,z,a-1,b,c);
	}
	if( b>=0 )
	{
		if( z[c] == x[a] )
		ans = ans + res(x,y,z,a,b-1,c);
	else
		ans = ans + res(x,y,z,a,b-1,c);
	}
	// for(int i=a;i>=0;i--)
	// {
	// 	if(z[c]==x[i])
	// 	{
	// 		//cout<<"calling @"<<i-1<<" "<<b<<" "<<c-1<<"\n";
	// 		ans+=res(x,y,z,i-1,b,c-1);
	// 	}
	// }
	// for(int i=b;i>=0;i--)
	// {
	// 	if(z[c]==y[i])
	// 	{
	// 		//cout<<"calling @"<<a<<" "<<i-1<<" "<<c-1<<"\n";
	// 		ans+=res(x,y,z,a,i-1,c-1);
	// 	}
	// }	

	memo[a+1][b+1][c+1]=ans;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string x,y,z;
		cin>>x>>y>>z;
		memset(memo,-1,sizeof(memo));
		cout<<res(x,y,z,x.size()-1,y.size()-1,z.size()-1)<<"\n";
		//cout<<res(x,y,z,0,1,0)<<" "<<res(x,y,z,1,0,0)<<" "<<res(x,y,z,0,0,1)<<"\n";		
	}
	
}