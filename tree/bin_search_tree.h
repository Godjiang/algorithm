#include <string>
#include "bin_tree_impl.h"

template <typename T>
class binSearchTree : public binTree<T>
{
    public:
        binSearchTree(const char* str) : binTree<T>()
        {
            createTreeFromStr(str);
        }
        binNodePos(T) search(T const& e);
        binNodePos(T) insert(T const& e);
        binNodePos(T) remove(T const& e);
    private:
        void createTreeFromStr(const char* str);
};
