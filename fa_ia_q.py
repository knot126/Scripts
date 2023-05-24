import requests
import json

url = "https://web.archive.org/web/timemap/json?url=http%3A%2F%2Ffuraffinity.net%2F&matchType=prefix&collapse=urlkey&output=json&fl=original%2Cmimetype%2Ctimestamp%2Cendtimestamp%2Cgroupcount%2Cuniqcount&filter=!statuscode%3A%5B45%5D..&limit=50000&_=1683408165170"

r = requests.get(url)

if (r.status_code == 200):
	t = r.content.decode('utf-8')
	
	print(len(json.loads(t)))
	
	f = open("results_fa.json", "w")
	f.write(t)
	f.close()
	
	print("done!")
else:
	print(f"<problem: {r.status_code}>")
