/* 0x8815D480: SGI STL _Rb_tree_base_iterator::_M_increment: in-order successor of a red-black tree node (parent +4, left +8, right +0xC) */
/* Matched on /Oc (agAL). Plain route, first try with the textbook SGI body. */
typedef struct RbNode RbNode;
struct RbNode { int color; RbNode *parent; RbNode *left; RbNode *right; };

RbNode *ts4_rb_tree_increment_8815D480(RbNode *x)
{
    if (x->right != 0) {
        x = x->right;
        while (x->left != 0)
            x = x->left;
    } else {
        RbNode *y = x->parent;
        while (x == y->right) {
            x = y;
            y = y->parent;
        }
        if (x->right != y)
            x = y;
    }
    return x;
}
