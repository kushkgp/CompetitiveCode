#include <bits/stdc++.h>
using namespace std;

double H,D,U;
double F;

int bs(int l,int r,bool (*f)(int)){
	int x=-1;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(f(mid)){
			x=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return x;
}
int bs2(int l,int r,int n,bool (*f)(int ,int)){
	int x=-1;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(f(n,mid)){
			x=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return x;
}

int ES(int l,bool (*f)(int,int)){
	int n = 1;
	while(!f(l,n)){n<<=1;}
	return bs2(n>>1,n,l,f);
}

bool func1(int n){
	if(n==0) return 0;
	double f = U*(n - F*(n*(n-1))/2)-(n-1)*D;
	return f>H;
}

bool func2(int l,int n){
	if(l<n) return U*(l - F*(l*(l-1))/2)-(n)*D < 0;
	return U*(n - F*(n*(n-1))/2)-(n)*D < 0;
}

int main(){
	while(1){
		cin>>H>>U>>D>>F;
		F/=100;
		int f;
		int n = floor(1/F)+1;
		int n2 = ceil((U-D)/(U*F)+(double)1/2);
		// cout<<func2(101,68)<<endl;
		int n3 = floor((U-D)/(U*F)+(double)1/2);
		// cout<<U*(3 - F*(3*(3-1))/2)-(3-1)*D<<endl;
		if(!H)
			return 0;
		else if(D>U || !F){
			n=1;
			if(H<U)
				f=1;
			else
				f=0;
		}
		else{
			if(func1(n2) || func1(n3)){
				f = 1;
				if(!func1(n3))
					n = n2;
				else
					n = bs(1,n3,func1);
			}
			else{
				f=0;
				n = ES(n,func2);
			}
		}
		if(f)
			cout<<"success on day "<<n<<endl;
		else
			cout<<"failure on day "<<n<<endl;
	}
}

