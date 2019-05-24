#include <set>
#include <random>
#include <chrono>
#include <fstream>
#include <iostream>
#include <exception>

void generate_file_of_random_integers(const std::string& filename, int start, int end, int k) {
    if (filename.empty() || start < 0 || end < 0) throw std::invalid_argument("");
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dis(start, end);
    auto generate{std::bind(dis, gen)};
    std::set<int> numbers;
    int count = 0;
    std::fstream file;
    file.open(filename, std::ios::out);
    while (count < k) {
        auto num = generate();
        if (numbers.count(num) != 0) continue;
        numbers.insert(num);
        ++count;
        file << num << std::endl;
    }
    std::cout << "Generated integers: " << numbers.size() << std::endl;
}

class time_measurer {
public:
    time_measurer() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~time_measurer() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << std::endl << diff.count() << " seconds" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};
