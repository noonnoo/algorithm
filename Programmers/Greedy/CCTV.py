def solution(routes):
    answer = 0
    length = len(routes)
    routes.sort(key=lambda r : r[1])
    last = 0

    curr = 0
    while curr < length:
        last = routes[curr][1]
        answer += 1

        while True:
            if curr == length:
                break
            elif routes[curr][0] <= last:
                curr += 1
            else:
                break

    return answer

print(solution([[-20,-15],[-14,-5],[-18,-13],[-5,-3]]))