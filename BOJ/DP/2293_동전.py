import sys
read = sys.stdin.readline

n,k = map(int, read().split())
coins = [ int(read()) for i in range(n)]
DP = [ 0 for n in range(k + 1)]
DP[0] = 1

for i in coins:
    for j in range(i, k+1):
        DP[j] += DP[j - i]

print(DP[k])