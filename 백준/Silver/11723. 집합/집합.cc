#include <iostream>
using namespace std;

bool s[21];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int M, x;
    
    cin >> M;
    
    string str;
    
    while(M--) {
        cin >> str;
        
        if (str=="add") {
            cin >> x;
            s[x] = 1;
        }
        else if (str=="remove") {
            cin >> x;
            s[x] = 0;
        }
        else if (str=="check") {
            cin >> x;
            cout << s[x] << "\n";
        }
        else if (str=="toggle") {
            cin >> x;
            if (s[x]) s[x] = 0;
            else s[x] = 1;
        }
        else if (str=="all") {
            for (int i=1;i<=20;i++) s[i] = 1;
        }
        else if (str=="empty") {
            for (int i=1;i<=20;i++) s[i] = 0;
        }
    }
}