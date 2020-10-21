#include <string>
#include <vector>
#include <algorithm> 
using namespace std;
typedef unsigned long long ull;

ull solution(int n, vector<int> times) {
    ull answer = 0;
    sort(times.begin(), times.end());
    
    ull maxi = (ull)times[times.size()-1] * (ull)n;             //최대로 걸릴 수 있는 시간
    ull mini = (ull)times[0];   //최소 시간
    
    while(mini < maxi){
        ull mid = (mini + maxi) / 2;
        ull people = 0;
        
        for(int i = 0; i < times.size(); i++){  //times[i]가 처리할 수 있는 사람 수 
            people += (mid / (ull)times[i]);
        }
        
        if(people < n){             //목표 사람보다 적은 사람 수용 --> 시간 부족
            mini = mid + 1;         //최소 시간을 늘린다
        } else {                    //목표 사람보다 많은 사람 수용 --> 시간 남음
            maxi = mid;             //최대 시간을 줄인다.
        }
    }
    
    return maxi;
}
