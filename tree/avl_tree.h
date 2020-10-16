#include "bin_search_tree_impl.h"

template <typename T>
class AVLTree : public binSearchTree<T>
{
    public:
        AVLTree(const char* str) : binSearchTree<T>(str) {}
        virtual binNodePos(T) insert(T const& e) override;
    private:
        binNodePos(T) rotateAt(binNodePos(T) c);
        binNodePos(T) tallerChild(binNodePos(T) x);
};