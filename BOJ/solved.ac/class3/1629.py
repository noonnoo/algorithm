import sys
input = sys.stdin.readline

def power(a, b):
    if b == 1:
        return a % C
    else:
        temp = power(a, b // 2)         #(재귀)b의 반(나머지는 내림한)만큼 a의 제곱수를 구함
                                        #b가 최대 32라고 하면 재귀로 곱셈하는 경우가 log32 즉 5까지 즐어듦
        if(b % 2 == 0):                 #b가 짝수면 a를 한번 더 곱하지 않아도 됨
            return temp * temp % C
        else:                           #b가 홀수면 a를 한번 더 곱해서 원래 값을 만들어줘야함
            return temp * temp * a % C

A, B, C = map(int, input().split())
ans = power(A, B)
print(ans)
