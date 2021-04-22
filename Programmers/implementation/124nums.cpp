#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int nsize = 1;
    while(true){
        if(3 * (pow(3,nsize) - 1) / 2 >= n){
            for(;nsize > 0;nsize--){
                int pre_size = 3 * (pow(3, nsize - 1) - 1) / 2;
                int tmp = (n - pre_size - 1) / pow(3, nsize-1);                
                
                if(tmp == 2)
                    answer += '4';
                else
                    answer += tmp + '1';
                n = n - pre_size - pow(3, nsize - 1) * tmp + 3 * (pow(3, nsize - 2) - 1) / 2;
            }    
            break;
        }
        nsize++;
    }
    
    return answer;
}

//1씩빼고 3으로 나머지,나누기 하는 방법이 훨씬 간단..
