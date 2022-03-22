#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> ops(4,0);
int mini = 1000000000, maxi = -1000000000;

int operate(int op, int operand1, int operand2){
    if(op == 0) return operand1 + operand2;
    else if(op == 1) return operand1 - operand2;
    else if(op == 2) return operand1 * operand2;
    else return operand1 / operand2;
}

void insertOperator(int idx, int num){
    if(idx >= nums.size()){
        if(mini > num) mini = num;
        if(maxi < num) maxi = num;
        return;
    }
    for (int i = 0; i < 4; i++){
        if(ops[i] > 0){
            ops[i]--;
            insertOperator(idx + 1, operate(i, num, nums[idx]));
            ops[i]++;
        }
    }
}

int main(){
    int N, tmp;
    cin >> N;

    while(N--){
        cin >> tmp;
        nums.push_back(tmp);
    }
    for(int i = 0; i < 4; i++)
        cin >> ops[i];
    
    insertOperator(1, nums[0]);
    cout << maxi << "\n" << mini;
}