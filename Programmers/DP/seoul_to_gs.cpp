#include <string>
#include <vector>
#include <iostream>
using namespace std;

int next_city(const vector<vector<int>> &travel, int K, int index, int time, int money){
    if (time > K)
        return -1;

    if (index == travel.size() - 1) {
        return money;   
    } else {
        int temp = next_city(travel, K, index + 1, time + travel[index + 1][0], money + travel[index + 1][1]);     //도보로 갈 때
        int temp2 = next_city(travel, K, index + 1, time + travel[index + 1][2], money + travel[index + 1][3]);    //자전거로 갈 때

        return temp > temp2 ? temp : temp2;
    }
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    answer = next_city(travel, K, -1, 0, 0);

    return answer;
}
