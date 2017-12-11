from math import *
from decimal import *
for n in range(1,18):
	a=Decimal(1)
	getcontext().prec = 25
	for i in range(1,n+1):
		for j in range(1,4):
			x=2*Decimal(cos(i*Decimal(pi)/(n*2+1)))
			y=2*Decimal(cos(j*Decimal(pi)/6))
			a=a*(x*x+y*y)
	print(a)