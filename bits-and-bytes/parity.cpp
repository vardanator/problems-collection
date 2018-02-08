#include <iostream>

int parity_brute_force(int n)
{
    int result = 0;
    while (n != 0) {
        result ^= (n & 1);
        n >>= 1;
    }
    return result;
}

int parity_faster(int n)
{
    int result = 0;
    while (n != 0) {
        result ^= 1;
        n &= (n - 1);
    }
    return result;
}

int main()
{
    std::cout << "parity of " << 11 << " is " << parity_brute_force(11) << std::endl;
    std::cout << "parity of " << 12 << " is " << parity_brute_force(12) << std::endl;

    std::cout << "fast: " << 11 << " is " << parity_faster(11) << std::endl;
    std::cout << "fast: " << 9 << " is " << parity_faster(9) << std::endl;

    return 0;
}
