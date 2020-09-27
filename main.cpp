#include "include/common.h"
#include "algorithm/bubble_sort.h"
#include "algorithm/select_sort.h"

int main()
{
    float data[10] = {1, 5, 5, 7, 9, 9, 4, 0, 8, 10};
    std::cout << "input data : ";
    show_data(data, 10);

    // bubble_sort(data, 10);
    // select_sort(data, 10);

    std::cout << "result data : ";
    show_data(data, 10);
    return 0;
}