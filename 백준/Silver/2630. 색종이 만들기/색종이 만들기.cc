#include <iostream>
using namespace std;

int white = 0;
int blue = 0;
int N;

int paper[129][129];

void func(int x_start, int y_start, int cur) {
    int tmp;
    for (int y=y_start;y<=y_start+cur-1;y++) {
        for (int x=x_start;x<=x_start+cur-1;x++) {
            if (x==x_start && y==y_start) {
                tmp = paper[x][y];
            }
            else {
                if (paper[x][y] != tmp) {
                    func(x_start, y_start, cur/2);
                    func(x_start+cur/2, y_start, cur/2);
                    func(x_start, y_start+cur/2, cur/2);
                    func(x_start+cur/2, y_start+cur/2, cur/2);
                    return;
                }
            }
        }
    }
    
    if (tmp==0) white++;
    else blue++;
} 

int main() {
    cin >> N;
    
    for (int y=1;y<=N;y++) {
        for (int x=1;x<=N;x++) {
            cin >> paper[x][y];
        }
    }
    
    func(1, 1, N);
    
    cout << white << "\n" << blue;
}