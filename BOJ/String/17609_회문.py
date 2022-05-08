import sys
read = sys.stdin.readline

def isSimilar(str, left, right):
    while left < right:
        if str[left] == str[right]:
            left += 1
            right -= 1
        else:
            return False
    return True

def isPalindrome(str):
    ret = 0
    left, right = 0, len(str) - 1
    while left < right:
        if str[left] == str[right]:
            left += 1
            right -= 1
        else:
            similarWoFront = isSimilar(str, left + 1, right)
            similarWoRear = isSimilar(str, left, right - 1)
            if similarWoFront or similarWoRear:
                return 1
            else:
                return 2
    return 0

N = int(read())
for n in range(N):
    str = read().strip()
    print(isPalindrome(str))