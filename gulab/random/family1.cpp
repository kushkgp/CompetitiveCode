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

int bs(int *a,int n,int x){
	int l,r,m;
	l=0;
	r=n-1;
	int i=r;
	while(l<r){
		m=(l+r)/2;
		if(a[m]>=x){
			i=m;
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return i;
}

int lis(family* a,int n,int h){
	int b1[n],b2[n],m1=0,m2=-1,i,maxlen,turn;
	for (i = 0; i < n; ++i)
	{
		if(sign(a[i].loc)==1){
			b1[0]=a[i].loc;
			i++;
			break;
		}
	}
	turn = 1;
	for (; i < n; ++i)
	{
		int temp = abs(a[i].loc);
		if (sign(a[i].loc)==1&&!turn)
		{
			if(temp>b1[m1]){
				b1[++m1]=temp;
			}
			else
				b1[bs(b1,m1+1,temp)]=temp;
			turn=!turn;
		}

		else if(sign(a[i].loc)==-1&&turn){
			if(m2==-1||temp>b2[m2]){
				b2[++m2]=temp;
			}
			else
				b2[bs(b2,m2+1,temp)]=temp;
			turn=!turn;
		}
	}
	maxlen = m1+m2;
	m1=0;m2=-1;
	for (i = 0; i < n; ++i)
	{
		if(sign(a[i].loc)==-1){
			b1[0]=a[i].loc;
			i++;
			break;
		}
	}
	turn = 1; 
	for (; i < n; ++i)
	{
		int temp = abs(a[i].loc);
		if (sign(a[i].loc)==-1&&!turn)
		{
			if(temp>b1[m1]){
				b1[++m1]=temp;
			}
			else
				b1[bs(b1,m1+1,temp)]=temp;
			turn=!turn;
		}

		else if(sign(a[i].loc)==1&&turn){
			if(m2==-1||temp>b2[m2]){
				b2[++m2]=temp;
			}
			else
				b2[bs(b2,m2+1,temp)]=temp;
			turn=!turn;
		}
	}
	if(maxlen<m1+m2)
		maxlen =m1+m2;
	return maxlen+1;
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