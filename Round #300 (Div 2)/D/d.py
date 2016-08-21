
board = []

n = int(raw_input())

for i in range(n):
	board.append(raw_input())

pieces = []

for i in range(n):
	for (j,c) in enumerate(board[i]):
		if c == 'o':
			pieces.append((i,j))

moves = [set() for _ in range(len(pieces))]

for i in range(n):
	for (j,c) in enumerate(board[i]):
		if c == 'x':
			for (k,p) in enumerate(pieces):
				moves[k].add((i-p[0],j-p[1]))


result = moves[0]
for i in range(1,len(pieces)):
	result &= moves[i]

piece = [['.' for _ in range(n*2-1)] for _ in range(n*2-1)]

for d in result:
	piece[d[0]+n-1][d[1]+n-1] = 'x'

piece[n-1][n-1] = 'o'

print "YES"
for row in piece:
	print reduce(lambda a,c: a+c,row)