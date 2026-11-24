/* Swing_DLL.xex 0x8825B800: allocate a 0x20-byte pool node and copy a 16-byte payload into it */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef unsigned int u32;
typedef struct Payload16 { u32 a, b, c, d; } Payload16;
typedef struct Node { char hdr[0x10]; Payload16 value; } Node;
typedef struct Owner { void *pool; } Owner;
extern Node *fn_88613570(void *pool, u32 size, u32 align, Owner *owner);

/* Allocates a 0x20-byte node from the owner's pool and copies the 16-byte payload into it. */
Node *fn_8825B800(Owner *o, const Payload16 *item)
{
    void *pool = o->pool;
    Node *node = fn_88613570(pool, 0x20, 4, o);
    Payload16 *slot = &node->value;
    if (slot) {
        *slot = *item;
    }
    return node;
}
