//******************************************************
// 14. Validating ISBNs
//******************************************************
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cctype>

using namespace std;

bool validate_isbn_10(std::string isbn) {
    
    // Removing hypens from isbn number
    auto noHypenEnd = remove(begin(isbn), end(isbn), '-');
    isbn.erase(noHypenEnd, end(isbn));

    if(isbn.length() == 10 && count_if(begin(isbn), end(isbn), [](unsigned char c){ return std::isdigit(c); }) == 10) {
        size_t index = 0;
        auto w = 1;

        int sum = accumulate(begin(isbn), end(isbn) - 1, 0, [&w](int const total, const char c) {                                                                            
                                                                        return total + w++ * (c - '0');  
                                                                    });
        if((sum % 11) == (isbn.back() - '0')) {
            return true;
        }         
    }
    return false;
}

int main() {

    std::string isbn {"0306406152"};
    //std::string isbn {"0-306-40615-2"};
    cout << "Is ISBN number: " << boolalpha << validate_isbn_10(isbn);

    return 0;
}


