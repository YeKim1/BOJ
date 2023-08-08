#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    
    cin >> N;
    
    int cnt = 1;
    string cur = "666";
    while(true) {
        if (cnt==N) break;
        
        int tmp = stoi(cur) + 1;
        cur = to_string(tmp);
        
        if (cur.find("666") != string::npos) cnt++;
    }
    
    cout << cur;
}