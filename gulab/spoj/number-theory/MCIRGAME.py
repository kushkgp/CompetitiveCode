def inp():
	while 1:
		try:
			x = int(input())
			return x;
		except:
			continue;

C = [1]
for i in range(1,151):
	x=C[i-1]
	x=x*(4*i-2)
	x=x//(i+1)
	C.append(x);

x=inp()
while x!=-1:
	print (C[x])
	x=inp()