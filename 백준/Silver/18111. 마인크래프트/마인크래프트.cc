#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    int curH = 0;

    int ansS = -1;
    int ansH = 0;

    while (true) {
        int curB = B;
        int curS = 0;
        // 땅 고르기 작업
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] > curH) {
                    curS += ((v[i][j] - curH) * 2);
                    curB += ((v[i][j] - curH) * 1);
                }
                else if (v[i][j] < curH) {
                    curS += ((curH - v[i][j]) * 1);
                    curB -= ((curH - v[i][j]) * 1);
                }
            }
        }
        // 
        if (curB >= 0) {
            if (ansS == -1) {
                ansS = curS;
                ansH = curH;
            }
            
            if (curS < ansS) {
                ansS = curS;
                ansH = curH;
            }
            else if (curS == ansS && curH > ansH) ansH = curH;
        }
        if (++curH > 256) break;
    }

    cout << ansS << " " << ansH;

}