#include <iostream>
#include <stack>
using namespace std;

//stack 활용
int getNums(stack<int> &st){
    int ret = 0;
    while(!st.empty() && st.top() >= 0){
        ret += st.top();
        st.pop();
    }
    return ret;
}

int main(){
    stack<int> st;      // ( : -1, [ : -2
    string input;
    
    cin >> input;

    for(int i = 0; i < input.size(); i++){
        char curr = input[i];
        switch (curr)
        {
        case '(':
            st.push(-1);
            continue;
        case '[':
            st.push(-2);
            continue;
        }
        
        int tmp = getNums(st);
        if(st.empty()) break;       // 안넣을 경우 반례 : ]]
        
        if(curr == ')'){
            if(st.top() != -1){
                break;
            }
            else if (tmp == 0){
                st.pop();
                st.push(2);
            }
            else{
                st.pop();
                st.push(tmp * 2);
            }
        } else if(curr == ']'){
            if(st.top() != -2){
                break;
            }
            else if (tmp == 0){
                st.pop();
                st.push(3);
            }
            else{
                st.pop();
                st.push(tmp * 3);
            }
        }
    }

    int tmp = getNums(st);
    if(st.empty())
        cout << tmp;
    else
        cout << 0;
}