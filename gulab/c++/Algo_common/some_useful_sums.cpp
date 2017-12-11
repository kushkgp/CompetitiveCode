int sum1(int a){			// sum1(a) = (1+2+3+....+a)%MOD
	ll x = ((ll)a)*(a+1);
	x>>=1;
	x%=MOD;
	return (int)x;
}
int sum2(int a){			// sum1(a) = (1^2+2^2+3^2+....+a^2)%MOD
	ll x = ((ll)a)*(a+1);
	x>>=1;
	x*=((a<<1)+1);
	x/=3;
	x%=MOD;
	return (int)x;
}