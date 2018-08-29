#include <iostream>
using namespace std;

class triplet {
    public:
    int gcd;
    int x;
    int y;
};

triplet gcdExtendedEuclid(int a, int b) {
    //Base Case
    if(b == 0) {
        triplet myAns;
        myAns.gcd = a;
        myAns.x = 1;
        myAns.y = 0;
        return myAns;
    }
    triplet smallAns = gcdExtendedEuclid(b, a%b);
    
     //Extended euclid says
    triplet myAns;
    myAns.gcd = smallAns.gcd;
    myAns.x = smallAns.y;
    myAns.y = smallAns.x - (a/b)*smallAns.y;
    return myAns;
}

int main() {
    int a = 16;
    int b = 10;
    triplet ans = gcdExtendedEuclid(a, b);
    cout << ans.gcd << " " << ans.x << " " << ans.y << endl;
    return 0;
}