#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define pb push_back
vector<ll> primes;
bool sieve[50005];

void create() {
    for(int i = 2;i<=50000;i++) {
        if(sieve[i]) {
            for(int j = 2*i;j<=50000;j+=i) {
                sieve[j] = false;
            }
            primes.pb(i);
        }
    }
}

int main(){
	// Write your code here
    memset(sieve, true, sizeof sieve);
    create();
    int t;
    cin >> t;
    while(t--) {
        ll ans = 1;
        ll n; cin >> n;
        if(n == 0) {
            cout << "1" << endl;
            continue;
        }
        if(n == 1) {
            cout << "1" << endl;
            continue;
        }
        for(int i = 0;i<primes.size() && primes[i] <= n;i++) {
            ll count = 0;
            ll val = primes[i];
            while(n/val > 0) {
                count += (n/val);
                val *= primes[i];
            }
            ans = ((ans%mod) * (count+1)%mod)%mod;
        }
        cout << ans << endl;
    }
	return 0;
}