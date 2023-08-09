#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int K, N;

    cin >> K >> N;

    vector<long long> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long high = v[K - 1];
    long long low = 1;

    long long max_len = 0;
    while (low <= high) {
        long long cnt = 0;
        long long mid = (high + low) / 2;

        for (int i = 0; i < K; i++) {
            cnt += (v[i] / mid);
        }

        if (cnt >= N && mid > max_len) max_len = mid;

        // 더 작게 쪼개야 한다
        if (cnt >= N) low = mid + 1;
        // 더 크게 쪼개야 한다
        else if (cnt < N) high = mid - 1;
    }

    cout << max_len;


}