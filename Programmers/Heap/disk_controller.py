import heapq
import math

def solution(jobs):
    answer, n , idx = 0, len(jobs), 0
    jobs.sort()     #시작 시간 순서대로 sort
    last, time, waiting = -1, 0, []

    while idx < len(jobs):
        for start, delay in jobs:
            if last < start <= time:  # 이전 작업이 끝난 시간이 보다 현재 작업 시작 시간이 빠르면(대기 리스트)
                heapq.heappush(waiting, [delay, start])

        if waiting:
            idx += 1
            last = time
            delay, start = heapq.heappop(waiting)
            time += delay
            answer += (time - start)
        else:
            time += 1

    return math.floor(answer / n)
