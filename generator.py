
def lcg(a, x, b, m):
	return (a * x + b) % m

def main():
	print("Please select parameters to test with.")
	a = eval(input("a = "))
	b = eval(input("b = "))
	m = eval(input("m = "))
	s = eval(input("s_0 = "))
	
	x = s
	i = 0
	before = []
	
	while (True):
		x = lcg(a, x, b, m)
		
		print(f"[{i}] -> {x}")
		
		if (x in before):
			break
		
		before.append(x)
		
		i += 1
	
	print(f"Repeated after {i + 1} iterations.")

if __name__ == "__main__":
	main()
