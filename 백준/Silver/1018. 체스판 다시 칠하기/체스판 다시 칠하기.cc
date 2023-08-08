#include <iostream>
using namespace std;

string B_start[] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string W_start[]{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

int main() {
	int N, M;

	cin >> N >> M;

	string* s = new string[N];

	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}

	int min = 65;

	for (int i = 0; i < N; i++) {
		if ((N-i) >= 8) {
			for (int j = 0; j < M; j++) {
				if ((M-j) >= 8) {

					int cnt = 0;

					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {
							if (s[i + k][j + l] != B_start[k][l]) cnt++;
						}
					}

					if (cnt < min) min = cnt;
					
					cnt = 0;

					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {
							if (s[i + k][j + l] != W_start[k][l]) cnt++;
						}
					}

					if (cnt < min) min = cnt;
				}
			}
		}
	}

	cout << min;
}