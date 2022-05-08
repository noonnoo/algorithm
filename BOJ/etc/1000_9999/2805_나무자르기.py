import sys
read = sys.stdin.readline

N, M = map(int, read().split())
trees = list(map(int, read().split()))

start, end = 1, max(trees)

while(start <= end):
    mid = (start + end) // 2
    treeHeight = sum(list(map(lambda x: x-mid if x >= mid else 0, trees)))
    if treeHeight >= M:
        start = mid + 1
    else:
        end = mid - 1

print(end)