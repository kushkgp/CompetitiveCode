/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <message.h>
#include "majority.h"

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(auto x = y; x <= z; x++)
#define F2(x,y,z) for(auto x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

pii combine(pii & a, pii & b){
	pii temp;
	if(a.ff == b.ff){
		temp.ff = a.ff;
		temp.ss = a.ss+b.ss;
	}
	else{
		if(b.ss>a.ss){
			temp.ff = b.ff;
			temp.ss = b.ss - a.ss;
		}
		else{
			temp.ff = a.ff;
			temp.ss = a.ss - b.ss;
		}
	}
	return temp;
}

int main(){
	int n = NumberOfNodes();
	int id = MyNodeId();
	int size = GetN();

	// locally moore computation
	// e.ff = candidate, e.ss = count
	pii e = mp(0, 0);
	{
		for(int i = id; i < size; i+=n){
			pii x = mp(GetVote(i), 1);
			e = combine(e,x);
		}
		PutInt(0, e.ff);
		PutInt(0, e.ss);
		Send(0);
	}

	// Combine to compute the candidate
	e = mp(0, 0);
	if(id == 0){
		F1(i, 0, n-1){
			Receive(i);
			int candidate = GetInt(i);
			int count = GetInt(i);
			pii temp = mp(candidate, count);
			e = combine(e, temp);
		}
		F1(i, 0, n-1){
			PutInt(i, e.ff);
			Send(i);
		}
	}

	// receive to to report actual count
	int candidate;
	{
		Receive(0);
		candidate = GetInt(0);
		int count = 0;
		for(int i = id; i < size; i+=n){
			if(candidate == GetVote(i))
				count++;
		}
		PutInt(0, count);
		Send(0);
	}

	// check if it is a majority
	if(id == 0){
		int count = 0;
		F1(i, 0, n-1){
			Receive(i);
			count+=GetInt(i);
		}
		if(count>size/2)
			cout<<candidate<<endl;
		else
			cout<<"NO WINNER"<<endl;
	}

}