#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class box{
public:
	int h,l,w;
};

class lessthan{
public:
	bool operator()(const box & a,const box & b){return a.l*a.w>b.l*b.w;}
}lessthanf;

int maxheight(box *b,int n){
	std::vector<box> a;
	for (int i = 0,j=0; i < n; ++i)
	{
		a.push_back(b[i]);
		j++;
		a.push_back(b[i]);
		a[j].h=b[i].l;
		a[j++].l=b[i].h;

		a.push_back(b[i]);
		a[j].h=b[i].w;
		a[j++].w=b[i].h;
	}
	sort(a.begin(),a.begin()+3*n,lessthanf);
	int dp[3*n];
	for (int i = 0; i < 3*n; ++i)
	{
		int m=0;
		for (int j = 0; j < i; ++j)
		{
			if (max(a[j].l,a[j].w)>max(a[i].l,a[i].w)&&min(a[j].l,a[j].w)>min(a[i].l,a[i].w)){
				if(m<a[j].h)
					m=a[j].h;
			}
		}
		dp[i]=a[i].h+m;
	}
	int max=0;
	for (int i = 0; i < 3*n; ++i)
	{
		cout<<a[i].h<<endl;
		if(max<dp[i]){
			max=dp[i];
			cout<<"   "<<i<<endl;
		}
	}
	return max;
}

int main(){
	int n;
	cin>>n;
	box *b = (box*)malloc(n*sizeof(box));
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i].h>>b[i].l>>b[i].w;
	}
	cout<<maxheight(b,n)<<endl;
}