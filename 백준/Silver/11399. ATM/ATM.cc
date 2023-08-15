#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) { cin >> v[i]; }

	sort(v.begin(), v.end());

	int sum = 0;
	int cur = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (cur + v[i]);
		cur += v[i];
	}

	cout << sum;
}