//******************************************************
// 16. Enumerating IPv4 addresses in a range
//******************************************************
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cctype>
#include <sstream>      // std::istringstream

using namespace std;

class ipv4 {
private:
    unsigned int a_;
    unsigned int b_;
    unsigned int c_;
    unsigned int d_;
public:
    constexpr ipv4() : a_(0), b_(0), c_(0), d_(0)  {};
    constexpr ipv4(unsigned int a, 
                    unsigned int b,
                    unsigned int c,
                    unsigned int d) : a_(a), b_(b), c_(c), d_(d) {};
    constexpr ipv4(unsigned long a) :
        a_((a >> 24) & 0xFF),
        b_((a >> 16) & 0xFF),
        c_((a >> 8) & 0xFF),
        d_(a & 0xFF) {};
    friend ostream& operator<<(ostream& os, const ipv4& ip);
    friend std::istream& operator>>(std::istream& is, ipv4& a);
    std::string to_string() const
    {
        std::stringstream sstr;
        sstr << *this;
        return sstr.str();
    }
    constexpr unsigned long to_ulong() const noexcept
    {
        return (static_cast<unsigned long>(a_) << 24) |
        (static_cast<unsigned long>(b_) << 16) |
        (static_cast<unsigned long>(c_) << 8) |
        static_cast<unsigned long>(d_);
    }
    ipv4& operator++(int) {
        *this = ipv4(to_ulong() + 1);
        return *this;   
    }
    bool operator==(const ipv4& b) {
        if(this->a_ = b.a_ && this->b_ == b.b_ && this->c_ == b.c_ && this->d_ == b.d_) {
            return true;
        }
        return false;
    }
    bool operator<(const ipv4& ip) {
        if(this->to_ulong() < ip.to_ulong()) {
            return true;
        }
        return false;
    }
    bool operator>(const ipv4& ip) {
        if(this->to_ulong() > ip.to_ulong()) {
            return true;
        }
        return false;
    }
    bool operator<=(const ipv4& ip) {
        return !(*this > ip);
    }
};

ostream& operator<<(ostream& os, const ipv4& ip) {
    os << ip.a_ << '.' << ip.b_ << '.' << ip.c_ << '.' << ip.d_ << endl;
    return os;
} 
std::istream& operator>>(std::istream& is, ipv4& a) {
    char d1, d2, d3;
    int b1, b2, b3, b4;
    is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;   
    if(d1 == '.' && d2 == '.' && d3 == '.') {
        a = ipv4(b1, b2, b3, b4);
    }
    else {
        is.setstate(std::ios_base::failbit);
    }
     
    return is;
}
int main() {
    ipv4 ip1{1, 2, 3, 0};
    ipv4 ip2{1, 2, 3, 5};
    for(ipv4 ip = ip1; ip <= ip2; ip++) {
        cout<< ip;
    }
    return 0;
}


