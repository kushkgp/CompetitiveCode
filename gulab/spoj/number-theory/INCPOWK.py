import math
def main():
	t = int(input())
	while t!=0:
		t=t-1
		k,n = input().split()
		k = int(k)
		n = int(n)
		ans = 0
		while n!=0:
			x = int(math.log(n,2))
			ans+=k**x
			n=n-2**x
		print(ans)
main()