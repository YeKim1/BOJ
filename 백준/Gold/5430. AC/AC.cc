#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, n, x;
    string p, xArr;

    cin >> T;

    while (T--) {
        cin >> p >> n;
        deque<int> Q;
        
        cin >> xArr;

        string tmp = "";
        for (int i = 0; i < xArr.length(); i++) {
            if (xArr[i] >= '0' && xArr[i] <= '9') {
                tmp += xArr[i];
            }
            else if (xArr[i] == ',') {
                Q.push_back(stoi(tmp));
                tmp = "";
            }
        }
        if (tmp != "") Q.push_back(stoi(tmp));

        bool isReverse = 0;
        bool isError = 0;
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                isReverse = !isReverse;
            }
            else if (p[i] == 'D') {
                if (Q.empty())  isError = 1;
                else {
                    if (isReverse) Q.pop_back();
                    else Q.pop_front();
                }
            }
        }

        if (isError) cout << "error";
        else {
            if (Q.empty()) cout << "[]";
            else if (isReverse) {
                cout << "[";
                for (int i = Q.size() - 1; i > 0; i--) {
                    cout << Q[i] << ",";
                }
                cout << Q[0] << "]";
            }
            else {
                cout << "[";
                for (int i = 0; i < Q.size() - 1; i++) {
                    cout << Q[i] << ",";
                }
                cout << Q[Q.size() - 1] << "]";
            }
        }
        cout << "\n";
    }
}