
#include <string>
#include <iostream>

std::string withoutString(std::string base, const std::string& remove)
{
    std::string::size_type pos = std::string::npos;
    while ((pos = base.find(remove)) != std::string::npos) {
        base.erase(pos, remove.size());
    }
    return base;
}

int main()
{
    std::cout << "withoutString(\"Hello there\", \"llo\") → " << withoutString("Hello there", "llo") << std::endl;
    std::cout << "withoutString(\"Hello there\", \"e\") → " << withoutString("Hello there", "e") << std::endl;
    std::cout << "withoutString(\"Hello there\", \"x\") → " << withoutString("Hello there", "x") << std::endl;
}
