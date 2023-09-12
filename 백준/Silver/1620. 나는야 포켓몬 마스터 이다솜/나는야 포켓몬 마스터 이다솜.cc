#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string s;
map<int, string> m_int;
map<string, int> m_str;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> s;
        m_int[i] = s;
        m_str[s] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> s;

        if (s[0] >= 'A' && s[0] <= 'Z') {
            cout << m_str[s] << "\n";
        }
        else {
            int tmp = stoi(s);
            cout << m_int[tmp] << "\n";
        }
    }
}