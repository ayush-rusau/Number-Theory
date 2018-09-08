#include <bits/stdc++.h>
using namespace std;

long long modIterative(long long a, long long b, long long c) {
    a = a%c;
    long long ans = 1;
    while(b > 0) {
        if(b&1) {
            ans = (ans*a)%c;
           // b = b >> 1;
        }
        a = (a*a)%c;
        b = b>>1;
    }
    return ans;
}

long long modRecursive(long long a, long long b, long long c) {
    if(b == 0) {
        
        return 1;
    }
    if(b%2 == 0) {
        //even
        return modRecursive((a*a)%c, b/2, c);
    } else {
        //Odd
        return ((a%c)*modRecursive((a*a)%c, b/2, c))%c;
    }
}


int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = modRecursive(a, b, c);
    long long ans1 = modIterative(a, b, c);
    cout << ans << endl;
    cout << ans1 << endl;
    return 0;
}