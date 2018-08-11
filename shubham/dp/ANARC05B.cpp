#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

long long solve(vi &a,vi &b,int n,int m)
{
	long long ans=0,sum1=0,sum2=0;
	int i=0,j=0;
	while(i<n || j<m)
	{
	 	// cout<<i<<" "<<j<<endl;
		if(i!=n && j!= m)
		{
			if(a[i]==b[j])
			{
				ans = a[i]+ ans + max(sum1,sum2);
				sum1=0;
				sum2=0;
				i++;
				j++;
			}
			else if(a[i]<b[j])
			{
				sum1+=a[i];
				i++;
			}
			else
			{
				sum2+=b[j];
				j++;
			}
		}
		else if(i!=n)
		{
			sum1+=a[i];
			i++;
		}
		else
		{
			sum2+=b[j];
			j++;
		}
	}
	ans += max(sum1,sum2);
	return ans;
}

int main()
{
	while(true)
	{
		int n,m;
		scanf("%d",&n);
		if(n==0)
			break;
		vi a(n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		// cout<<"here"<<endl;
		scanf("%d",&m);
		vi b(m);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		// cout<<"here1"<<endl;
		printf("%lld\n", solve(a,b,n,m));

	}
}