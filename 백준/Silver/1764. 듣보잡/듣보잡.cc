#include <iostream>
#include <map>
using namespace std;

int N, M, cnt{0};
string s;
map<string, int> m;

int main() {
    cin >> N >> M;
    
    for (int i=0;i<N+M;i++) {
        cin >> s;
        m[s]++;
        if (m[s]==2) cnt++;
    }
    cout << cnt << "\n";
    
    for (map<string,int>::iterator iter = m.begin();iter!=m.end();iter++) {
        if (iter->second==2) {
            cout << iter->first << "\n";        
        }
    }
   
}