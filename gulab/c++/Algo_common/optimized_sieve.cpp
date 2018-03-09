
#define N 10000000
int phi[N/64+1];
vi primes;
#define gP(n) (phi[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (phi[n>>6]&=~(1<<((n>>1)&31)))

void precompute()
{
	memset(phi,-1,sizeof(phi));
	primes.pb(2);
	for(int i = 3; i<=N; i+=2)
		if(gP(i)){
			primes.pb(i);
			for(int j = i; j <=N/i; j+=2) rP(i*j);
		}
}

inline ull add(ull& a, ull& b, ull& c){
	return a>c-b?a-(c-b):(a+b)%c;
}

/* this function calculates (a*b)%c taking into account that a*b might overflow */
ull mulmod(ull a, ull b, ull c){
	ull x = 0,y=a%c;
	while(b > 0){
		if(b&1){
			x = add(x,y,c);
		}
		y = add(y,y,c);
		b>>=1;;
	}
	return x%c;
}

/* This function calculates (a^b)%c */
ull modulo(ull a, ull b, ull c){
	ull x=1,y=a%c; // u long long is taken to avoid overflow of intermediate results
	while(b > 0){
		if(b&1){
			x=mulmod(x,y,c);
		}
		y = mulmod(y,y,c); // squaring the base
		b>>=1;
	}
	return x%c;
}

/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(ull p,int iteration){
	if(p<2){
		return false;
	}
	if(p!=2 && !(p&1)){
		return false;
	}
	ull s=p-1;
	while(!(s&1)){
		s>>=1;
	}
	for(int i=0;i<iteration;i++){
		ull a=rand()%(p-1)+1,temp=s;
		ull mod=modulo(a,temp,p);
		while(temp!=p-1 && mod!=1 && mod!=p-1){
			mod=mulmod(mod,mod,p);
			temp<<=1;
		}
		if(mod!=p-1 && !(temp&1)){
			return false;
		}
	}
	return true;
}
