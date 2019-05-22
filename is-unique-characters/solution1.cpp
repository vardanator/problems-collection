#include <iostream>
#include <string>
#include <bitset>

bool is_all_unique(const std::string& str) {
    if (!str.size()) return true;
    std::bitset<256> mask;
    for (const char& c : str) {
        if (mask[(int)c]) {
            return false;
        }
        mask.set((int)c);
    }
    return true;
}

int main() {
    std::cout << is_all_unique("abcdefg123") << std::endl;
    std::cout << is_all_unique("aabcd") << std::endl;
    return 0;
}
