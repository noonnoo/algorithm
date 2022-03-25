# 이전과 현재 바위 사이 거리가 mid_dist보다 작으면 remove
# removed가 n보다 많으면 mid_dist가 n만큼 제거해서 나올 수 있는 거리여서 True
def possible(dist, mid_dist, rocks, n):
    pre, removed = 0, 0
    for rock in rocks:
        if rock - pre < mid_dist:
            removed += 1
        else:
            pre = rock
    if dist - pre < mid_dist:
        removed += 1
    print(mid_dist, removed)
    return True if removed > n else False

def solution(dist, rocks, n):
    min_dist, max_dist = 0, dist            # 구하려는 dist는 각 지점 사이 거리의 최솟값 중 가장 큰 값
    answer = 0
    rocks.sort()

    while min_dist < max_dist:
        mid_dist = (min_dist + max_dist)//2
        if possible(dist, mid_dist, rocks, n):
            max_dist = mid_dist
        else:
            answer = mid_dist
            min_dist = mid_dist + 1
        print(min_dist, max_dist)
        print()
    
    return answer

print(solution(25,[2,14,11,21,17],2))