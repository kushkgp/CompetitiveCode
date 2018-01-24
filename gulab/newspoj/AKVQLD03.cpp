#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BITree{
private:
	T *tree;
	int size;
public:
	T range_query(int idx){
		T sum = 0;
		idx++;											
		for(;idx>0;idx -= (idx & -idx))					
			sum = sum + tree[idx];
		return sum;
	}
	T range_query(int idx1, int idx2){
		return this->range_query(idx2) - this->range_query(--idx1);	
	}
	void point_update(int idx ,T val){
		idx++;											
		for(; idx < size ; idx += (idx & -idx))			
			tree[idx] = tree[idx] + val;
	}
	BITree<T>(int n){
		size = n+1;
		tree = new T[size];
		memset(tree,0,sizeof(T)*size);
	}
	~BITree<T>(){
		delete[] tree;
	}
};

int main(){
	int n,q;
	cin>>n>>q;
	BITree<int> B(n);
	while(q--){
		string s;
		cin>>s;
		if(s==string("find")){
			int a,b;
			cin>>a>>b;
			cout<<B.range_query(--a,--b)<<endl;
		}
		else{
			int p,v;
			cin>>p>>v;
			B.point_update(--p,v);
		}
	}
}