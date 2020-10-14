def solution(n, computers):
    answer = 0
    visited = [False for _ in range(n)]

    def DFS(idx):       #dfs 함수 
        nonlocal visited, computers, n, answer

        if idx == n:    #idx가 n과 같아지면 return
            return

        visited[idx] = True
        for j in range(n):  #idx에서 갈 수 있고, 방문한 적 없는 컴퓨터인 경우 DFS 실행
            if computers[idx][j] == 1 and visited[j] is False:
                DFS(j)

    for i in range(n):
        if visited[i] is False:
            DFS(i)
            answer += 1

    return answer
