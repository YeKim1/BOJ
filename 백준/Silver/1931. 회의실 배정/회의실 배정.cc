#include <iostream>
#include <algorithm>
using namespace std;

int n, s, e;
int ans = 0;

pair<int, int> t[100000];

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second < p2.second) return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first) return true;
		else return false;
	}
	else return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;

		t[i] = make_pair(s, e);
	}

	sort(t, t + n, compare);

	pair<int, int> cur = t[0];
	ans++;

	for (int i = 1; i < n; i++) {
		if (t[i].first >= cur.second) {
			cur = t[i];
			ans++;
		}
	}

	cout << ans;
}