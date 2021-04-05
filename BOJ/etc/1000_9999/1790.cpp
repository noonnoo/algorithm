#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n, k, result = -1;
	cin >> n >> k;

	int temp = 0, cnt = 0;
	for (int i = 1, j = 1; j <= n; i++, j *= 10) {		//i는 자리수, j는 i자리수인 수의 전체 개수
		temp += n - j + 1;								//temp는 n까지 나열한 수의 총 자리수를 구하기 위함

		if (k < cnt + (pow(10, i) - pow(10, i - 1)) * i && k <= temp) {		//k가 i번째 자리수까지 나열한 모든 수의 자리수보다 작고, temp 보다 작으면
			int idx = k - cnt - 1;						//idx는 k에서 (i-1)번째 자리수까지 나열한 모든 수의 개수를 뺀 것 (k를 i자리수보다 작게 만듦)
			int num = (idx / i) + pow(10, i - 1);		//num은 k번째 자리수의 원래 숫자
			result = to_string(num)[idx % i] - '0';		//num에서 k번째 자리수가 있는 위치를 구하기
			break;
		}

		cnt += (pow(10, i) - pow(10, i - 1)) * i;
	}

	cout << result;
}
