import sys
from heapq import heappush, heappop

INF = float('inf')
input = sys.stdin.readline

N, M = map(int, input().split())
s = int(input())-1
graph = [[] for i in range(N)]

d = [INF] * N
heap = []
def dijkstra(s):
    d[s] = 0
    heappush(heap, [0, s])                  #그래프 시작점에서 갈 수 있는 간선을 heap에 넣음

    while heap:                             #heap이 비어있지 않으면
        w, curr = heappop(heap)             #heap pop해서 가장 작은 거리 가중을 갖는 경우 구해냄
        for next, temp_w in graph[curr]:    #가장 작은 거리 가중을 가는 것이 갈 수 있는 노드들
            next_w = temp_w + w
            if(next_w < d[next]):           #거쳐가는 것이 더 비용이 적으면 update, heap에 넣기
                d[next] = next_w
                heappush(heap, [next_w, next])

for i in range(M):
    u, v, w = map(int, input().split())
    graph[u-1].append([v-1, w])
dijkstra(s)
for i in d:
    print(i if i != INF else "INF")
