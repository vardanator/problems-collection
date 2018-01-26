#include <vector>
#include <iostream>

void print_v(const std::vector<int>& vec, const std::string& prefix = "") {
    std::cout << prefix << std::endl;
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

std::vector<int> getProductsOfAllIntsExceptAtIndex(const std::vector<int>& vec)
{
    std::vector<int> before(vec.size(), 1);

    int products = 1;
    std::size_t vec_size = vec.size();
    for (std::size_t ix = 0; ix < vec_size; ++ix) {
        before[ix] = products;
        products *= vec[ix];
    }
    products = 1;
    for (int ix = vec_size - 1; ix >= 0; --ix) {
        before[ix] *= products;
        products *= vec[ix];
    }

    return before;
}

int main()
{
    std::vector<int> integers;
    integers.push_back(1);
    integers.push_back(7);
    integers.push_back(3);
    integers.push_back(4);

    for (auto elem : getProductsOfAllIntsExceptAtIndex(integers)) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
