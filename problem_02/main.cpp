#include <iostream>

using namespace std;
int gcd(int a, int b);

int main() {

    int a = 282;
    int b = 78;
    cout << gcd(a, b);
    return 0;
}

// int gcd(int a, int b)
// {
//     while(a != b) {
//         if(a > b) {
//             a -= b;
//         }
//         else {
//             b -= a;
//         }
//     }
//     return a;
// }

// recursive
int gcd(int a, int b)
{
    if(a != b) {
        if(a > b) {
            return gcd(a-b, b);
        }
        else {
            return gcd(a, b - a);
        }
    }
    return a;
}