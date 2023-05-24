import json
import pathlib

AVOID = ["text/html", "image/gif", "application/x-javascript", "warc/revisit", "image/png"]

t = json.loads(pathlib.Path("results.json").read_text())

for r in t:
	if (r[1] in AVOID):
		continue
	
	print(r[1], r[0])
