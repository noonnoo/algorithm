#include <iostream>
#include <cmath>
using namespace std;

int N;
double x[10001], y[10001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    double result = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        if (i > 0)
            result += (x[i] * y[i - 1]) - (x[i - 1] * y[i]);
    }
    result += (x[0] * y[N - 1]) - (y[0] * x[N - 1]);

    cout << fixed;
    cout.precision(1);
    result = abs(result) / 2;
    cout << round(result * 10) / 10;
}
