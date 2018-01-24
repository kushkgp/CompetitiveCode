#include <bits/stdc++.h>
using namespace std;


int main(){
	int a[10001];
	a[0]=a[1]=0;
	for (int i = 2; i <= 10000; ++i)
	{
		a[i] = 1;
		for (int j = 2; j < i; ++j)
		{
			if((i%j)==0){
				a[i]=0;
				break;
			}
		}
	}
	// cout<iendl;
	int temp = 100001;
	for (int i = 10000; i >=0; --i)
	{
		if(a[i]==1)
			temp=0;
		else
			temp++;
		a[i]=temp;
	}
	// cout<<endl;
	// for (int i = 1; i <= 10000; ++i)
	// {
	// 	if(!a[i])
	// 		cout<<i<<" ";
	// }
	// cout<<endl;
	int **b,n,k;
	cin>>n>>k;
	b = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		b[i]=new int[n];
		for (int j = 0; j < n; ++j)
		{
			cin>>b[i][j];
		}
	}
	int minp = 1000001;
	int i1,i2;
	for (int i = 1; i < n-1; ++i)
	{
		for (int j = 1; j < n-1; ++j)
		{
			if(!(a[b[i][j]]%k)&&!(a[b[i-1][j-1]]%k)&&!(a[b[i+1][j+1]]%k)&&!(a[b[i-1][j+1]]%k)&&!(a[b[i+1][j-1]]%k)){
				temp = (a[b[i][j]]+a[b[i-1][j-1]]+a[b[i+1][j+1]]+a[b[i-1][j+1]]+a[b[i+1][j-1]])/k;
				if(minp>temp){
					minp=temp;
					i1=i+1;
					i2=j+1;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		delete b[i];
	}
	delete b;
	if (minp<50000)
	{
		cout<<"yes"<<endl;
		cout<<minp<<endl;
		cout<<i1<<" "<<i2<<endl;
	}
	else
		cout<<"no"<<endl;
	return 0;
}