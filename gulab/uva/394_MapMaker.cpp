#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef vector<ll> vll;

typedef struct arr{
	string name;
	int base,d,val;
	vi lbound;
	vll carr;
	arr(const string & s = " "){name =s;}
	bool operator<(const arr& rhs) const
  	{
    	return name < rhs.name;
  	}
  	bool operator==(const arr& rhs) const
  	{
  	    return name == rhs.name;
  	}

} arr;


int main(){
	int n,r;
	cin>>n>>r;
	set< arr > s;
	while(n--){
		arr a;
		cin>>a.name>>a.base>>a.val>>a.d;
		for (int i = 0; i < a.d; ++i)
		{	int x,y;
			cin>>x>>y;
			a.lbound.push_back(x);
			a.carr.push_back(y-x+1);
		}
		ll temp = a.carr[a.d-1];
		a.carr[a.d-1] = 1;
		for (int i = a.d-2; i>=0; --i)
		{
			ll temp2 = a.carr[i];
			a.carr[i]=temp*a.carr[i+1];
			temp = temp2;
		}
		s.insert(a);
	}
	while(r--){
		string name;
		cin>>name;
		const arr & a = *(s.find(arr(name)));
		// if(s.find(arr(name))==s.end())cout<<"wrong"<<endl;
		int temp,i=0;
		ll sum = a.base;
		cout<<name<<"[";
		// cout<<"hi"<<endl;
		for (; i < a.d-1; ++i)
		{
			cin>>temp;
			sum += a.val*a.carr[i]*(temp-a.lbound[i]);
			cout<<temp<<", ";
			// cout<<i<<a.val*a.carr[i]*(temp-a.lbound[i])<<endl;
		}
		cin>>temp;
		sum += a.val*a.carr[i]*(temp-a.lbound[i]);
		cout<<temp<<"] = "<<sum<<endl;
	}
}