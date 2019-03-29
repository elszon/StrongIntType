#include <iostream>

#include "StrongIntType.hpp"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    using ChipId = StrongIntType<struct Chip, unsigned>;
    ChipId id{10};
    std::cout << ChipId{10}.value() << std::endl;

    std::cout << static_cast<unsigned>(id + ChipId{11}) << std::endl;
    return 0;
}
