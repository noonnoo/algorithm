import math

def solution(n, times):
    times.sort()
    min_time, max_time = times[0], (times[-1] * n)

    while(min_time < max_time):
        people = 0
        mid_time = math.floor((min_time+max_time) / 2)
        for t in times:
            people += math.floor(mid_time / t)

        if people < n:
            min_time = mid_time + 1
        else:
            max_time = mid_time

    return min_time

print(solution(6,[7,10]))