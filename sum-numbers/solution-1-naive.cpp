#include <cctype>
#include <string>
#include <vector>
#include <iostream>

// Works only for positive integers
int sumNumbers(const std::string& raw)
{
    int sum = 0;
    for (int ix = 0; ix < raw.size(); ) {
        int current_number = 0;
        while (std::isdigit(raw[ix++])) {
            current_number *= 10;
            current_number += (raw[ix - 1] - '0');
        }
        sum += current_number;
    }
    return sum;
}

int main()
{
    std::cout << "abc123xyz -> " << sumNumbers("abc123xyz") << std::endl;
    std::cout << "aa11b33 -> " << sumNumbers("aa11b33") << std::endl;
    std::cout << "7 11 -> " << sumNumbers("7 11") << std::endl;

    return  0;
}
