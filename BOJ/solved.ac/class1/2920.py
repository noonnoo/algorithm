import sys

input = sys.stdin.readline

standard = [ "1 2 3 4 5 6 7 8\n", "8 7 6 5 4 3 2 1\n" ]
scale = str(input())

if(scale == standard[0]):
    print("ascending")
elif(scale == standard[1]):
    print("descending")
else:
    print("mixed")
