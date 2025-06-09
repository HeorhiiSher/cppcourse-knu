#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

template<typename T>
struct squared_sum {
    T operator()(const T& sum, const T& x) { return sum + x * x; };
};

template<typename T>
struct Generator {
    T m_value, m_step;
    Generator(T initial, T step):m_value(initial), m_step(step){};
    T operator()() {
        T cur_value = m_value;
        m_value += m_step;
        return cur_value;
    }
};

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    std::generate(v.begin(), v.end(), Generator<T>(initial, step));
    std::shuffle(v.begin(), v.end(), std::default_random_engine{});

    // compute differences
    std::adjacent_difference(v.begin(), v.end(), diffs.begin());

    // compute standard deviation of all differences
    const T sum = std::reduce(diffs.begin()+1, diffs.end());
    const T sumsq = std::accumulate(diffs.begin()+1, diffs.end(), T(), squared_sum<T>());
    const T mean = sum/len;
    const T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    compute(1000, 0.0, 7.0);
    // call compute here with Complex
    compute(1000, Complex(0,0), Complex(4,5));
}
