/* 0x883E2E78: climbs the parent chain (+0x54) to the topmost node and returns whether it is the root recorded by its owner (+0x18, root at +0x30); 0 without owner. */
/* Matched on /O1 (agAB). The climb is an inline root() with an early return; compare written owner->root == top. */
typedef struct N N;
typedef struct O { char p[0x30]; N *root; } O;
struct N { char p[0x18]; O *o; char p1c[0x54 - 0x1c]; N *up; };
static N *root(N *n) { N *p; if (!n->up) return n; for (p = n->up; p->up; p = p->up) ; return p; }
unsigned char fn_883E2E78(N *n)
{
    N *top = root(n);
    if (top->o)
        return top->o->root == top;
    return 0;
}
