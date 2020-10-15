#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include "bin_tree.h"

template <typename T>
int binTree<T>::updateHeight(binNodePos(T) x)
{
    return x->height_ = 1 + std::max(stature(x->left_child_), stature(x->left_child_));
}

template <typename T>
void binTree<T>::updateHeightAbove(binNodePos(T) x)
{
    while (x) {
        updateHeight(x);
        x = x->parent_;
    }
}

template <typename T> 
static int removeAt(binNodePos(T) x)
{
   if (!x) {
       return 0;
   }
   int n = 1 + removeAt(x->left_child_) + removeAt(x->right_child_); 
   delete x;
   return n;
}

template <typename T>
int binTree<T>::remove(binNodePos(T) x)
{
    FromParentTo(*x) = nullptr;
    updateHeightAbove(x->parent_);
    int n = removeAt(x);
    size_ -= n;
    return n; 
}

template <typename T>
binNodePos(T) binTree<T>::insertAsRoot(T const& e)
{
    if (root_ != nullptr) {
        std::cout << "this tree has root!" << std::endl;
    } else {
        size_++;
        return root_ = new binNode<T>(e);
    }
}

template <typename T>
binNodePos(T) binTree<T>::insertAsLeftChild(binNodePos(T) x, T const& e)
{
    size_++;
    x->insertAsLeftChild(e);
    updateHeightAbove(x);
    return x->left_child_;
}

template <typename T>
binNodePos(T) binTree<T>::insertAsRightChild(binNodePos(T) x, T const& e)
{
    size_++;
    x->InsertAsRightChild(e);
    updateHeightAbove(x);
    return x->right_child_;
}

template <typename T>
void binTree<T>::PushToStackForInorder(std::stack<binNodePos(T)> &left_child_stack,
                                       binNodePos(T) x)
{
    while(nullptr != x) {
        #ifdef DEBUG
        std::cout << "push " << x->data_ << " to stack"<< std::endl;
        #endif
        left_child_stack.push(x);
        x = x->left_child_;
    }
}

template <typename T>
void binTree<T>::InOrderIteration(std::string &outString, binNodePos(T) const &x)
{
    std::stack<binNodePos(T)> left_child_stack;
    PushToStackForInorder(left_child_stack, x);
    #ifdef DEBUG
    std::cout << "stack size : " << left_child_stack.size() << std::endl;
    #endif

    while(0 != left_child_stack.size()) {
        binNodePos(T) currentNode = left_child_stack.top();
        outString += std::to_string(currentNode->data_);
        outString += " ";
        left_child_stack.pop();
        if (nullptr != HasRightChild(*currentNode)) {
            PushToStackForInorder(left_child_stack, HasRightChild(*currentNode));
        }
    }
}

template <typename T>
void binTree<T>::InOrderTraverse(std::string &outString, binNodePos(T) const &x)
{
    if (nullptr == x) {
        return;
    }
    InOrderTraverse(outString, x->left_child_);
    outString += std::to_string(x->data_);
    outString += " ";
    InOrderTraverse(outString, x->right_child_);
}

template <typename T>
void binTree<T>::PushToStackForPreorder(std::string &outString,
                                        std::stack<binNodePos(T)> &right_child_stack,
                                        binNodePos(T) x)
{
    while(nullptr != x) {
        outString += std::to_string(x->data_);
        outString += " ";
        if (nullptr != HasRightChild(*x)) {
            right_child_stack.push(x->right_child_);
        }
        x = x->left_child_;
    }
}

template <typename T>
void binTree<T>::PreOrderIteration(std::string &outString, binNodePos(T) const &x)
{
    std::stack<binNodePos(T)> right_child_stack;
    PushToStackForPreorder(outString, right_child_stack, x);
    #ifdef DEBUG
    std::cout << "pre order : " << outString << std::endl;
    std::cout << "stack size : " << right_child_stack.size() << std::endl;
    #endif

    while(0 != right_child_stack.size()) {
        auto tmpNode = right_child_stack.top();
        right_child_stack.pop();
        PushToStackForPreorder(outString, right_child_stack, tmpNode);
    }
}

template <typename T>
void binTree<T>::PreOrderTraverse(std::string &outString, binNodePos(T) const &x)
{
    if (nullptr == x) {
        return;
    }
    outString += std::to_string(x->data_);
    outString += " ";
    PreOrderTraverse(outString, x->left_child_);
    PreOrderTraverse(outString, x->right_child_);
}

template <typename T>
void binTree<T>::PushToQueueForPostorder(std::stack<binNodePos(T)>& left_child_stack,
                                         std::queue<binNodePos(T)>& right_child_queue,
                                         binNodePos(T) x)
{
    while(nullptr != x) {
        right_child_queue.push(x);
        if (nullptr != HasLeftChild(*x)) {
            left_child_stack.push(HasLeftChild(*x));
        }
        x = x->right_child_;
    }
}

template <typename T>
void binTree<T>::PostOrderIteration(std::string &outString, binNodePos(T) const &x)
{
    std::stack<binNodePos(T)> left_child_stack;
    std::queue<binNodePos(T)> right_child_queue;
    PushToQueueForPostorder(left_child_stack, right_child_queue, x);

    while(0 != left_child_stack.size()) {
        auto tmpNode = left_child_stack.top();
        left_child_stack.pop();
        PushToQueueForPostorder(left_child_stack, right_child_queue, tmpNode);
    }

    #ifdef DEBUG    
    std::cout << "reverse order queue" << std::endl;   
    #endif
    auto size_num = right_child_queue.size();
    for(int i = 0; i < size_num; i++) {
        #ifdef DEBUG
        // std::cout << right_child_queue.front()->data_ << std::endl;
        #endif
        left_child_stack.push(right_child_queue.front());
        right_child_queue.pop();
    }

    for(int i = 0; i < size_num; i++) {
        outString += std::to_string(left_child_stack.top()->data_);
        outString += " ";
        left_child_stack.pop();
    }
}

template <typename T>
void binTree<T>::PostOrderTraverse(std::string &outString, binNodePos(T) const &x)
{
    if (nullptr == x) {
        return;
    }
    PostOrderTraverse(outString, x->left_child_);
    PostOrderTraverse(outString, x->right_child_);   
    outString += std::to_string(x->data_);
    outString += " ";
}