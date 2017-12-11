/* considering a>=b*/

int gcdExtended(int a, int b, int &x, int &y){
	if(!b){
		x = 0; y = 1;
		return a;
	}
	int x1,y1;
	int g = gcdExtended(b,a%b,x1,y1);
	x = y1 - (a/b)*x1;
	y = x1;
	return g;
}


int gcd(int a,int b){
	if(!b)
		return a;
	return gcd(b,a%b);
}
