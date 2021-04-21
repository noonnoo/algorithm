#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;    
    
    int i= 0;   
    int j = people.size() - 1;  
    sort(people.begin(), people.end(), greater<int>());
    
    for(;i <= j; i++){
        int boat_limit = limit - people[i];
        if(!people[i])
            continue;
        people[i] = 0;
        answer++;
        
        if(people[j] != 0 && boat_limit >= people[j]){
            people[j--] = 0;                
        }
    }
    
    return answer;
}
