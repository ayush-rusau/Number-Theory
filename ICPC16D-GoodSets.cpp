#include <bits/stdc++.h>
using namespace std;
#define N 750000
#define ll long long
#define mod 1000000007


int main() {
    int t;
    cin >> t;
    while(t--) {
        ll* a = new ll[N+1];
        for(int i = 0;i<=N;i++) {
            a[i] = 0;
        }
       // int max = INT_MIN;
        int n;
        cin >> n;
        for(int i = 0;i<n;i++) {
            int temp;
            cin >> temp;
            // if(temp > max)
            //    max = temp;
            a[temp]++;
        }

        for(int i = 1;i<=N/2;i++) {
            if(a[i]) {
                for(int j = i*2;j<=N;j+=i) {
                    if(a[j] && j!=i) {
                        a[j] += a[i];
                    }
                }
            }
        }

        // for(int i = 0;i<=max;i++) {
        //     cout << a[i] << " ";
        // }

        ll ans = 0;
        for(int i = 0;i<=N;i++) {
            ans = (ans % mod + a[i]%mod) % mod;
        }
        cout << ans << endl;
        delete [] a;
    }
    return 0; 
}