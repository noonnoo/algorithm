answer = []
def DFS(tickets, idx, visited, curr_list):
    v = visited[:]
    curr_list.append(tickets[idx][1])
    v[idx] = True
    last_city = curr_list[-1]

    if v.count(False) == 0:         #모든 경우를 다 살펴봤으니 answer에 추가하고 return
        answer.append(curr_list[:])
        curr_list.pop()             #현재까지 경로 중 이번에 추가한 경로 삭제
        return              

    for i in range(len(tickets)):   #i번째 ticket의 출발지가 현재 들린 마지막 도시이면 DFS 진행
        if v[i] is True:
            continue
        if last_city == tickets[i][0]:
            DFS(tickets, i, v, curr_list)

    curr_list.pop()


def solution(tickets):
    for i in range(len(tickets)):
        visited = [False for _ in range(len(tickets))]
        if (tickets[i][0] == "ICN"):
            curr_list = ["ICN"]
            DFS(tickets, i, visited, curr_list) #첫번째 도시가 ICN이면 DFS 진행

    answer.sort()       #answer를 알파벳 순으로 정렬
    print(answer)
    return answer[0]    #가장 첫번째 정답 출력
