#include <iostream>
#include <deque>
#include <string>
using namespace std;

void functionR(bool &front){
    front = !front;
}

bool functionD(deque<int> &arr, bool &front){
    if(arr.empty())
        return false;
    
    if(front)
        arr.pop_front();
    else
        arr.pop_back();
    return true;
}

void input(string &cmd, deque<int> &arr){
    int n = 0;
    string nums, tmp = "";
    cin >> cmd >> n >> nums;

    if(!n) return;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == '[') continue;
        else if(nums[i] == ',' || nums[i] == ']'){
            arr.push_back(stoi(tmp));
            tmp = "";
        } 
        else
            tmp += nums[i];
    }
}

void printArr(deque<int> &arr, bool front){
    cout << "[";
    if(front)
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i];
            if(i != arr.size()-1) 
                cout << ",";
        }
    else
        for(int i = arr.size() - 1; i >= 0; i--){
            cout << arr[i];
            if(i != 0)
                 cout << ",";
        }
    cout << "]";
}

int main(){
    int N;
    cin >> N;

    while(N--){
        string cmd;
        deque<int> arr;
        bool front = true, error = false;
        input(cmd, arr);

        for(int i = 0; i < cmd.size(); i++){
            if(cmd[i] == 'R') 
                functionR(front);
            else if(cmd[i] == 'D')
                if(!functionD(arr, front)){
                    error = true;
                    break;
                }
        }

        if (error)
            cout << "error";
        else
            printArr(arr, front);
        cout << "\n";
    }
}