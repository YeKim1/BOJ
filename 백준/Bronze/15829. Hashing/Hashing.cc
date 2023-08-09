#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int L;
    string str;

    cin >> L >> str;

    long long sum = 0;
    for (int i = 0; i < str.length(); i++) {
        sum += ((str[i] - 'a' + 1) * pow(31, i));
    }

    cout << sum;
}