#include <iostream>
#include <string>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    int ans = A * B * C;
    
    string s = to_string(ans);
    int cnt[10] = {0};
    for (int i=0;i<s.length();i++) {
        cnt[s[i] - '0']++;
    }
    
    for (int i=0;i<10;i++) {
        cout << cnt[i] << "\n";
    }
}