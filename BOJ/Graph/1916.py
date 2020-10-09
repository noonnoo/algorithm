import sys

INF = float('inf')
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())

graph = [[INF for j in range(N)] for i in range(N)]
for i in range(N):
    graph[i][i] = 0
for i in range(M):
    input = [int(x) for x in sys.stdin.readline().split()]
    if(graph[input[0]-1][input[1]-1] > input[2]):
        graph[input[0]-1][input[1]-1] = input[2]

se = [int(x)-1 for x in sys.stdin.readline().split()]

v = [False for i in range(N)]
d = [0 for i in range(N)]

def getMin():
    global N, v, d
    min = INF
    index = int(0)
    for i in range(N):
        if(d[i] < min and v[i] is False):
            min = d[i]
            index = i

    return index

def dijkstra(se):
    global N, graph, v, d
    for i in range(N):
        d[i] = graph[se[0]][i]

    v[se[0]] = True
    for i in range(N-2):
        curr = getMin()
        v[curr] = True

        for j in range(N):
            if(v[j] is False):
                if(d[curr] + graph[curr][j] < d[j]):
                    d[j] = d[curr] + graph[curr][j]

dijkstra(se)
print(d[se[1]])
