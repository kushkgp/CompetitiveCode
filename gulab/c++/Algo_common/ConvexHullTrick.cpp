http://wcipeg.com/wiki/Convex_hull_trick

// Pseudocode(dp) :
// input N
// for i ∈ [1..N]
//      input rect[i].h
//      input rect[i].w
// let cost[0] = 0
// for i ∈ [1..N]
//      let cost[i] = ∞
//      for j ∈ [0..i-1]
//          cost[i] = min(cost[i],cost[j]+rect[i].h*rect[j+1].w)
// print cost[N]

// Pseudocode(convex hull) :
// input N
// for i ∈ [1..N]
//      input rect[i].h
//      input rect[i].w
// let E = empty lower envelope structure
// let cost[0] = 0
// add the line y=mx+b to E, where m=rect[1].w and b=cost[0] //b is zero
// for i ∈ [1..N]
//      cost[i] = E.query(rect[i].h)
//      if i<N
//           E.add(m=rect[i+1].w,b=cost[i])
// print cost[N]

/*
 conhull class (lines should be sorted in descending order of slopes before adding for convexity and in ascending order for concavity)
 add - amortized constant , query - lg(n)
 space - O(n)
 Can be used to query min value of y at a x in given set of lines
 can be used in dp where
 dp[i] = min((factor depending only on j=m)*(some factor depending only on i=x) + (factor depending only on j=c))
*/

// used in http://www.spoj.com/problems/ACQUIRE/
// see solution for both dp and convex hull code

// m is int but c is ll and query result is ll

class conhull{
private:
	vector<pair<int,ll> > v;					/* Vector for storing lines */

	/* intersection point x coordinate */
	float intersection(int m1, int m2, ll c1, ll c2){
		return (float(c1-c2))/(m2-m1);
	}
	float intersection(pair<int,ll> a, pair<int,ll> b){
		return intersection(a.ff,b.ff,a.ss,b.ss);
	}
	/* bs for index of required line */
	int bs(float key){
		int x=v.size()-1;							// intialising result to n-1 the line
		int mid,l=0,r=x-1;							// checking only on lines 0 to n-2
		while(l<=r){
			mid=(l+r)/2;
			if(intersection(v[mid],v[mid+1])>=key){	// if key(x coordinate) <= x coordinate of intersection(mid,mid+1)
				x=mid;								// current line is mid
				r=mid-1;							// search left
			}
			else
				l=mid+1;							// search right
		}
		return x;
	}
public:
	const vector<pair<int,ll> > & get_vector() const {
		return v;
	}
	/* Deletes redundant lines(now) and then add this line */
	void add(int m, ll c){
		for (int i = v.size()-1; i >=1; --i)
		{
			if(intersection(v[i],v[i-1])>=intersection(v[i-1].ff,m,v[i-1].ss,c)){
				v.pop_back();						// pop like stack
			}
			else break;
		}
		v.pb(mp(m,c));								// add line to hull
	}
	/* For random query */
	ll query(ll x){
		int index = bs(x);
		return x*v[index].ff+v[index].ss;			// line equation
	}
	/* Pointer walk(changes index accordingly) : Use when x is increasing */
	ll query(ll x, int &index){		
		if(index>v.size()-1)						// if index > last_index previous lines deleted some lines change it to last index										
			index = v.size()-1;
		for (; index<v.size()-1; ++index)			// increase index till intersection(index,index+1)>=x
		{
			if(intersection(v[index],v[index+1])<x)
				continue;
			break;
		}
		return x*v[index].ff+v[index].ss;			// line equation
	}
};

/*

*/

// m and c are int and query result can be float

class conhull{
private:
	vector<pair<int,int> > v;								/* Vector for storing lines */	

	/* intersection point x coordinate */
	float intersection(int m1, int m2, int c1, int c2){		// intersection point x coordinate
		return (float(c1-c2))/(m2-m1);
	}
	float intersection(pii a, pii b){
		return intersection(a.ff,b.ff,a.ss,b.ss);
	}
	/* bs for index of required line */
	int bs(float key){
		int x=v.size()-1;							// intialising result to n-1 the line
		int mid,l=0,r=x-1;							// checking only on lines 0 to n-2
		while(l<=r){
			mid=(l+r)/2;
			if(intersection(v[mid],v[mid+1])>=key){	// if key(x coordinate) <= x coordinate of intersection(mid,mid+1)
				x=mid;								// current line is mid
				r=mid-1;							// search left
			}
			else
				l=mid+1;							// search right
		}
		return x;
	}
public:
	const vpii & get_vector() const {
		return v;
	}
	/* Deletes redundant lines(now) and then add this line */
	void add(int m, int c){
		for (int i = v.size()-1; i >=1; --i)
		{
			if(intersection(v[i],v[i-1])>=intersection(v[i-1].ff,m,v[i-1].ss,c)){
				v.pop_back();						// pop like stack
			}
			else break;
		}
		v.pb(mp(m,c));								// add line to hull
	}
	/* For random query */
	float query(float x){
		int index = bs(x);
		return x*v[index].ff+v[index].ss;			// line equation (m*x+c)
	}
	/* Pointer walk(changes index accordingly) : Use when x is increasing */
	float query(float x, int &index){		
		if(index>v.size()-1)						// if index > last_index previous lines deleted some lines change it to last index										
			index = v.size()-1;
		for (; index<v.size()-1; ++index)			// increase index till intersection(index,index+1)>=x
		{
			if(intersection(v[index],v[index+1])<x)
				continue;
			break;
		}
		return x*v[index].ff+v[index].ss;			// line equation
	}
};

/*

*/