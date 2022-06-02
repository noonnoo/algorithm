import sys
read = sys.stdin.readline

N, M = map(int, read().split())
pioneer = read().strip()
nuclearFamily = [ read().split() for _ in range(N) ]
descendent = [ read().strip() for _ in range(M) ]
result = [0, '']

family = {}
for c, p1, p2 in nuclearFamily:
    family[c] = [p1, p2, 0]

def DFS(child):
    if child in family:
        if family[child][0]:
            p1, p2 = family[child][0], family[child][1]
            family[child][2] = (DFS(p1) + DFS(p2)) / 2
    elif child == pioneer:
        family[child] = [None, None, 1]
    else:
        family[child] = [None, None, 0]
    return family[child][-1]

for d in descendent:
    tmp = DFS(d)
    if result[0] < tmp:
        result = [tmp, d]

print(result[1])
