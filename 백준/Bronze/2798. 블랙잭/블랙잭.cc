#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cout.tie();

    int N, M;

    cin >> N >> M;

    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum;
    int min = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j != i) {
                for (int k = 0; k < N; k++) {
                    if (k != i && k != j) {
                        sum = arr[i] + arr[j] + arr[k];
                        if (sum <= M && sum > min) min = sum;
                    }
                }
            }
        }
    }

    cout << min;

}