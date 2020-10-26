#include <string>
#include <vector>
using namespace std;

int answer = 9;

void dfs(int N, int number, int count, int current) {
    if (count > 8)      //문제에서 count가 8이 넘어가면 -1을 리턴하라고 했기 때문에 제한을 둠
        return; 
    if (count > 0 && current == 0)      //count0을 넘어서 0이 나오면 짤
        return;

    //number가 나왔을 때 count가 answer보다 작으면 answer에 count 저장하고 return
    if (current == number) {            
        answer = answer < count ? answer : count;
        return;
    }

    //temp는 N이 연속되서 나타나는 숫자
    int temp = 0;
    for (int i = 0; i < 9; i++) {
        temp = temp * 10 + N;
        //사칙연산 다해보기
        dfs(N, number, count + 1 + i, current - temp);
        dfs(N, number, count + 1 + i, current + temp);
        dfs(N, number, count + 1 + i, current * temp);
        dfs(N, number, count + 1 + i, current / temp);
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);

    if (answer == 9) return -1;
    return answer;
}
