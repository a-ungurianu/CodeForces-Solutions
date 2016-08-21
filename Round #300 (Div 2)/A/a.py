inp = str(raw_input())

found = False

for i in range(len(inp)):
	for j in range(i,len(inp)):
		if inp[:i] + inp[j:] == "CODEFORCES":
			print "YES"
			found = True
			break
	if found:
		break
if not found:
	print "NO"