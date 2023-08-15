#include <iostream>
using namespace std;

int main() {
	
	int N, K, A;

	cin >> N >> K;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		while ((sum + arr[i]) <= K) {
			sum += arr[i];
			cnt++;
		}

		if (sum == K) break;
	}

	cout << cnt;



}