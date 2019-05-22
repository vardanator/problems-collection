#include <cctype>
#include <string>
#include <iostream>
#include <unordered_map>

bool is_permutation(std::string&& str) {
    if (str.empty()) return true;
    std::unordered_map<int, int> count;
    for (auto& ch : str) {
        if (ch != ' ') {
            count[std::tolower((unsigned char)ch)]++;
        }
    }
    bool odd_already_exists = false;
    for (const auto& cnt : count) {
        if (cnt.second % 2 != 0) {
            if (odd_already_exists) return false;
            odd_already_exists = true;
        }
    }
    return true;
}

int main() {
    std::cout << "Tact Coa " << std::boolalpha << is_permutation("Tact Coa") << std::endl;
    std::cout << "Tact Coa " << std::boolalpha << is_permutation("Tact Coap") << std::endl;
}
