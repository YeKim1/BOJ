#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(const int a, const int b) {
		int tmp_a = (a < 0) ? -a : a;
		int tmp_b = (b < 0) ? -b : b;

		if (tmp_a < tmp_b) return false;
		if (tmp_a > tmp_b) return true;

		return a > b;
	}
};


priority_queue<int, vector<int>, compare> pq;

int main() {
	int N, x;

	cin >> N;

	while (N--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}