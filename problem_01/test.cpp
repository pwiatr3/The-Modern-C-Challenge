#include <catch2/catch_test_macros.hpp>
int sumOfNumDivBy3and5(int num)
{
    unsigned long int sum = 0;
    for(int i = 0; i <= num; i++) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}
TEST_CASE( "Sum of natural numbers divisible by 3 and 5 are computed", "[factorial]" ) {
    REQUIRE(sumOfNumDivBy3and5(0) == 0);
    REQUIRE(sumOfNumDivBy3and5(2) == 0);
    REQUIRE(sumOfNumDivBy3and5(3) == 3);
    REQUIRE(sumOfNumDivBy3and5(5) == 8);
}