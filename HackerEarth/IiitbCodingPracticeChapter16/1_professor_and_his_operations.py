import sys

line = sys.stdin.readline().rstrip()
line = sys.stdin.readline().rstrip()
inp = line.split(" ")
inp = [int(el) for el in inp]

op = [0 for _ in range(len(inp))]
q = int(sys.stdin.readline().rstrip())

for _ in range(q):
    line = sys.stdin.readline().rstrip()
    line = line.split(" ")
    l = int(line[0])
    r = int(line[1])
    for i in range(l-1, r):
        op[i] = (op[i]+1) % 2

if(len(op)%2 == 0):
    lim = len(op)/2 - 1
else:
    lim = int(len(op)/2) + 1

n = len(op)
for i in range(lim):
    op[i] = (op[i] + op[n-i-1])%2
    if (op[i] == 1):
        temp = inp[i]
        inp[i] = inp[n-i-1]
        inp[n-i-1] = temp

for el in inp:
    print str(el),
