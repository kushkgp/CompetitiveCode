https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

/*
 Both point_update and range_update adds value to previous values
*/

/*
 BITree class (point update and range query)
 point_update - ln(n) , range_query - ln(n) , construction from array - n*ln(n)
 space - n+1
 op+, op- and op= should be defined on typename T
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as BITree<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
*/

template <typename T>
class BITree{
private:
	T *tree;
	int size;
public:
	/* range_query upto particular index */
	T range_query(int idx){								/* return 0 when idx = -1 */
		T sum = 0;
		idx++;											/* User's indices are from 0 and we are using from 1 */
		for(;idx>0;idx -= (idx & -idx))					/* flipping last nonzero bit */
			sum = sum + tree[idx];
		return sum;
	}
	/* Range Queries from idx1 to idx2 including both idx1 and idx2 */
	/* Safe only when op- is defined on T */
	T range_query(int idx1, int idx2){
		return this->range_query(idx2) - this->range_query(--idx1);	/* idx1==0 will be automatically handled */
	}
	/* update value of idx to val */
	void point_update(int idx ,T val){
		idx++;											/* User's indices are from 0 and we are using from 1 */
		for(; idx < size ; idx += (idx & -idx))			/* next index to be updated */
			tree[idx] = tree[idx] + val;
	}
	/* Constructor which inintialize with 0, complexity - constant*/
	BITree<T>(int n){
		size = n+1;
		tree = new T[size];
		memset(tree,0,sizeof(T)*size);
	}
	/* Constructor which copies from array, complexity - n*ln(n) */
	/* Here n denotes size of passed array */
	BITree<T>(T* a,int n){
		size = n+1;
		tree = new T[size];
		memset(tree,0,sizeof(T)*size);
		for (int i = 0; i < size ; ++i){
			this->point_update(i,a[i]);					/* update every index */
		}
	}
	void clear(){
		memset(tree,0,sizeof(T)*size);
	}
	/* Deconstructor */
	~BITree<T>(){
		delete[] tree;
	}
};

/*

*/



/*
 BITree2 class (range update and point query)
 required: BITree class
 range_update - ln(n) , point_query - ln(n) , construction from array - n*ln(n)
 space - n+1
 op+, op- and op= should be defined on typename T
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as BITree<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
 */

template <typename T>
class BITree2{
private:
	BITree<T> *tree;
	int size;								/* size of array given by user */
	void gen_diff_array(T* a, int n){
		for (int i = n-1; i >0 ; --i)
			a[i] = a[i] - a[i-1];
	}
public:
	/* update value from idx1 to idx2 to val */
	void range_update(int idx1, int idx2, T val){
		tree->point_update(idx1,val);
		if(idx2<size-1)						/* No need to update when query is on n-1 */
			tree->point_update(idx2+1,0-val);
	}

	/* point_query to particular index */
	T point_query(int idx){
		return tree->range_query(idx);
	}
	/* Constructor which inintialize with 0, complexity - constant*/
	BITree2<T>(int n):size(n){
		tree = new BITree<T>(n);
	}
	/* Constructor which changes and copies from array, complexity - n*ln(n) */
	/* Here n denotes size of passed array */
	BITree2<T>(T* a,int n):size(n){
		this->gen_diff_array(a,size);
		tree = new BITree<T>(a,size);
	}
	/* Deconstructor */
	~BITree2<T>(){
		delete tree;
	}
};

/*

*/

See comment: https://apps.topcoder.com/forums/?module=Thread&threadID=715842&start=0&mc=8

/*
 BITree3 class (range update and range query)
 required: BITree class
 range_update - ln(n) , range_query - ln(n) , construction from array - n*ln(n)
 space - 2*n
 op+, op-, op*(with int) and op= should be defined on typename T
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as BITree<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
 */

template <typename T>
class BITree3{
private:
	BITree2<T> *tree1,*tree2;
	int size;								/* size of array given by user */
	void gen_diff_array(T* a, int n){
		for (int i = n-1; i >0 ; --i)
			a[i] = a[i] - a[i-1];
	}
public:
	/* update value from idx1 to idx2 to val */
	void range_update(int idx1, int idx2, T val){
		tree1->range_update(idx1, size-1, val);
		tree2->range_update(idx1, size-1, val*(idx1-1));
		if(idx2<size-1){
			tree1->range_update(idx2+1, size-1, 0-val);
			tree2->range_update(idx2+1, size-1, (0-val)*idx2);
		}
	}
	/* Range query upto idx */
	T range_query(int idx){
		return tree1->point_query(idx)*idx - tree2->point_query(idx);	/* A[p]*p - X */
	}
	/* range_query from idx1 to idx2 including idx1 and idx2 */
	T range_query(int idx1,int idx2){
		T sum = this->range_query(idx2);
		if(idx1)									/* No need of subtraction if idx1==0 */
			sum = sum - this->range_query(--idx1);
		return sum;
	}
	/* Constructor which inintialize with 0, complexity - constant*/
	BITree3<T>(int n):size(n){
		tree1 = new BITree2<T>(n);
		tree2 = new BITree2<T>(n);
	}
	/* Constructor which changes and copies from array, complexity - n*ln(n) */
	/* Here n denotes size of passed array */
	BITree3<T>(T* a,int n):size(n){
		tree1 = new BITree2<T>(n);
		tree2 = new BITree2<T>(n);
		for (int i = 0; i < size; ++i) this->range_update(i,i,a[i]);
	}
	/* Deconstructor */
	~BITree3<T>(){
		delete tree1;
		delete tree2;
	}
};

/*

*/