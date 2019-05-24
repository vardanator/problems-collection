#include "bitset.h"
#include "utility.h"

#include <fstream>

int main() {
    const int max{10000000};
    // generate_file_of_random_integers("local.in", 1, max, max/2);
    const int first_half_limit = max / 2;
    bitset half_bitset{first_half_limit}; // 0.59Mb
    std::fstream input;
    input.open("local.in", std::ios::in);
    while (!input.eof()) {
        int num;
        input >> num;
        if (num < first_half_limit) {
            half_bitset.set(num);
        }
    }
    std::cout << "reading input done, bitset1 ready" << std::endl;
    std::fstream output;
    output.open("sorted.out", std::ios::out);
    for (int ix = 0; ix < first_half_limit; ++ix) {
        if (half_bitset.get(ix)) {
            output << ix << std::endl;
        }
    }
    std::cout << "half1.out ready" << std::endl;

    half_bitset.reset();
    input.close();
    input.open("local.in", std::ios::in);
    while (!input.eof()) {
        int num;
        input >> num;
        if (num >= first_half_limit) {
            half_bitset.set(num - first_half_limit);
        }
    }
    input.close();
    std::cout << "reading input done, bitset2 ready" << std::endl;

    for (int ix = 0; ix < first_half_limit; ++ix) {
        if (half_bitset.get(ix)) {
            output << (ix + first_half_limit) << std::endl;
        }
    }

}
