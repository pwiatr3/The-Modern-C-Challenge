//******************************************************
// 17. Creating a 2D array with basic operations
//******************************************************
#include <iostream>
#include  <exception>
#include <vector>

using namespace std;
template<class T, size_t R, size_t C>
class array2d {
    
public:
    T arr[R][C] {0};
    array2d() {}
    constexpr array2d(std::initializer_list<T> init_list) {
        if((R * C) != init_list.size()) {
            throw length_error("Initilalizer list has wrong size");
        }
        auto it = begin(init_list);
        for( int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                arr[row][col] = *it++;
            }
        }
    }
    constexpr size_t size(const int rank) const {
        if(rank == 1) {
            return R;
        }
        if(rank == 2) {
            return C;
        }
        throw out_of_range("Rank can be 1 or 2!");
    }
    constexpr T* data() {
        return &arr[0][0];
    }
    constexpr const T* data() const {
        return &arr[0][0];
    }
    constexpr T& at(size_t row, size_t col) {
        if(row >= 0 && row < R && col >= 0 && col < C) {
            return arr[row][col];
        }
        throw out_of_range("Array index is out of range!");
    }
    constexpr const T& at(size_t row, size_t col) const {
        if(row >= 0 && row < R && col >= 0 && col < C) {
            return arr[row][col];
        }
        throw out_of_range("Array index is out of range!");
    }
    constexpr void print() const {
        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                cout << arr[row][col] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    void fill(const T& value) {
        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                arr[row][col] = value;
            }
        }
    }
    void swap(array2d& other) {

        T temp;
        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                temp = this->at(row, col);
                this->at(row, col) = other.at(row, col);
                other.at(row, col) = temp;
            }
        }
    }
};

int main() {
    array2d<int, 2, 3> arr {1, 2, 3, 4, 5, 6};
    arr.print();
    arr.at(0,0) = 4;
    arr.print();
    int* ptr = arr.data();
    ptr[0] = 1;
    // for(int i = 0; i < arr.size(1) * arr.size(2); i++) {
    //     cout << ptr[i] << ' ';
    // }
    // cout << endl;
    arr.print();
    arr.fill(1);
    arr.print();


    // const array2d<int, 1, 3> arr1 {0, 1, 2};
    // arr1.print();
    // cout << arr1.at(0, 2);
    // const int* ptr1 = arr1.data();

    array2d<int, 2, 3> arr2 {0, 1, 2, 3, 4, 5};
    arr.swap(arr2);
    arr.print();
    arr2.print();
    return 0;
}


