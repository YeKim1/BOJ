#include <iostream>
using namespace std;

int num[100001];
int sum[100001];
int N, M, i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    int tmp = 0;
    for (int cnt = 1; cnt <= N; cnt++) {
        sum[cnt] = sum[cnt - 1] + num[cnt];
    }

    while (M--) {
        cin >> i >> j;

        if (i == 1) cout << sum[j] << "\n";
        else {
            cout << sum[j] - sum[i - 1] << "\n";
        }
    }
}