#include <vector>
#include <iostream>

std::vector<int> getProductsOfAllIntsExceptAtIndex(const std::vector<int>& vec)
{
    std::vector<int> results(vec.size(), 1);

    for (std::size_t ix = 0; ix < vec.size(); ++ix) {
        for (std::size_t jx = 0; jx < vec.size(); ++jx) {
            if (jx == ix) continue;
            results[ix] *= vec[jx];
        }
    }
    return results;
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
