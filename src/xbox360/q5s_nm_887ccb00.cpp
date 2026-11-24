/* Swing_DLL.xex 0x887CCB00: Ts4CtlFactory::Create — virtual slot 16 of the
 * vtable at lbl_880EA318. Allocates a node with
 * ts4_if_call_seq_u32_lbl_88D45B38_88211A08 and initialises it with
 * fn_887CCA98(node, a, b); when the init fails the node is destroyed through
 * its vtable slot 0 (deleting destructor, flag 1) and 0 is returned.
 * The `this` pointer is not used: r3 passes through to the allocator unchanged.
 * The failure path is written as `node = 0` falling through to the shared
 * return; an early `return 0` puts li r4,1 before mr r3 (3 off). */
struct Ts4CtlNode {
    virtual void Destroy(int del);
};

extern "C" Ts4CtlNode *ts4_if_call_seq_u32_lbl_88D45B38_88211A08(void);
extern "C" unsigned char fn_887CCA98(Ts4CtlNode *node, void *a, void *b);

struct Ts4CtlFactory {
    virtual Ts4CtlNode *Create(void *a, void *b);
};

Ts4CtlNode *Ts4CtlFactory::Create(void *a, void *b)
{
    Ts4CtlNode *node = ts4_if_call_seq_u32_lbl_88D45B38_88211A08();
    if (node && !fn_887CCA98(node, a, b)) {
        node->Destroy(1);
        node = 0;
    }
    return node;
}
