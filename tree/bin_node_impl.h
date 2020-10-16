#include "bin_node.h"

template <typename T>
binNodePos(T) binNode<T>::insertAsLeftChild(T const& data)
{
    return left_child_ = new binNode(data, this);
}

template <typename T>
binNodePos(T) binNode<T>::InsertAsRightChild(T const& data)
{
    return right_child_ = new binNode(data, this);
}

template <typename T>
int binNode<T>::size()
{
    int size = 1;
    if (left_child_) {
        size += left_child_->size();
    }
    if (right_child_) {
        size += right_child_->size();
    }
    return size;
}
template <typename T>
binNodePos(T) binNode<T>::succ()
{
    binNodePos(T) current_node = this;
    if (HasRightChild(*current_node)) { // succ一定是右子树的最左点
        current_node = HasRightChild(*current_node);
        while(HasLeftChild(*current_node)) {
            current_node = HasLeftChild(*current_node);
        }
    } else { //succ一定是一直往左上追寻到底，再取parent的点
        while(IsRightChild(*current_node)) {
            current_node = current_node->parent_;
        }
        current_node = current_node->parent_;
    }
    return current_node;
}