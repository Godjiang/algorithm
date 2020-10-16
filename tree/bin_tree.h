#pragma once
#include <stack>
#include <queue>
#include "bin_node_impl.h"

#define FromParentTo(x) \
   (IsRoot(x) ? this->root_ : (IsLeftChild(x) ? (x).parent_->left_child_ : (x).parent_->right_child_))

template <typename T>
class binTree
{
    protected:
        int size_;
        binNodePos(T) root_;
        virtual int updateHeight (binNodePos(T) x); 
        void updateHeightAbove (binNodePos(T) x); 
    public:
        binTree() : size_(0), root_(nullptr) {}
        virtual ~binTree() {
            if (0 < size_) {
                remove(root_);
            }
        }
    int remove(binNodePos(T) x);
    int size() const {return size_;}
    bool empty() const {return !root_;}
    binNodePos(T) root() const {return root_;}
    binNodePos(T) insertAsRoot(T const& e);
    binNodePos(T) insertAsLeftChild(binNodePos(T) x, T const& e);
    binNodePos(T) insertAsRightChild(binNodePos(T) x, T const& e);
    void InOrderTraverse(std::string &outString, binNodePos(T) const &x);
    void InOrderIteration(std::string &outString, binNodePos(T) const &x);
    void PreOrderTraverse(std::string &outString, binNodePos(T) const &x);
    void PreOrderIteration(std::string &outString, binNodePos(T) const &x);
    void PostOrderTraverse(std::string &outString, binNodePos(T) const &x);
    void PostOrderIteration(std::string &outString, binNodePos(T) const &x);
    // binNodePos(T) attachAsLeftChild(binNodePos(T) x, binTree<T>* &T);
    // binNodePos(T) attachAsRightChild(binNodePos(T) x, binTree<T>* &T);

    private:
    void PushToStackForInorder(std::stack<binNodePos(T)> &left_child_stack,
                               binNodePos(T) x);
    void PushToStackForPreorder(std::string &outString,
                                std::stack<binNodePos(T)> &right_child_stack,
                                binNodePos(T) x);
    void PushToQueueForPostorder(std::stack<binNodePos(T)>& left_child_stack,
                                 std::queue<binNodePos(T)>& right_child_queue,
                                 binNodePos(T) x);
};