N = int(input())
liquids = sorted(list(map(int, input().split())))

left, right = 0, N-1
result = [liquids[left], liquids[right]]
mini = 2000000000

while left < right:
    tmp = liquids[left] + liquids[right]
    if abs(tmp) < mini:
        result = [liquids[left], liquids[right]]
        mini = abs(tmp)
    if tmp == 0: break
    elif tmp < 0:
        left += 1
    else:
        right -= 1
    
print(result[0], result[1])