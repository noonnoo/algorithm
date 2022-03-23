import sys
read = sys.stdin.readline

N, K = map(int, read().split())
elec = list(map(int, read().split()))
result = 0

# 제일 나중에 사용되는 가전제품의 플러그를 뽑자
plugged = {}
for i in range(0, len(elec)):
    if len(plugged) >= N:
        break
    if elec[i] not in plugged:
        plugged[elec[i]] = elec.index(elec[i], i+1) if elec[i] in elec[i+1:] else 101
#print(plugged)

for i in range(N, K):
    for e in plugged:       # 전자제품이 언제 쓰일지에 대한 정보가 i번째 이전으로 되어 있는 경우 갱신
        if plugged[e] < i:
            plugged[e] = elec.index(e, i + 1) if e in elec[i + 1:] else 101
    if elec[i] in plugged:
        continue
    # plug 교체하는 경우
    result += 1
    latter = max(plugged, key=plugged.get)
    del plugged[latter]
    plugged[elec[i]] = elec.index(elec[i], i + 1) if elec[i] in elec[i + 1:] else 101
    
print(result)