#include <iostream>
#include <cstdint>

template<typename T>
void bubble_sort(T* data, size_t num)
{
    // loop (length of data - 1) time, get biggest data every loop.
    for (size_t current_loop_len = num - 1; current_loop_len > 0; current_loop_len--) {
        #ifdef DEBUG
        std::cout << "-------------- loop time " << (num - current_loop_len) << " start "
                  << "---------------" << std::endl;
        #endif
        for (size_t current_index = 0; current_index < current_loop_len; current_index++) {
            T* current_data = data + current_index;
            T* bigger_data = data + current_index + 1;
            #ifdef DEBUG
            std::cout << *current_data << " - " << *bigger_data << " change to ";
            #endif
            if (*current_data > *bigger_data) {
                T temp = *current_data;
                *current_data = *bigger_data;
                *bigger_data = temp;
            }
            #ifdef DEBUG
            std::cout << *current_data << " - " << *bigger_data << std::endl;
            #endif
        }
        #ifdef DEBUG
        std::cout << "-------------- loop time " << (num - current_loop_len) << " result "
                  << "--------------" << std::endl;
        show_data(data, num);
        std::cout << "-------------- loop time " << (num - current_loop_len) << " end "
                  << "-----------------" << std::endl << std::endl;
        #endif
    }
}
