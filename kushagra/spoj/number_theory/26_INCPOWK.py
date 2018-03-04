import math
def main():
	t = int(input())
	while t!=0:
		t=t-1
		x = input()
		k,n = x.split()
		k = int(k)
		n = int(n)
		ans = 0
		bas = 1;
		i=0
		while n!=0:
			if n&1:
				ans+=(k**i)
			n>>=1
			i+=1
		print(ans)
main()