import sys
read = sys.stdin.readline

N = int(read())
cranes = list(map(int, read().split()))
M = int(read())
boxes = list(map(int, read().split()))

cranes.sort(reverse=True)
boxes.sort(reverse=True)

if cranes[0] < boxes[0]:
    print(-1)
    sys.exit()
else:
    ans = 0
    while boxes:
        for crane in cranes:
            for box in boxes:
                if crane >= box:
                    boxes.remove(box)
                    break
        ans += 1
    print(ans)