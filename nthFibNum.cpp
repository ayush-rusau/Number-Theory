// Nth Fibo number in O(log(N)) using matrix exponentiation

#include <iostream>
using namespace std;

void multiply(int A[2][2], int M[2][2]) {
    int a = A[0][0]*M[0][0] + A[0][1]*M[1][0];
    int b = A[0][0]*M[0][1] + A[0][1]*M[1][1];
    int c = A[1][0]*M[0][0] + A[1][1]*M[1][0];
    int d = A[1][0]*M[0][1] + A[1][1]*M[1][1];

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}


void power(int A[2][2], int n) {
    if(n==0 || n==1)
       return ;

    power(A, n/2);
    
    //Multiplying A^n/2 with A^n/2
    multiply(A, A);

    if(n&1) {
        int M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

int fib(int n) {
    int A[2][2] = {{1, 1}, {1, 0}};
    if(n == 0) {
        return 0;
    }
    power(A, n-1);
    return A[0][0];
}

int main() {
    int n;
    cin >> n;
    
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}