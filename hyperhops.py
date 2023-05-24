
def hyper(a, n, b):
	"""
	Calculate a[n]b
	"""
	
	if (n == 1):
		return a + b
	else:
		c = b - 1
		r = a
		
		while (c != 0):
			r = hyper(r, n - 1, a)
			c -= 1
		
		return r

while True:
	a = int(input("a = "))
	n = int(input("[n] = "))
	b = int(input("b = "))
	
	print(f"a[n]b =", hyper(a, n, b))
	print()
