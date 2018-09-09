#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll x, ll p, ll mod) {
    ll ans = 1;
    while(p > 0) {
        if(p&1) {
           ans = (ans*x)%mod;
            
        }
        x = (x*x) % mod;
        p = p >> 1;

    }
    return ans;
}

ll power(ll a, ll p) {
    ll ans = 1;
    for(ll i = a+1;i<p;i++) {
        ll ans1 = f(i, p-2, p);
        ans = ((ans % p) * (ans1%p)) % p;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll p, n;
        cin >> n >> p;
        if(n >= p) {
            cout << "0" << endl;
            continue;
        }

        ll ans = power(n, p);
        ans *= -1;
        ans = ans + p;
        cout << ans << endl;
    }
    return 0;
}