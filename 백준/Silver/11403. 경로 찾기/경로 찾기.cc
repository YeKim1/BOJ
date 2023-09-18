#include <iostream>
using namespace std;

const int MAX_N = 101;
int N;
int map[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // Initialize the map array
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][k] && map[k][j]) {
                    map[i][j] = 1;
                }
            }
        }
    }

    // Output the result
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
