#include <iostream>
using namespace std;

double scores[1001];

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		double N, count = 0, mean = 0;
		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> scores[j];
			mean += scores[j];
		}
		mean /= N;

		for (int j = 0; j < N; j++) {
			if (scores[j] > mean)
				count++;
		}

		printf("%.3f%%\n", (double)count * 100 / N);
	}
}
