#include <iostream>
using namespace std;
#define N 1000001
int prime[1000001];

void gen2(int **a) {
    a[0][0] = 1;
    a[0][1] = 2;
    for(int i = 2;i<N;i++)
        a[0][i] = a[0][1];
    for(int i = 0;i<=10;i++) {
        for(int j = 0;j<N;j++) {
            if(j == 0 || j == 1) {
                a[i][j] = 0;
                
            } else if(prime[j] == i) {
                a[i][j] = a[i][j-1] + 1;
            } else {
                a[i][j] = a[i][j-1];
            }
        }
    }
}

void generate() {
    for(int i = 0;i<N;i++) {
        prime[i] = 0;
    }

    for(int i = 2;i<N;i++) {
        if(prime[i] == 0) {
            for(int j = i;j<N;j+=i) {
                prime[j]++;
            }
        }
    }
}

int main() {
    generate();

    int t;
    cin >> t;
    int **a = new int*[11];
    for(int i = 0;i<11;i++) {
        a[i] = new int[N];
    }
    gen2(a);
    while(t--) {
        int x, y, n;
        cin >> x >> y >> n;
        if(n == 0 && x == 1) {
            cout << "1" << endl;
        } else {
            int ans = a[n][y] - a[n][x-1];
            cout << ans << endl;
        }
    }
    return 0;
}