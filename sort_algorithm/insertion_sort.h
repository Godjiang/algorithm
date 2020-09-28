#include <iostream>
#include <stdint.h>

template<typename T>
void insertion_sort(T* data, size_t num)
{
    // 每次循环，都令[:loop_index]的数组变有序
    for (size_t loop_index = 1; loop_index < num; loop_index++) {
        #ifdef DEBUG
        std::cout << "-------------- loop time " << loop_index << " start "
                  << "---------------" << std::endl;
        show_data(data, num);        
        #endif
        T* loop_data = data + loop_index;
        size_t target_index = loop_index;
        // 每次循环，找到[loop_index]需要插入的位置，记录在 target_index 中
        for (size_t order_index = loop_index - 1; order_index >= 0; order_index--) {
            T* order_last_data = data + order_index;
            if ((*loop_data) < (*order_last_data)) {
                target_index = order_index;
            } else {
                break; //前半段
            }
        }
        // 将 [target_index:loop_index - 1] 向后移一位，将[loop_index]插入到[target_index]处
        if ( loop_index > target_index) {
            #ifdef DEBUG
            std::cout << "insert data : " << *(loop_data) << std::endl;
            std::cout << " [" << target_index << ":" << loop_index - 1 << "] right shift"<< std::endl;
            #endif
            T insert_data = *(loop_data);
            for (size_t tmp = loop_index; tmp > target_index; tmp--) {
                *(data + tmp) = *(data + tmp - 1);
            }
            *(data + target_index) = insert_data;
        }
        #ifdef DEBUG
        std::cout << "-------------- loop time " << loop_index << " result "
                  << "--------------" << std::endl;
        show_data(data, num);
        std::cout << "-------------- loop time " << loop_index << " end "
                  << "-----------------" << std::endl << std::endl;
        #endif
    }
}