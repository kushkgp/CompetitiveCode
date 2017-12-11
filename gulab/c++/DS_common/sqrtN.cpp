http://www.infoarena.ro/blog/square-root-trick

/*
 sqrtN class (two level tree structure)
 update - constant , range_query - sqrt(n) , construction from array - n
 space - n+[n/k]
 op+, op- and op= should be defined on typename T
 For inintialising with vector treat iterator as pointer i.e.
 use constructor as sqrt<int>(&(*v.begin()),v.size()) where v's typename is vector<int>
*/

template <typename T>
class sqrtN{
private:
	T *A;			/* Array containing values of elements */
	int size;		/* Size of array A */
	T *S;			/* Array containing values of groups of size k */
	int k;			/* Group size default is sqrt(n) */
public:
	/* get array for user modifications(there should be build after it) */
	T* get_Array(){
		return A;
	}
	void build(){
		for (int i = 0,sum = 0; i < size; ++i)
		{
			sum = sum + A[i];
			if((i+1)%k==0){
				S[i/k] = sum;
				sum = 0;
			}
		}
	}
	/* update value of idx to val */
	void modify(int idx, int val){
		S[idx/k] = S[idx/k] - A[idx] + val;
		A[idx] = val;
	}
	/* Range Queries from idx1 to idx2 including both idx1 and idx2 */
	T range_query(int idx1, int idx2){
		T sum = 0;
		int i = idx1;
		while((i%k) && i<=idx2){			/* if initial elements do not complete a group */
			sum = sum + A[i];
			i += 1;
		}
		while (i + k <= idx2){				/* Middle groups */
			sum = sum + S[i/k];
			i += k;
		}
		while(i <= idx2 ) {					/* elements of last group */
			sum = sum + A[i];
			i += 1;
		}
		return sum;
	}
	/* Constructor which inintialize with 0, complexity - constant*/
	sqrtN(int n, int group_size = 0):size(n),k(group_size){
		if(!k)
			k = sqrt(size);
		A = new T[size];
		S = new T[size/k];
		memset(A,0,sizeof(T)*size);
		memset(S,0,sizeof(T)*(size/k));
	}
	/* Constructor which copies from array, complexity - n */
	/* Here n denotes size of passed array */
	sqrtN(T * a, int n, int group_size = 0):size(n),k(group_size){
		if(!k)
			k = sqrt(size);
		A = new T[size];
		S = new T[size/k];
		for (int i = 0; i < n; ++i) A[i] = a[i];
		this->build();
	}
	~sqrtN(){
		delete[] A;
		delete[] S;
	}
};

/*

*/