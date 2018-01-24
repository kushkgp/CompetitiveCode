#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct family
{
	int age;
	int loc;
}family;

int h;

int bs(family *a,int n,int x){
	int l,r,m;
	l=0;
	r=n-1;
	int i=r;
	while(l<r){
		m=(l+r)/2;
		if(a[m].age >=x){
			i=m;
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return i;
}

bool SameSign(int x, int y)
{
    return (x >= 0) ^ (y < 0);
}

int lis(family *a,int n){
	int maxlen=0;
	family b[n];
	b[0].age = a[0].age;
	b[0].loc = a[0].loc;
	// cout << "hi " << b[0].age << " " << b[0].loc << endl;
	int pos = 0;
	for (int i = 1; i < n; ++i)
	{
		// cout << "sign "<< !SameSign(a[i].loc,b[maxlen].loc) << endl;	
		// cout << "distance "<< abs(a[i].loc - b[maxlen].loc) << endl;
		if(a[i].age == b[maxlen].age) 
		{
			// cout << endl << "qwertyuio" << endl << endl;
			continue;
		}

		if(a[i].age > b[maxlen].age && !SameSign(a[i].loc,b[maxlen].loc) && abs(a[i].loc - b[maxlen].loc) <= h)
		{
			++maxlen;
			b[maxlen].age = a[i].age;
			b[maxlen].loc = a[i].loc;
			// cout << "hi " << b[maxlen].age << " " << b[maxlen].loc << endl;

		}
		else
		{	
			pos = bs(b,maxlen+1,a[i].age);
			// if(pos > 0 && !SameSign(b[pos].loc,b[pos-1].loc)) 
			// {
			// 	b[pos].age = a[i].age;
			// 	b[pos].loc = a[i].loc;
			// }
			if(pos == 0) 
			{
				b[pos].age = a[i].age;
				b[pos].loc = a[i].loc;
				// cout << "pos = " << pos << " " << b[pos].age << " " << b[pos].loc << endl;
			}

		}
	}

	// cout << endl;
	// for(int i = 0 ; i <= maxlen ; i++)
	// 	cout << b[i].age << " " << b[i].loc << endl;
	// cout << endl;

	return maxlen;
}

bool myfunc(family a,family b)
{
	return a.age < b.age;
}

int main(){
	int n;
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

	cout<<lis(a,n)<<endl;
	// int b[]={4,6};
	// cout<<bs(b,2,5)<<endl;
}