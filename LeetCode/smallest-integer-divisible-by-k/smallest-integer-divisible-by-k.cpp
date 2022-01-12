class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 1, cnt = 0;
        bool remainders[100000] = {false};
        
        while(true){
            cnt++;
            if(num % k == 0) return cnt;            //나눠짐
            if(remainders[num]) return -1;      //나눠질수 없는 경우 나머지 순환
            remainders[num] = true;
            num = (num * 10 + 1) % k;            
        }
    }
};  
