import sys
read = sys.stdin.readline

N = int(read())
places = list(map(int, read().split()))
answer = 0
total = sum(places)

b1 = total - places[N-1]            # 벌통이 왼쪽 끝에 있는 경우
for b in range(N - 2, 0, -1):
    b1 -= places[b]
    answer = max(answer, b1 + (total - places[N-1] - places[b]))

b1 = total - places[0]              # 벌통이 오른쪽 끝에 있는 경우
for b in range(1, N-1):
    b1 -= places[b]
    answer = max(answer, b1 + (total - places[0] - places[b]))

# 벌통이 가운데 있고, 벌들이 양 끝에 있는 경우
answer = max(answer, total - places[0] - places[N-1] + max(places[1:N-1]))

print(answer)