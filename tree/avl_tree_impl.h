#include "avl_tree.h"

template <typename T>
binNodePos(T) AVLTree<T>::insert(T const& e)
{
    binNodePos(T) insert_pos = this->insert(e);
    if (nullptr != insert_pos) {
        std::cout << "the date you want insert is already in the tree " << std::endl;
        return nullptr;
    }

    for (binNodePos(T) current_pos = hot;
         nullptr != current_pos;
         current_pos = current_pos->parent_) {
        if (!AvlBalanced(current_pos)) {
            FromParentTo(current_pos) = rotateAt(current_pos);
            // original hole tree is balanced, insertion only affects one node
            // because height before rotate equal after rotate
            break;
        }
    }
    return insert_pos;
}

template <typename T>
binNodePos(T) AVLTree<T>::rotateAt(binNodePos(T) c)
{
    binNodePos(T) b = tallerChild(*c);
    binNodePos(T) a = tallerChild(*b);
    if (IsLeftChild(b) && IsLeftChild(a)) {
        // t1 = a->left_child_
        // t2 = a->right_child_
        // t3 = b->right_child_
        // t4 = c->right_child_

    } else if(IsLeftChild(b) && IsRightChild(a)) {
        // t1 = b->left_child_
        // t2 = a->left_child_
        // t3 = a->right_child_
        // t4 = c->right_child_

    } else if(IsRightChild(b) && IsRightChild(a)) {
        // t1 = c->left_child_
        // t2 = b->left_child_
        // t3 = a->left_child_
        // t4 = a->right_child_

    } else if(IsRightChild(b) && IsLeftChild(a)) {
        // t1 = c->left_child_
        // t2 = a->left_child_
        // t3 = a->right_child_
        // t4 = b->right_child_

    }

}

template <typename T>
binNodePos(T) AVLTree<T>::connect34(binNodePos(T) a,
                                    binNodePos(T) b,
                                    binNodePos(T) c,
                                    binNodePos(T) t1,
                                    binNodePos(T) t2,
                                    binNodePos(T) t3,
                                    binNodePos(T) t4)
{
    
}