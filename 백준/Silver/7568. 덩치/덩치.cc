#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, x, y;

    cin >> N;

    pair<int, int>* p = new pair<int, int>[N];

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }

    for (int i = 0; i < N; i++) {
        int cnt = 1;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (p[i].first < p[j].first && p[i].second < p[j].second) cnt++;
            }
        }
        cout << cnt << " ";
    }

}