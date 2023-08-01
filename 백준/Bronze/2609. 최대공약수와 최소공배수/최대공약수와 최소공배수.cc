#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int n;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    int a, b;

    cin >> a >> b;

    if (b < a) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    cout << gcd(a, b) << "\n";

    cout << a * b / gcd(a, b);
}