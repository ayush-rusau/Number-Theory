#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mk make_pair

bool sieve[1000005];
unordered_map<int, int> mappy;

void create() {
    int count = 1;
    for(ll i = 2;i<=1000000;i++) {
        if(sieve[i]) {
            ll val = i*i*i;
            for(ll j = 1;j*val<=1000000;j++) {
                sieve[j*val] = false;
            }
        }
    }
    for(int i = 1;i<=1000000;i++) {
        if(sieve[i]) {
            mappy.insert(mk(i, count++));
            // count++;
        }
    }
}

int main() {
    memset(sieve, true, sizeof sieve);
    create();
    int t;
    cin >> t;
    for(int i = 1;i<=t;i++) {
        
        int n;
        cin >> n;
        cout << "Case " << i << ": ";
        if(sieve[n]) {
            cout << mappy[n] << endl;
        } else {
            cout << "Not Cube Free" << endl;
        }
    }
    return 0;

}