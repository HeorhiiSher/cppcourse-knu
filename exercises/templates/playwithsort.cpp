#include "OrderedVector.hpp"
#include "Complex.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ranges>

struct ReverseStringLess {
    bool operator() (const std::string &s, const std::string &t) const {
        // TODO: compare reversed strings
        // hint: you can use:
        // - std::views::reverse
        // - std::ranges::lexicographical_compare
        // or, if your compiler does not support those yet,
        // take copies of the strings and reverse them using std::reverse
        std::string copy_s = s;
        std::string copy_t = t;
        std::reverse(copy_s.begin(), copy_s.end());
        std::reverse(copy_t.begin(), copy_t.end());
        return copy_s < copy_t;
    }
};

struct ManhattanLess {
    bool operator() (const Complex &a, const Complex &b) const {
        return std::abs(a.real()) + std::abs(a.imaginary()) < std::abs(b.real()) + std::abs(b.imaginary());
    }
};

int main() {
    std::cout << "Integer\n";
    OrderedVector<int> v(10);
    for (int i = 10; i > 0; i--)
        v.add(i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string> vs(5);
    vs.add(std::string("one"));
    vs.add(std::string("two"));
    vs.add(std::string("three"));
    vs.add(std::string("four"));
    vs.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs[i] << " ";
    std::cout << "\n\n";

    // TODO: Demonstrate OrderedVector with Complex as element type similar to above

    std::cout << "Complex\n";
    OrderedVector<Complex> c(10);
    for (int i = 10; i>0; i--) {
        c.add(Complex(i,i));
    }
    
    for (int i = 0; i<10; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "String reverse\n";
    OrderedVector<std::string, ReverseStringLess> vs_2(5);
    vs_2.add(std::string("one"));
    vs_2.add(std::string("two"));
    vs_2.add(std::string("three"));
    vs_2.add(std::string("four"));
    vs_2.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs_2[i] << " ";
    std::cout << "\n\n";

    std::cout << "Complex Manhattan\n";
    OrderedVector<Complex, ManhattanLess> c_2(10);
    for (int i = 10; i>0; i--) {
        c_2.add(Complex(i,i));
    }
    
    for (int i = 0; i<10; i++) {
        std::cout << c_2[i] << " ";
    }
    std::cout << "\n\n";

    // TODO: Extend OrderedVector to allow to customize the ordering via an additional template paramter.
    //       Then, demonstrate the new functionality by ordering an OrderedVector<std::string>,
    //       where the strings are compared starting at their last letters.


    // TODO: Order an OrderedVector of Complex based on the Manhattan distance


}
