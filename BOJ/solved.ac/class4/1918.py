infix = input()

ans = ""
operator = []
bracket = 0

for x in infix:
    if (x == '('):
        operator.append(x)
    elif (x == ')'):
        while(operator[-1] != '('):
            ans += operator.pop()
        operator.pop()
    elif (x == '*' or x == '/'):
        while (len(operator) and operator[-1] != '('
               and (operator[-1] == '*' or operator[-1] == '/')):  # 이전 연산자 우선순위가 같으면 pop
            ans += operator.pop()
        operator.append(x)
    elif (x == '+' or x == '-'):
        while (len(operator) and operator[-1] != '('):
            ans += operator.pop()
        operator.append(x)
    else:
        ans += x

while(len(operator)):
    ans += operator.pop()

print(ans)
