//******************************************************
// 5. Sexy prime pairs
// Write a program that prints all the sexy prime pairs
// up to a limit entered by the user.
//******************************************************
#include <iostream>
#include <numeric>

using namespace std;

bool isPrime(int num) {
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}



int main() {

    int limit = 0;
    cout << "Enter limit: ";
    cin >> limit;
    cout << endl;

    for(int i = 2; i <= limit - 6; i++) {
        if(isPrime(i) && isPrime(i + 6)) {
            cout << "Sexy pair is (" << i << ", " << i + 6 <<")" << endl;
        }
    }

    return 0;
}


