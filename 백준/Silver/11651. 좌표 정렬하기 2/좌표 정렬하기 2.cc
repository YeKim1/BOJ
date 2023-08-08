#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second < b.second) return true;
    else if (a.second > b.second) return false;
    else { // 같은 경우
        if (a.first < b.first) return true;
        else return false;
    }
}

int main() {
    int N, x, y;

    cin >> N;

    pair<int, int>* p = new pair<int, int>[N];

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }

    sort(p, p + N, compare);
    
    for (int i = 0; i < N; i++) {
        cout << p[i].first << " " << p[i].second << "\n";
    }
}