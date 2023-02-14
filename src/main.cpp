#include "conv.h"
#include <iostream>

int main(void)
{
    std::array<std::array<uint32_t, 4>, 4> init({{
        {2, 3, 5, 2},
        {1, 6, 3, 1},
        {2, 8, 7, 2},
        {5, 3, 4, 1},
    }});

    std::array<std::array<uint32_t, 2>, 2> kernel({{
        {2, 3},
        {1, 5}
    }});

    auto output = convolute2D(init, kernel);

    for (auto o1 : output)
    {
        for (auto x : o1)
        {
            std::cout << x << ", ";
        }
        std::cout << "\n" << std::endl;
    }
}