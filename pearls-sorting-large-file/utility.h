#include <set>
#include <random>
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
    while (count < k) {
        auto num = generate();
        if (numbers.count(num) != 0) continue;
        numbers.insert(num);
        ++count;
    }
    std::cout << "Generated integers: " << numbers.size() << std::endl;

    std::fstream file;
    file.open(filename, std::ios::out);
    for (const auto& num : numbers) {
        file << num << std::endl;
    }
}
