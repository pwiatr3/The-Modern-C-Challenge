#include <iostream>
#include <numeric>

using namespace std;
//int gcd(int a, int b);
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main() {

    int a = 15;
    int b = 20;
    cout << lcm(a, b);

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

