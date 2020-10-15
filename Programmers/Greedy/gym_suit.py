def solution(n, lost, reserve):
    answer = 0
    able = [True for _ in range(n)]
    
    for x in lost:
        if reserve.count(x) == 1:
            reserve.remove(x)
        else:
            print(x)
            able[x - 1] = False
        
    for i in reserve:
        if i > 1 and able[i-2] == False:
            able[i-2] = True
        elif i < n and able[i] == False:
            able[i] = True
        
    return able.count(True)
