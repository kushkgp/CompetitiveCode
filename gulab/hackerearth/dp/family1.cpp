#include <bits/stdc++.h>
using namespace std;

typedef struct family
{
	int age;
	int loc;
}family;

bool myfunc(family a,family b)
{
	return a.age < b.age;
}

int sign(int n){
	return n<0?-1:1;
}

int lis(family* a,int n,int h){
	int dp[n],max1=0;
	for (int i = 0; i < n; ++i)
	{
		int max =0;
		for (int j = 0; j < i; ++j)
			if (a[i].age>a[j].age&&sign(a[i].loc)!=sign(a[j].loc)&&abs(a[i].loc-a[j].loc)<=h&&max<dp[j])			
				max = dp[j];
		dp[i]=1+max;
		if(max1<dp[i])
			max1=dp[i];
	}
	return max1-1;
}

int main(){
	int n,h;
	cin>>n >> h;

	family *a = new family[n];

	for (int i = 0; i < n; ++i)
	{
		cin>> a[i].age >> a[i].loc;
	}

	sort(a,a+n,myfunc);

	// cout << endl;
	// for(int i = 0 ; i < n ; i++)
	// 	cout << a[i].age << " " << a[i].loc << endl;
	// cout << endl;

	cout<<lis(a,n,h)<<endl;
	// int b[]={4,6};
	// cout<<bs(b,2,5)<<endl;
}