#include <string>
#include <iostream>

bool check_rotation(const std::string& s1, const std::string& s2)
{
    if (s1.size() != s2.size() || (s1.empty() && s2.empty())) return false;
    if (s1 == s2) return true;
    auto s2_index = s2.size() - 1;
    auto s1_index = s1.find(s2[s2_index]);
    if (s1_index == std::string::npos) return false;
    while (s1_index > 0) {
        --s2_index;
        --s1_index;
        if (s1[s1_index] != s2[s2_index]) return false;
    }
    if (s2_index == 0) return true;
    auto cut = s2.substr(0, s2_index);
    return (s1.find(cut) != std::string::npos);
}

int main() {
    std::cout << "waterbottle vs erbottlewat: " << check_rotation("waterbottle", "erbottlewat") << std::endl;
    std::cout << "waterbottle vs waterbottle: " << check_rotation("waterbottle", "waterbottle") << std::endl;
    std::cout << "hello vs nollo: " << check_rotation("hello", "nollo") << std::endl;
    std::cout << "utercomp vs computer: " << check_rotation("utercomp", "computer") << std::endl;
    std::cout << "butter vs googol: " << check_rotation("butter", "googol") << std::endl;
}
