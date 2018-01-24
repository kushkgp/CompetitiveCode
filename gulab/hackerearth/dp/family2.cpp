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
bool compatible(family a,family b,int h){
	return a.age<b.age&&abs(a.loc-b.loc)<=h;
}

int lis(family* a,int n,int h,int flag){
	family b1,b2;
	int maxlen=0,i;
	for (i = 0; i < n; ++i)
	{
		if(sign(a[i].loc)==flag){
			if(flag==-1)
				b2=a[i];
			else
				b1=a[i];
			break;
		}
	}
	int turn  = -flag;
	for (; i < n; ++i)
	{
		if(sign(turn)==sign(a[i].loc)){
			if(turn==1){
				if(compatible(b2,a[i],h)){
					b1 = a[i];
					maxlen++;
					turn=-turn;
				}
			}
			else {
				if(compatible(b1,a[i],h)){
					b2 = a[i];
					maxlen++;
					turn=-turn;
				}
			}
		}
		else{
			if(sign(a[i].loc)==1){
				if(abs(b1.loc)>abs(a[i].loc))
					b1 = a[i];
			}
			else{
				if(abs(b2.loc)>abs(a[i].loc))
					b2 = a[i];
			}
		}
	}
	return maxlen;
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

	cout<<max(lis(a,n,h,-1),lis(a,n,h,1))<<endl;
	// cout<<lis(a,n,h,1)<<endl;
	// int b[]={4,6};
	// cout<<bs(b,2,5)<<endl;
}