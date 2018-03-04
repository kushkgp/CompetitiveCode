def inp():
	while 1:
		try:
			x = int(input())
			return x;
		except:
			continue;
catalans = [1]

for i in range(0,150):
	catalans.append((catalans[i]*2*(2*i+1))//(i+2))

x=inp()
while x!=-1:
	print (catalans[x])
	x=inp()