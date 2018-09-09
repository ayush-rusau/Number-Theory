#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

void multiply(long long A[2][2], long long M[2][2]) {
    int a = ((A[0][0] %mod *M[0][0]%mod) + (A[0][1]%mod * M[1][0]%mod))%mod;
    int b = ((A[0][0] %mod *M[0][1]%mod) + (A[0][1]%mod * M[1][1]%mod))%mod;
    int c = ((A[1][0] %mod *M[0][0]%mod) + (A[1][1]%mod * M[1][0]%mod))%mod;
    int d = ((A[1][0] %mod *M[0][1]%mod) + (A[1][1]%mod * M[1][1]%mod))%mod;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void power(long long A[2][2], long n) {
    if(n==0 || n==1) {
        return ;
    }

    power(A, n/2);
    multiply(A, A);

    if(n&1) {
        long long M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

unsigned long long fib(long n) {
    long long A[2][2] = {{1, 1}, {1, 0}};
    if(n == 0) {
        return 0;
    }
    power(A, n-1);
    return A[0][0];
}

unsigned long long solve(long long n, long long m) {
    unsigned long long ans1 = fib(n);
    unsigned long long ans2 = fib(m);
    cout << ans2 << " " << ans1 << endl;
    return ans2-ans1;
}

int main() {
    long n, m;
    cin >> n >> m;
    unsigned long long ans = solve(n+1, m+2);
    cout << ans << endl;
    return 0;
}