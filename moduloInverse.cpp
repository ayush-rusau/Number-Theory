#include <bits/stdc++.h>
using namespace std;

int g, x, y;

void moduloInverse(int a, int b) {
    if(b == 0) {
        if(a == 1)
            g = 1;
        else 
            g = -1;
        x = 1;
        y = 0;
        return;
    }
    moduloInverse(b, a%b);
    int temp = y;
    y = x - (a/b)*y;
    x = temp;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int a, m;
        cin >> a >> m;
    
        moduloInverse(a, m);
        if(g != -1) {
            cout << (x+m)%m << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}