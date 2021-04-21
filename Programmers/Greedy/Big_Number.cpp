#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int idx = -1;
    int nsize = number.size();
    for (int i = nsize - k; i > 0; i--) {
        int check_list = nsize - i;
        int tmp_max = -1;
        for (int j = idx + 1; j <= check_list; j++) {
            if (tmp_max < number[j] - '0') {
                tmp_max = number[j] - '0';
                idx = j;
            }
        }
        answer += tmp_max + '0';
    }

    return answer;
}
