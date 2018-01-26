nextPermutation(vector<int> &A) {
	int n = A.size();
	int i;
	for (i = n - 1; i > 0; --i)
	{
		if(A[i]>A[i-1]){
			int x = upper_bound(A.rbegin(),A.rbegin()+(n-1-i),A[i-1]) - A.rbegin();
			x = n-1 - x;
			swap(A[i-1],A[x]);
			break;
		}
	}
	sort(A.begin()+i,A.end());
}
