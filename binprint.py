COLUMNS = 16
POSTRITS = 8

import pathlib, sys, struct

b = pathlib.Path(sys.argv[1]).read_bytes()

def print_pos(pos):
	s = ""
	h = hex(pos)[2:] # Hex string
	
	for i in range(POSTRITS):
		if (i < POSTRITS - len(h)):
			s += "0"
		else:
			s += h[i - (POSTRITS - len(h))]
	
	print("".join(s) + "  ", end = "")

for i in range(len(b)):
	v = hex(b[i])[2:]
	
	# Add zero before if it does not exsist
	if (len(v) == 1):
		v = "0" + v
	
	# Position of byte (if needed)
	if (i % COLUMNS == 0):
		print_pos(i)
	
	# Print byte
	print(f"{v} ", end = "")
	
	# New line
	if (i % COLUMNS == (COLUMNS - 1)):
		print()
