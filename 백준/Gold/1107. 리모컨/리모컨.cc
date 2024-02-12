#include <iostream>
#include <climits>
#include <string>
using namespace std;

int n, m;
bool isBreak[10] = { false };

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		isBreak[tmp] = true;
	}

	int ans = INT_MAX;

	// 1. 100번부터 +, -로만 이동
	
	ans = n - 100;
	if (ans < 0) ans *= -1;

	// 2. 버튼을 눌러서 채널 이동 후 +, -로 이동

	for (int i = 0; i <= 1000000; i++) {
		// 2.1 i에 고장난 숫자가 있는지 체크
		string tmpString = to_string(i);
		bool check = true;
		for (int j = 0; j < tmpString.size(); j++) {
			if (isBreak[tmpString[j]-'0'] == true) {
				check = false;
				break;
			}
		}
		
		if (check) {
			int sum = tmpString.size() + abs(n - i);
			ans = min(ans, sum);
		}
	}

	cout << ans;
}