def solution(numbers, target):
    answer = int(0)

    def DFS(total, index):                  #함수 내의 함수
        nonlocal answer, numbers, target    #지역변수가 아님을 선언        
        if(index == len(numbers)):          #index가 다 채워지면 리턴
            if(total == target):
                answer += 1                 #target과 여태껏 만든 수가 같으면 answer++
            return                          
        DFS(total+numbers[index], index+1)  #이번 수를 더하거나
        DFS(total-numbers[index], index+1)  #빼거나
        
    DFS(0, 0)    
    return answer
​
