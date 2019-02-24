#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007

void multiply(ll A[2][2], ll M[2][2]) {
    int a = (A[0][0]*M[0][0]%mod + A[0][1]*M[1][0]%mod) % mod;
    int b = (A[0][0]*M[0][1]%mod + A[0][1]*M[1][1]%mod) %mod;
    int c = (A[1][0]*M[0][0]%mod + A[1][1]*M[1][0]%mod) %mod;
    int d = (A[1][0]*M[0][1]%mod + A[1][1]*M[1][1]%mod) % mod;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void power(ll A[2][2], ll n) {
    if(n == 0 || n == 1) {
        return ;
    }

    power(A, n);

    multiply(A, A);

    if(n&1) {
        ll M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

pair <ll, ll> fib(ll n) {
    ll A[2][2] = {{1, 1}, {1, 0}};

    if(n == 0) {
        pair <ll, ll> p;
        p.first = p.second = 0;
        return p;
    }

    power(A, n-1);

    pair <ll ,ll> p;
    p.first = A[0][0];
    p.second = A[0][1];

    return p;
}

ll powerExpo(ll a, ll b) {
    a = a%mod;
    ll ans = 1;
    while(b > 0) {
        if(b&1) {
            ans = (ans*a) % mod;
        }
        b = b >> 1;
        a = (a*a) % mod;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, n;
        cin >> a >> b >> n;

        pair <ll, ll> p = fib(n-1);
        
        ll ans1 = powerExpo(1+a, p.first);
        ll ans2 = powerExpo(1+b, p.second);

        ll ans = ((ans1%mod) * (ans2%mod)) % mod - 1;
        cout << ans << endl;
    }
    return 0;
}