#include "utility.h"
#include "bitset.h"

#include <set>
#include <fstream>
#include <iterator>
#include <algorithm>

void tests() {

    //generate_file_of_random_integers("local.in", 1, 1000000, 700000);
    /*
    bitset b{100};
    b.set(14);
    b.set(44);
    b.set(99);
    std::cout << "14 == " << b.get(14) << ", 44 == " << b.get(44)
        << ", 45 == " << b.get(45) << ", 99 == " << b.get(99) << std::endl;
    */
}

int main() {
    tests();
    time_measurer t;
    std::set<int> s;
    std::fstream file;
    file.open("local.in", std::ios::in);
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::inserter(s, s.end()));
    std::fstream output;
    output.open("problem1.out", std::ios::out);
    for (const auto& el : s) {
        output << el << std::endl;
    }
}
