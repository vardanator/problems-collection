#include <vector>
#include <iostream>

int getMaxSpan(const std::vector<int>& vec)
{
    int max_span = 0;
    const std::size_t size = vec.size();
    //const std::size_t half_size = vec.size() / 2 + 1;
    for (int ix = 0; ix < size; ++ix) {
        int jx = size - 1;
        while (jx > ix && vec[jx] != vec[ix]) {
            jx--;
        }
        if ((jx - ix) > max_span) {
            max_span = jx - ix + 1;
        }
    }
    // workaround?
    return (max_span == 0 && vec.size() > 0) ? 1 : max_span;
}

int main()
{
    int arr[] = {1, 2, 1, 1, 3};
    int arr2[] = {1, 4, 2, 1, 4, 1, 4};
    int arr3[] = {1, 4, 2, 1, 4, 4, 4};
    int arr4[] = {3, 3, 3};
    int arr5[] = {3, 9, 9};
    int arr6[] = {1, 2, 3};
    std::cout << getMaxSpan(std::vector<int>(arr, arr + 5)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr2, arr2 + 7)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr3, arr3 + 7)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr4, arr4 + 3)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr5, arr5 + 3)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(0)) << std::endl;
    std::cout << getMaxSpan(std::vector<int>(arr6, arr6 + 1)) << std::endl;

    return 0;
}
