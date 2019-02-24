#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 

void multiply(ll A[2][2], ll M[2][2]) {
    int a = ((A[0][0]*M[0][0]) % mod + (A[0][1]*M[1][0]) % mod) % mod;
    int b = ((A[0][0]*M[0][1]) % mod + (A[0][1]*M[1][1]) % mod) % mod;
    int c = ((A[1][0]*M[0][0]) % mod + (A[1][1]*M[1][0]) % mod) % mod;
    int d = ((A[1][0]*M[0][1]) % mod + (A[1][1]*M[1][1]) % mod) % mod;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void power(ll A[2][2], int k) {
    if(k==0 || k==1)
       return ;

    power(A, k/2);
    
    multiply(A, A);

    if(k&1) {
        ll M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

ll fib(ll n) {
    ll A[2][2] = {{1, 1}, {1, 0}};
    if(n == 0) {
        return 0;
    }
    power(A, n-1);
    return A[0][0];
}

ll solve(ll n, ll m) {
    ll ans1 = fib(n+2) - 1;
    ll ans2 = fib(m+1) - 1;
    // cout << ans2 << " " << ans1 << endl;
    return (ans1-ans2 + mod) % mod;
}

int main() {
    int t; cin >> t;
    while(t--) {
        long n, m;
        cin >> m >> n;
        ll ans = solve(n, m);
        cout << ans << endl;
    }
    return 0;
}