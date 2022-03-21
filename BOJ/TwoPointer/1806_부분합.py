import sys
read = sys.stdin.readline

N, S = map(int,read().split())
nums = list(map(int, read().split()))

result = 2e+8+1
total = 0
left, right = 0, 0

while(True):
    if total >= S:
        total -= nums[left]
        left += 1
        result = min(result, right - left + 1)
    elif right == N:
        break
    else:
        total += nums[right]
        right += 1

if result == 2e+8+1:
    print(0)
else:
    print(result)