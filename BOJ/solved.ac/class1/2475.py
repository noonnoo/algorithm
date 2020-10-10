import sys
input = sys.stdin.readline

num = input().split()
ans = 0
for n in num:
    ans += int(n) * int(n)

print(ans % 10)
