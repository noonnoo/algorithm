#include <iostream>
#include <vector>

using namespace std;

string gear[4];
int three[4] = { 2,2,2,2 };
int nine[4] = { 6,6,6,6 };

int get_twelve(int t) {         // score을 얻기위한 12시 index구하기
    if (t - 2 < 0)
        return 8 + t - 2;
    else return t - 2;
}

void rotate(int num, int clockwise) {       
    if (clockwise == -1) {      //반시계방향 회전
        three[num] = three[num] + 1 > 7 ? 0 : three[num] + 1;
        nine[num] = nine[num] + 1 > 7 ? 0 : nine[num] + 1;
    }
    else {                      //시계방향 회전
        three[num] = three[num] - 1 < 0 ? 7 : three[num] - 1;
        nine[num] = nine[num] - 1 < 0 ? 7 : nine[num] - 1;
    }
}

void solve(int num, int clockwise, bool flag) {
    int cw = clockwise;
    int pre_nine = gear[num][nine[num]], pre_three = gear[num][three[num]];
    rotate(num, cw);

    for (int i = num - 1; i >= 0; i--) {        //num이전의 톱니바퀴 회전시키기
        if (pre_nine != gear[i][three[i]]) {
            pre_nine = gear[i][nine[i]];
            cw *= -1;                           //회전은 이전과 반대방향으로
            rotate(i, cw);  
        }
        else                                    //회전시킬거 없으면 끝내긴
            break;
    }

    cw = clockwise;
    for (int i = num + 1; i < 4; i++) {         //num이후의 톱니바퀴 회전시키기
        if (pre_three != gear[i][nine[i]]) {
            pre_three = gear[i][three[i]];
            cw *= -1;
            rotate(i, cw);
        }
        else
            break;
    }
}

int main() {
    int N, score = 0;
    int num, clockwise;

    for (int i = 0; i < 4; i++)     //input
        cin >> gear[i];

    cin >> N;
    for (int i = 0; i < N; i++) {   //input대로 회전시키기
        cin >> num >> clockwise;
        solve(num - 1, clockwise, true);
    }

    //각 톱니의 12시방향을 구해서 S극이면 점수 얻기
    if (gear[0][get_twelve(three[0])] == '1') score += 1;
    if (gear[1][get_twelve(three[1])] == '1') score += 2;
    if (gear[2][get_twelve(three[2])] == '1') score += 4;
    if (gear[3][get_twelve(three[3])] == '1') score += 8;

    cout << score;
}
