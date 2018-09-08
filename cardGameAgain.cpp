#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sieve(ll k, ll* s) {
    vector <bool> prime(k+1,false);

    for(int i = 2;i<=k;i+=2) {
        s[i] = 2;
    }
    for(int i = 3;i<=k;i+=2) {
        if(prime[i] == false) {
            s[i] = i;

            for(int j = i;j*i<=k;j+=2) {
                if(prime[i*j] == false) {
                    prime[i*j] = true;

                    s[i*j] = i;
                }
            }
        }
    }
}

void generate(ll k, ll* s) {
    sieve(k, s);

    ll curr = s[k];
    int count = 1;

    while(k > 1) {
        k /= s[k];
        if(curr == s[k]) {
            count++;
            continue;
        }

        curr = s[k];
        count = 1;
    }
}

int main() {
    ll n, k;
    ll* a = new ll[n];
    // for(int i =0;i<n;i++) {
    //     cin >> a[i];
    // }
    
    ll s[k+1];
    cout << s[k] << endl;
    generate(k, s);
    return 0;
}