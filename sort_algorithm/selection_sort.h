#include <iostream>
#include <stdint.h>

template<typename T>
void selection_sort(T* data, size_t num)
{
    std::cout << "choose selection sort ." << std::endl;
    // 每次循环结束，令 [current_loop] 的值为本次循环最小值
    for (size_t current_loop = 0; current_loop < num - 1; current_loop++) {
        #ifdef DEBUG
        std::cout << "-------------- loop time " << current_loop + 1 << " start "
                  << "---------------" << std::endl;
        show_data(data, num);        
        #endif
        size_t smaller_index = current_loop;
        T* target_data = data + current_loop;
        T* smaller_data = data + current_loop;
        // 每次循环结束，找到本次最小值，记录在 smaller_data 中
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
        // target_data <==> smaller_data
        T temp = *target_data;
        *target_data = *smaller_data;
        *smaller_data = temp;
        #ifdef DEBUG
        std::cout << "-------------- loop time " << current_loop + 1 << " result "
                  << "--------------" << std::endl;
        show_data(data, num);
        std::cout << "-------------- loop time " << current_loop + 1 << " end "
                  << "-----------------" << std::endl << std::endl;
        #endif
    }
}