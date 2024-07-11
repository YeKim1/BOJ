#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9

int N, M;
int arr[MAX];

set<vector<int>> s;
vector<int> ans(MAX, 0);

void func(int start, int depth) {
	if (depth == M) {
		s.insert(vector<int>(ans.begin(), ans.begin() + M));
		return;
	}

	for (int i = start; i < N; i++) {
		ans[depth] = arr[i];
		func(i, depth + 1);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	int num;
	set<int> tmp;
	for (int i = 0; i < N; i++) {
		cin >> num;
		tmp.insert(num);
	}

	int idx = 0;
	for (int i : tmp) {
		arr[idx++] = i;
	}

	N = idx;

	for (int i = 0; i < N; i++) {
		func(i, 0);
	}

	for (auto& v : s) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}

}