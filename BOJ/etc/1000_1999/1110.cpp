#include <iostream>
using namespace std;

int sum_cycle(int N) {
	short temp;								//N의 일의 자리, 십의 자리를 합친 수

	if (N < 10)
		temp = N % 10;
	else 
		temp = (N / 10) + (N % 10);

	return (N % 10 * 10) + (temp % 10);		//새로운 수
}


int main() {
	int N;
	int num1, num2, count = 1;
	cin >> N;

	num1 = sum_cycle(N);					//처음에만 N으로 진행
	while (num1 != N) {
		num1 = sum_cycle(num1);				//이후에는 계속해서 새로 받은 수로 진행
		count++;
	}
	cout << count;
}
