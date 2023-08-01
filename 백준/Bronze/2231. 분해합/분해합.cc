#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;

    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int sum = i;

        string s = to_string(i);
        for (int j= 0; j < s.size(); j++) sum += (s[j] - '0');

        if (sum == N) {
            ans = i;
            break;
        }
    }

    cout << ans;
}