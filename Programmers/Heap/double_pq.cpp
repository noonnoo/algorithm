#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;

    int pq_size = 0;
    for(int i = 0; i < operations.size(); i++){
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));

        if(op == 'I'){
            pq_max.push(num);
            pq_min.push(num);
            pq_size++;
        } else if(pq_size && !pq_max.empty() && num == 1){
            pq_max.pop();
            pq_size--;
        } else if(pq_size && !pq_min.empty() && num == -1){
            pq_min.pop();
            pq_size--;
        }

        if(!pq_size){
            pq_min = priority_queue<int, vector<int>, greater<int>>();
            pq_max = priority_queue<int>();
        }
    }

    if(!pq_size){
        answer.push_back(0);
        answer.push_back(0);
    } else if(pq_size == 1){
        answer.push_back(1);
        answer.push_back(1);
    } else{
        answer.push_back(pq_max.top());
        answer.push_back(pq_min.top());
    }

    return answer;
}
