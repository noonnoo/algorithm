import sys
read = sys.stdin.readline

#input
N, K = map(int, read().split())
words = [ read().strip("antic\n") for n in range(N) ]   # antic은 빼고 시작
 
chosen = {'a':0,'c':2,'i':8,'n':13,'t':19}              # antic은 먼저 골라놓기
result = 0

# 백트래킹
def chooseChar(idx, k):
    global result
    if idx > 26:
        return
    if  k <= 0:
        possible = 0
        for w in words:                                 # words의 단어 알파벳 모두 chosen에 있을경우
            flag = True
            for c in w:
                if c not in chosen:
                    flag = False
                    break
            if flag:
                possible += 1
        result = max(result, possible)
        return
 
    ch = chr(97+idx)
    if ch not in chosen:                                # idx번째 문자를 고르는 경우
        chosen[ch] = idx
        chooseChar(idx + 1, k - 1)
        del chosen[ch]
    chooseChar(idx + 1, k)
 
if K < 5:
    print(0)
else:    
    chooseChar(0, K - 5)
    print(result)