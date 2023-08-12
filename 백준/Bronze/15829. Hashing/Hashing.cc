#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int L;
    string str;

    cin >> L >> str;

    long long sum = 0;
    long long r = 1;
    for (int i = 0; i < str.length(); i++) {
        long long x = str[i] - 'a' + 1;
        x *= r;
        r = (r * 31) % 1234567891;
        sum += (x % 1234567891);
    }

    cout << sum;
}