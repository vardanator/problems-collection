#include "bitset.h"
#include "utility.h"

#include <fstream>

int main() {
    const int max = 10000000;
    //generate_file_of_random_integers("local.in", 1, max, max/2);

    time_measurer t;
    bitset b{max};
    std::fstream file;
    file.open("local.in", std::ios::in);
    while (!file.eof()) {
        int num;
        file >> num;
        b.set(num);
    }
    std::fstream output;
    output.open("sorted.out", std::ios::out);
    for (int ix = 0; ix < max; ++ix) {
        if (b.get(ix)) {
            output << ix << std::endl;
        }
    }
    
}
