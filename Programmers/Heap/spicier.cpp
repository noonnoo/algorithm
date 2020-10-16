#include <string>
#include <vector>
#include <queue> 

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue <int, vector<int>, greater<int>> heap;

    for (int i = 0; i < scoville.size(); i++) {
        heap.push(scoville[i]);
    }

    while (heap.top() < K) {
        if (heap.size() < 2) {
            return -1;
        }
        int min1 = heap.top();
        heap.pop();
        int min2 = heap.top();
        heap.pop();

        answer++;
        heap.push(min1 + min2 * 2);
    }

    return answer;
}
