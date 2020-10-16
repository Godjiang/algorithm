#include <iostream>
#include <string>
#include "../tree/avl_tree_impl.h"


template <typename T>
void testEveryOrder(binSearchTree<T> &bin_search_tree);

int main ()
{
    char* createString = "6(2(0(,1),4(3,5)),8(7,9))#";
    AVLTree<int> avl_tree(createString);
}

template <typename T>
void testEveryOrder(binSearchTree<T> &bin_search_tree)
{
    auto tree_root = bin_search_tree.root();
    std::cout << "--------- pre order ----------" << std::endl;
    std::string pre_order_0;
    bin_search_tree.PreOrderTraverse(pre_order_0, tree_root);
    std::cout << pre_order_0 << std::endl;
    std::string pre_order_1;
    bin_search_tree.PreOrderIteration(pre_order_1, tree_root);
    std::cout << pre_order_1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    std::cout << "---------  in order ----------" << std::endl;
    std::string in_order_0;
    bin_search_tree.InOrderTraverse(in_order_0, tree_root);
    std::cout << in_order_0 << std::endl;
    std::string in_order_1;
    bin_search_tree.InOrderIteration(in_order_1, tree_root);
    std::cout << in_order_1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    std::cout << "--------- post order ---------" << std::endl;
    std::string post_order_0;
    bin_search_tree.PostOrderTraverse(post_order_0, tree_root);
    std::cout << post_order_0 << std::endl;
    std::string post_order_1;
    bin_search_tree.PostOrderIteration(post_order_1, tree_root);
    std::cout << post_order_1 << std::endl;
    std::cout << "-----------------------------" << std::endl;
}
