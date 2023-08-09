#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int cnt[8001] = { 0, };

	cin >> N;

	vector<int> v(N);

	double sum = 0;

	int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
		cnt[v[i] + 4000]++;

		if (cnt[v[i] + 4000] > max) max = cnt[v[i] + 4000];
	}


	sum = (double)round((sum / (double)N));
	if (sum == -0) sum = 0;
	cout << sum << "\n";

	sort(v.begin(), v.end());

	cout << v[v.size() / 2] << "\n";

	vector<int> tmp;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] == max) tmp.push_back(i);
	}

	if (tmp.size() == 1) cout << tmp[0] - 4000 << "\n";
	else {
		sort(tmp.begin(), tmp.end());
		cout << tmp[1] - 4000 << "\n";
	}

	cout << v[v.size() - 1] - v[0] << "\n";

}