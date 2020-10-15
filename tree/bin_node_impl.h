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