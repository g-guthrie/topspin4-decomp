/* 0x884BFA40: Gets a 32-byte pair of vectors from the node virtual at slot 7 (arg passed through) into a stack temp, then hands it to fn_884779E8(node->target (+0x10), &temp), which stores it at target+0xa0. */
/* Matched on /Oc (agAH). 16-byte aligned __vector4 pair from vx1_vector.h gives the 0x80 frame with the temp at 0x50. */
#include "vx1_vector.h"
typedef struct Bounds { __vector4 lo; __vector4 hi; } Bounds;
typedef struct Node Node;
typedef struct NodeVtbl { void *slot0[7]; void (*getBounds)(Node *n, int arg, Bounds *out); } NodeVtbl;
struct Node { NodeVtbl *vtable; char pad[0xc]; void *target; };
void fn_884779E8(void *target, const Bounds *b);
void fn_884BFA40(Node *n, int arg)
{
    Bounds b;
    n->vtable->getBounds(n, arg, &b);
    fn_884779E8(n->target, &b);
}
