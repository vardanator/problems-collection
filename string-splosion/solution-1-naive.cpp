#include <string>
#include <iostream>

std::string stringSplosion(const std::string& src)
{
    std::string res = "";
    for (int ix = 0; ix < src.size(); ++ix) {
        res += src.substr(0, ix + 1);
    }
    return res;
}

int main()
{
    std::cout << stringSplosion("Code") << std::endl;
    std::cout << stringSplosion("") << std::endl;
    std::cout << stringSplosion("ab") << std::endl;
    return 0;
}
