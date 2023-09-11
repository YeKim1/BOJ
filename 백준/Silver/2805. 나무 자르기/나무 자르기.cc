#include <iostream>
using namespace std;

long long N, M;
long long tree[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    long long max = 0;

    for (long long i = 0; i < N; i++) {
        cin >> tree[i];

        tree[i] > max ? max = tree[i] : max = max;
    }

    long long low = 0;
    long long high = max;
    long long mid;

    long long ans = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        long long sum = 0;

        for (long long i = 0; i < N; i++) {
            if (tree[i] > mid) sum += (tree[i] - mid);
        }

        if (sum >= M) {
            if (ans < mid) {
                ans = mid;
            }
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << ans;

}