#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define MAX 9

int N, M;
int arr[MAX];

vector<int> ans(MAX, 0);
bool visit[MAX];

set<vector<int>> s;


void func(int start, int depth) {
    if (depth == M) {
        s.insert(vector<int>(ans.begin(), ans.begin() + M));
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            ans[depth] = arr[i];
            visit[i] = true;
            func(start, depth + 1);
            visit[i] = false;
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        ans[0] = arr[i];
        visit[i] = true;
        func(i, 1);
        for (int j = 0; j < N; j++) {
            visit[i] = false;
        }
    }

    for (const auto& vec : s) {
        for (int i = 0; i < M; i++) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
}