#pragma once

#include <stdint.h>
#include <array>
#include <iostream>

template <size_t c, size_t k>
std::array<std::array<uint32_t, c - k + 1>, c - k + 1> convolute2D(const std::array<std::array<uint32_t, c>, c>& input, const std::array<std::array<uint32_t, k>, k>& kernel)
{
    std::array<std::array<uint32_t, c - k + 1>, c - k + 1> rval;
    for (size_t i = 0; i < rval.size(); i++)
    {
        for (size_t j = 0; j < rval.size(); j++)
        {
            // Get center or corner square 
            // If corner, iterate over other squares (its upper left corner), multiply by index in 
            // If center, iterate over other squares

            size_t convolute = 0;

            for (size_t x = 0; x < k; x++)
            {
                for (size_t y = 0; y < k; y++)
                {
                    convolute += input[i + x][j + y] * kernel[x][y];
                }
            }

            rval[i][j] = convolute;
        }
    }

    return rval;
}

template <uint32_t c, uint32_t k> 
std::array<std::array<uint32_t, c + k - 1>, c + k - 1> deconvolute2D()
{
    
}