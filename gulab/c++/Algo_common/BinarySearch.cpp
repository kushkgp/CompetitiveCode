int bs(std::vector<event> & v,int n,int key){
	int x=-1;
	int mid,l=0,r=n-1;
	while(l<=r){
		mid=(l+r)/2;
		if(v[mid].e<=key){
			x=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return x;
}