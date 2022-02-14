//combination하고 완전탐색 --> 시간 초과 탈락
//이분탐색.. n개의 돌을 없애서 돌 사이 거리의 최솟값이 x로 만들 수 있는가? (x에 대한 이분탐색)
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//n개보다 많은 조약돌을 없애 mini보다 작은 거리를 달성할 수 있으면 가능
bool possible(const vector<int> &rocks, const int &dist, const int &mini, const int &n){
    int removed = 0;
    int pre = 0;
    
    for(int i = 0; i < rocks.size(); i++){
        if(rocks[i] - pre < mini)   //이전 위치에서 현재와 간격이 최소거리보다 작으면
            removed++;              //해당 돌 제거
        else                        //최소보다 크면 pre 현재돌로 assign
            pre = rocks[i];            
    }    
    if(dist - pre < mini)
        removed++;
    
    return removed <= n ? false : true;     //n보다 많이 돌을 없애면 해당 경우는 가능
}


int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    int left = 0, right = distance;             //기준은 거리 (돌이 아님)
    
    while(left <= right){
        int mid = (int)(left+right)/2;
        
        if(possible(rocks, distance, mid, n))   //mid보다 돌 사이 거리가 좁아도 된다
            right = mid - 1;
        else {
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}
