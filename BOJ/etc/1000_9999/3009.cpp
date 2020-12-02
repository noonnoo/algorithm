#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    if (a1 == a2)
        cout << a3;
    else if (a1 == a3)
        cout << a2;
    else
        cout << a1;


    if (b1 == b2)
        cout << " " << b3;
    else if (b1 == b3)
        cout << " " << b2;
    else
        cout << " " << b1;
}
