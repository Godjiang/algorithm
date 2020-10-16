#include <stack>
#include "bin_search_tree.h"

template <typename T>
binNodePos(T) binSearchTree<T>::search(T const& e)
{
    binNodePos(T) tmpNode = this->root_;
    while(tmpNode)
    {
        hot = tmpNode;
        if (e == tmpNode->data_) {
            return tmpNode;
        } else if (e < tmpNode->data_) {
            tmpNode = tmpNode->left_child_;
        } else if (e > tmpNode->data_) {
            tmpNode = tmpNode->right_child_;
        }
    }
    return tmpNode;
}

template <typename T>
binNodePos(T) binSearchTree<T>::insert(T const& e)
{
    binNodePos(T) insert_pos = search(e);
    if (nullptr != insert_pos) {
        std::cout << "the date you want insert is already in the tree " << std::endl;
        return nullptr;
    } else {
        if (e < hot->data_) {
            return this->insertAsLeftChild(hot, e);
        } else {
            return this->insertAsRightChild(hot, e);
        }
    }
}

template <typename T>
void binSearchTree<T>::remove(T const& e)
{
    binNodePos(T) delete_pos = search(e);
    if (nullptr == delete_pos) {
        std::cout << "the date you want remove is not in the tree " << std::endl;
        return;
    }
    if (HasBothChild(*delete_pos)) {
        binNodePos(T) succ_node = delete_pos->succ();
        T tempData = delete_pos->data_;
        delete_pos->data_ = succ_node->data_;
        succ_node->data_ = tempData;
        if (!HasChild(*succ_node)) {
            FromParentTo(*succ_node) = nullptr;
            this->updateHeightAbove(succ_node->parent_);
            delete succ_node;
        } else if(HasRightChild(*succ_node)) {
            HasRightChild(*succ_node)->parent_ = succ_node->parent_;
            FromParentTo(*succ_node) = HasRightChild(*succ_node);
            this->updateHeightAbove(succ_node->parent_);
            delete succ_node;
        }
    } else if (HasLeftChild(*delete_pos)) {
        HasLeftChild(*delete_pos)->parent_ = delete_pos->parent_;
        FromParentTo(*delete_pos) = HasLeftChild(*delete_pos);
        this->updateHeightAbove(delete_pos->parent_);
        delete delete_pos;

    } else if (HasRightChild(*delete_pos)) {
        HasRightChild(*delete_pos)->parent_ = delete_pos->parent_;
        FromParentTo(*delete_pos) = HasRightChild(*delete_pos);
        this->updateHeightAbove(delete_pos->parent_);
        delete delete_pos;

    } else { // no child
        FromParentTo(*delete_pos) = nullptr;
        this->updateHeightAbove(delete_pos->parent_);
        delete delete_pos;
    }
}

template <typename T>
void binSearchTree<T>::createTreeFromStr(const char* str)
{
    binNodePos(T) last_node;
    std::stack<binNodePos(T)> stack;
    bool isLeftChild = 0;
    int i = 0;
    while('#' != str[i])
    {
        switch(str[i])
        {
            case '(' :
                stack.push(last_node);
                isLeftChild = 1;
                #ifdef DEBUG
                std::cout << "push " << last_node->data_  << " in stack"<< std::endl;
                std::cout << "stack top is " << stack.top()->data_ << std::endl;
                #endif
                break;
            case ',' :
                isLeftChild = 0;
                break;
            case ')' :
                stack.pop();
                break;
            default:
                T data = str[i] - 48;
                if(nullptr == this->root()) {
                    last_node = this->insertAsRoot(data);
                } else if (1 == isLeftChild) {
                    #ifdef DEBUG
                    std::cout << "parent is : " << stack.top()->data_ << std::endl;
                    std::cout << "parent's left child is : " << data << std::endl;
                    #endif
                    last_node = this->insertAsLeftChild(stack.top(), data);
                } else if (0 == isLeftChild){
                    #ifdef DEBUG
                    std::cout << "parent is : " << stack.top()->data_ << std::endl;
                    std::cout << "parent's right child is : " << data << std::endl;
                    #endif
                    last_node = this->insertAsRightChild(stack.top(), data);
                }
                break;
        }
        #ifdef DEBUG
        std::string inorder_string;
        std::cout << "this time tree inorder is : " << std::endl;
        this->InOrderIteration(inorder_string, this->root());
        std::cout << inorder_string << std::endl;
        std::cout << "********************************" << std::endl;
        #endif
        i++;
    }
}