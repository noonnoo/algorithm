import sys
read = sys.stdin.readline

H, W = map(int,read().split())
map = list(map(int, read().split()))

result = 0
left = 0

for i in range(1,len(map)):
    if i == W-1 and map[i] == 0:
        break
    if map[i - 1] < map[i] or i == W-1:
        h = min(map[left],map[i])
        for j in range(left + 1, i):
            if h > map[j]:
                result += (h - map[j])
                map[j] = map[i]
    if map[i] >= map[left]:
        left = i

print(result)