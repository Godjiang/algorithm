#pragma once
#include <iostream>

#define binNodePos(T) binNode<T>*
#define stature(p) ((p) ? (p)->height_ : -1)
#define IsRoot(x) (!((x).parent_))
#define IsLeftChild(x) (!IsRoot(x) && (&(x) == (x).parent_->left_child_))
#define IsRightChild(x) (!IsRoot(x) && (&(x) == (x).parent_->right_child_))
#define HasParent(x) (!IsRoot(x))
#define HasLeftChild(x) ((x).left_child_)
#define HasRightChild(x) ((x).right_child_)
#define HasChild(x) (HasLeftChild(x) || HasRightChild(x))
#define HasBothChild(x) ( HasLeftChild(x) && HasRightChild(x))
#define IsLeaf(x) (!HasChild(x))

/*useful for avl tree*/
#define Balanced(x) (stature((x).left_child_) == stature((x).right_child_))
#define BalFac(x) (stature((x).left_child_) - stature((x).right_child_))
#define AvlBalanced(x) (-2 < BalFac(x) && BalFac(x) < 2)
#define tallerChild(x) (\
    stature((x).left_child_) > stature((x).right_child_) ? (x).left_child_ : ( \
    stature((x).left_child_) < stature((x).right_child_) ? (x).right_child_ : ( \
    IsLeftChild(x) ? (x).left_child_ : (x).right_child_ ) \
    ) \
    )

template <typename T>
struct binNode {
    T data_;
    binNodePos(T) parent_;
    binNodePos(T) left_child_;
    binNodePos(T) right_child_;
    int height_;

    binNode():
        parent_(nullptr), left_child_(nullptr), right_child_(nullptr), height_(0)
    {}

    binNode(T in_data, 
            binNodePos(T) in_parent = nullptr,
            binNodePos(T) in_left_child = nullptr, 
            binNodePos(T) in_right_child = nullptr, 
            int in_height = 0):
        data_(in_data),
        parent_(in_parent), 
        left_child_(in_left_child),
        right_child_(in_right_child),
        height_(in_height)
    {}

    int size();
    binNodePos(T) succ();
    binNodePos(T) insertAsLeftChild(T const& data);
    binNodePos(T) InsertAsRightChild(T const& data);
};