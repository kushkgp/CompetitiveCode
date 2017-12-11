// O( (n+q)lg(n) )  nlg(n) in sorting + q*lg(n)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int bs(ll *A,int n,int j,int k){
	int x=0;
	/* sum may be > MAX_INT */
	ll sum;										/* sum will store no. of members which needed to be eaten to make [mid,j]==k */
	int mid,l=0,r=j;
	while(l<=r){
		mid=(l+r)/2;
		sum = A[mid];
		if(j!=n-1)
			sum-=A[j+1];						// sum now have sum of [mid,j]
		sum = k*(j-mid+1) - sum;				// no. of members to be eaten on left
		if(mid >= sum){							// (members on left = [0,mid-1]) >= sum, search left
			x=j-mid+1;							/* members which can be made == k are [mid,j] */
			r=mid-1;						
		}
		else									// search right
			l=mid+1;
	}
	return x;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		vector<int> v;
		int x;
		while(n--) cin>>x ,v.push_back(x);
		n = v.size();
		ll *a = new ll[n];					/* sum may be > MAX_INT */
		sort(v.begin(),v.end());
		a[n-1]=v[n-1];
		for (int i = n-2; i >=0 ; --i)		/* cumilative array from backwards */
			a[i] = a[i+1] + v[i];
		while(q--){
			int k,ans;
			cin>>k;
			int x = lower_bound(v.begin(),v.end(),k)-v.begin();		// V[index] >= k (already)
			ans = n - x;											// ans = n-x
			int j=x-1;												// V[index] which is just less than k
			ans += bs(a,n,j,k);
			cout<<ans<<endl;		
		}
		delete[] a;
	}
	return 0;
}

/* Test Case */
/*
1
5 11
2 4 6 8 10
1
3
4
5
7
8
9
10
13
14
15
*/
/*Expected
5
4
4
4
3
3
2
2
1
1
0
*/