#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int T, N, M, P;

    cin >> T;

    while (T--) {
        cin >> N >> M;

        queue<int> q;
        for (int i = 0; i < N; i++) {
            q.push(i);
        }

        vector<vector<int>> priority(10);
        for (int i = 0; i < N; i++) {
            cin >> P;
            priority[P].push_back(i);
        }

        int cnt = 0;
        bool flag = 1;
        while (flag) {
            int max_priority = -1;
            for (int i = 9; i >= 1; i--) {
                if (priority[i].size() != 0) {
                    max_priority = i;
                    break;
                }
            }

            if (max_priority == -1) break;

            while (!priority[max_priority].empty()) {
                while (find(priority[max_priority].begin(), priority[max_priority].end(), q.front()) == priority[max_priority].end()) {
                    int tmp = q.front();
                    q.pop();
                    q.push(tmp);
                }
                cnt++;
                if (q.front() == M) {
                    cout << cnt << "\n";

                    flag = 0;
                    break;
                }
                priority[max_priority].erase(find(priority[max_priority].begin(), priority[max_priority].end(), q.front()));
                q.pop();
            }
        }
    }
}