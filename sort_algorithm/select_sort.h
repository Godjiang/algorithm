#include <iostream>
#include <stdint.h>

template<typename T>
void select_sort(T* data, size_t num)
{
    for (size_t current_loop = 0; current_loop < num - 1; current_loop++) {
        #ifdef DEBUG
        std::cout << "-------------- loop time " << current_loop << " start "
                  << "---------------" << std::endl;
        show_data(data, num);        
        #endif
        size_t smaller_index = current_loop;
        T* target_data = data + current_loop;
        T* smaller_data = data + current_loop;
        for (size_t current_index = current_loop + 1; current_index < num - 1; current_index++) {
            T* loop_data = data + current_index;
            if (*loop_data < *smaller_data) {
                smaller_data = loop_data;
            }
        }
        #ifdef DEBUG
        std::cout << "target data : " << *target_data << std::endl;
        std::cout << "smaller data : " << *smaller_data << std::endl;
        #endif
        T temp = *target_data;
        *target_data = *smaller_data;
        *smaller_data = temp;
        #ifdef DEBUG
        std::cout << "-------------- loop time " << current_loop << " result "
                  << "--------------" << std::endl;
        show_data(data, num);
        std::cout << "-------------- loop time " << current_loop << " end "
                  << "-----------------" << std::endl << std::endl;
        #endif
    }
}