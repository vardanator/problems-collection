#include <vector>
#include <iomanip>
#include <iostream>


bool canBalance(const std::vector<int>& arr)
{
    std::vector<int> left(arr.size(), 0);
    std::vector<int> right(arr.size(), 0);
    const std::size_t size = arr.size();
    left[0] = arr[0];
    right[size - 1] = arr[size - 1];
    for (int ix = 1; ix < arr.size(); ++ix) {
        left[ix] = left[ix - 1] + arr[ix];
        right[size - ix - 1] = right[size - ix] + arr[size - ix - 1];
    }

    for (int ix = 0; ix < left.size() - 1; ++ix) {
        if (left[ix] == right[ix + 1]) return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 1};
    int arr2[] = {2, 1, 1, 2, 1};
    int arr3[] = {10, 10};
    std::cout << "Can balance [1, 1, 1, 2, 1]: " << std::boolalpha << canBalance(std::vector<int>(arr, arr + 5)) << std::endl;
    std::cout << "Can balance [2, 1, 1, 2, 1]: " << std::boolalpha << canBalance(std::vector<int>(arr2, arr2 + 5)) << std::endl;
    std::cout << "Can balance [10, 10]: " << std::boolalpha << canBalance(std::vector<int>(arr3, arr3 + 2)) << std::endl;
}
