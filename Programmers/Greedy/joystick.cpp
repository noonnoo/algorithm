#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int nsize = name.size();
    int idx = 0;
    string target(nsize, 'A');
    
    while(name != target) {
        if((int)'Z' - (int)name[idx] + 1 < (int)name[idx] - (int)'A')
            answer += (int)'Z' - (int)name[idx] + 1;
        else
            answer += (int)name[idx] - (int)'A';
        name[idx] = 'A';
        
        for(int i = 1; i < nsize; i++){
            if(name[(idx + i) % nsize] != target[(idx + i) % nsize]){
                idx = (idx + i) % nsize;
                answer += i;
                break;
            } else if(name[(nsize + idx - i) % nsize] 
                      != target[(nsize + idx - i) % nsize]){
                idx = (nsize + idx - i) % nsize;
                answer += i;
                break;
            }
        }        
    }
    
    return answer;
}
