#include <iostream>
#include <string>
#include "../tree/bin_search_tree_impl.h"

int main ()
{
    char* createString = "6(2(0(,1),4(3,5)),8(7,9))#";
    // char* createString = "A(B(C(,D),E(F,G)),H(I,J))#";
    binSearchTree<int> bin_search_tree(createString);
    auto tree_root = bin_search_tree.root();
    std::cout << "tree size is : " << bin_search_tree.size() << std::endl;
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