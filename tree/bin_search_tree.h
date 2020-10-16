#include <string>
#include "bin_tree_impl.h"

template <typename T>
class binSearchTree : public binTree<T>
{
    public:
        binSearchTree() : binTree<T>() {}
        binSearchTree(const char* str) : binTree<T>() {
            createTreeFromStr(str);
        }
        binNodePos(T) search(T const& e);
        virtual binNodePos(T) insert(T const& e);
        virtual void remove(T const& e);
    private:
        binNodePos(T) hot;
        void createTreeFromStr(const char* str);
};
