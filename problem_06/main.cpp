//******************************************************
// 6. Abundant numbers
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
    int sumOfProperDivisors = 1;

    cout << "Enter limit: ";
    cin >> limit;
    cout << endl;

    for(int i = 2; i <= limit / 2; i++) {
        if(limit % i == 0) {
            cout << i << " ";
            sumOfProperDivisors += i;
        } 
    }
    if(sumOfProperDivisors > limit) {
        cout << "Num " << limit << " is an abundant number!" << endl;
    }
    else {
        cout << "Num " << limit << " is not an abundant number!" << endl;
    }

    return 0;
}


