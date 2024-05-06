#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
bool selected[14];

int ans = INT_MAX;

int countDistance(pair<int, int> house, pair<int, int> chicken) {
	int rCnt = house.first - chicken.first;
	int cCnt = house.second - chicken.second;

	if (rCnt < 0) rCnt *= -1;
	if (cCnt < 0) cCnt *= -1;

	return rCnt + cCnt;
}

int countAllDistance(vector<vector<int>> map) {
	int sum = 0;
	for (int house = 0; house < houses.size(); house++) {
		int min_dis = INT_MAX;
		for (int chicken = 0; chicken < chickens.size(); chicken++) {
			if (selected[chicken]) {
				min_dis = min(min_dis, map[chicken][house]);
			}
		}
		sum += min_dis;
	}
	return sum;
}

void dfs(vector<vector<int>> map, int cur, int depth) {
	if (depth == M) {
		ans = min(ans, countAllDistance(map));
		return;
	}

	for (int i = cur; i < chickens.size(); i++) {
		selected[i] = true;
		dfs(map, i + 1, depth + 1);
		selected[i] = false;
	}

}

int main() {
	cin >> N >> M;

	int tmp;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> tmp;
			if (tmp == 1) houses.push_back(make_pair(r, c));
			if (tmp == 2) chickens.push_back(make_pair(r, c));
		}
	}

	vector<vector<int>> map(chickens.size(), vector<int>(houses.size()));

	for (int house = 0; house < houses.size(); house++) {
		for (int chicken = 0; chicken < chickens.size(); chicken++) {
			map[chicken][house] = countDistance(houses[house], chickens[chicken]);
			//cout << map[chicken][house] << " ";
		}
		//cout << "\n";
	}

	dfs(map, 0, 0);

	cout << ans;

	/*
	  0 1 2 3 4
	0 2 6 7 6 5
	1 2 2 3 4 7
	2 2 4 5 4 5
	3 5 3 4 3 2
	4 6 4 5 4 1
	5 6 4 3 2 1
	*/

}
