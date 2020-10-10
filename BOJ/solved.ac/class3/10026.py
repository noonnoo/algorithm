import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

N = int(input())
map = [list(input()) for _ in range(N)]

c_visited = [[False for x in range(N)] for i in range(N)]
n_visited = [[False for x in range(N)] for i in range(N)]

r_dir = [-1, 0, 0, 1]
c_dir = [0, -1, 1, 0]

def color_blind(i, j):
    c_visited[i][j] = True

    for dir in range(4):
        r = r_dir[dir] + i
        c = c_dir[dir] + j
        if(r < 0 or r >= N or c < 0 or c >= N):
            continue
        if(c_visited[r][c] is False):
            if(map[r][c] == map[i][j]):
                color_blind(r, c)
            elif((map[i][j] == 'R' or map[i][j] =='G')
                    and (map[r][c] == 'R' or map[r][c] =='G')):
                color_blind(r, c)

def none_blind(i, j):
    n_visited[i][j] = True

    for dir in range(4):
        r = r_dir[dir] + i
        c = c_dir[dir] + j
        if(r < 0 or r >= N or c < 0 or c >= N):
            continue
        if(n_visited[r][c] is False and map[r][c] == map[i][j]):
            none_blind(r, c)

count_color_blind = 0
count_none_blind = 0
for i in range(N):
    for j in range(N):
        if (c_visited[i][j] is False):
            color_blind(i, j)
            count_color_blind += 1
        if (n_visited[i][j] is False):
            none_blind(i, j)
            count_none_blind += 1

print(count_none_blind, count_color_blind)
