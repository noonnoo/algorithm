#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    //삼각형의 깊이 n-1번째 부터 시작
    for (int i = triangle.size() - 2; i >= 0; i--) {    
        //N-1깊이의 j번째 수는 N깊이의 j, j+1 중 큰 수를 더함
        for (int j = 0; j < triangle[i].size(); j++) {  
            triangle[i][j] += triangle[i + 1][j] >= triangle[i + 1][j + 1] 
                ? triangle[i + 1][j] : triangle[i + 1][j + 1];
        }
    }

    return triangle[0][0];
}

int main() {
    vector<vector<int>> triangle = { {7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5} };
    cout << solution(triangle) << endl;
}
