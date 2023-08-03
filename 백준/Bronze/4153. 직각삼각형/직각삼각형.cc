#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    
    while(true) {
        cin >> a >> b >> c;
        if (a==0 && b==0 && c==0) return 0;
        
        if (a >= b && a >= c) {
            int tmp = a;
            a = c;
            c = tmp;
        }
        else if (b >= a && b >= c) {
            int tmp = b;
            b = c;
            c = tmp;
        }
        
        if (a*a + b*b == c*c) cout << "right\n";
        else cout << "wrong\n";
    }
}