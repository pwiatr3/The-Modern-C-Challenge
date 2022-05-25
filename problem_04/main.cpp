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

    int num = 0;
    cout << "Enter number: ";
    cin >> num;
    cout << endl;
    if(num <= 2) {
        cout << "The number is too small";
        return -1;
    }
    for(int i = num - 1; i >= 2; i--) {
        if(isPrime(i)) {
            cout << "Largest prime smaller than " << num << " is " << i << endl;
            return 0;
        }
    }

    return 0;
}


