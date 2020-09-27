#include <iostream>
#include <stdint.h>

template<typename T>
void show_data(T* data, uint8_t num)
{
    for (int i = 0; i < num; i++) {
        std::cout << *(data + i) << " ";
    }
    std::cout << std::endl;
}