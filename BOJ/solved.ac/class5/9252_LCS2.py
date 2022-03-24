import sys
read = sys.stdin.readline

str1 = read().strip()
str2 = read().strip()

n, m = len(str1), len(str2)
LCS = [ [ "" for j in range(m+1) ] for i in range(n+1) ]

for i in range(1,n+1):
    for j in range(1,m+1):
        if str1[i-1] == str2[j-1]:
            LCS[i][j] = LCS[i-1][j-1] + str1[i-1]
        elif len(LCS[i][j-1]) > len(LCS[i-1][j]):
            LCS[i][j] = LCS[i][j-1]
        else:
            LCS[i][j] = LCS[i-1][j]

print(len(LCS[-1][-1]))
if LCS[n][m]:
    print(LCS[-1][-1])