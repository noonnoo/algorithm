def solution(begin, target, words):
    answer = 100
    if words.count(target) == 0:
        return 0

    N = len(words)
    n = len(begin)

    def able_to_change(word1, word2, n):    #알파벳 하나 차이나는지 확인해주는 함수
        diff = 0
        for j in range(n):
            if (word1[j] != word2[j]):
                diff += 1
                if (diff > 1):
                    break
        if (diff == 1):
            return True
        else:
            return False

    def dfs(count, idx, visited):           #dfs 함수 (visited는 이전 단계에서 받아서 사용)
        nonlocal begin, target, words, n, N, answer
        v = list(visited)
        word = ""
        if (idx == -1):
            word = begin
        else:
            word = words[idx]
            v[idx] = True

        if(able_to_change(word, target, n)):    #target으로 갈 수 있고 
            if (answer > count):                #count가 answer보다 작으면 교체
                answer = count
            return

        for i in range(N):                 #현재까지 방문한 적 없는 단어 중 able_to_change 통과할 수 있으면 dfs
            if(v[i] is True):
                continue
            if(able_to_change(words[i], word, n)):
                dfs(count + 1, i, v)
        return

    visited = [False for _ in range(len(words))]
    dfs(0, -1, visited)                     

    if(answer == 100):                    #배열을 통해 target으로 바꿀 수 없으면 answer가 그래로이기 때문에
        return 0                          #0 반환
    return answer + 1                     #바뀐 게 있으면 해당 수 + 1(target으로 바뀌는 과정 포함) 반환
