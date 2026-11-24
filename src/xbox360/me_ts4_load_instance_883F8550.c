/* 0x883F8550: loader: reads the id, creates a def (883F2F40) and an instance (883DBC98) from the node's allocator, binds them (883E2AC8, 883E13B8, def ref++), advances the root bank's used size by 0x90 and loads the instance (883E1F70; released through 883E3018 on error); 0x2C on allocation failure */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
extern const char lbl_88039FA4[];
typedef struct Alloc Alloc;
typedef struct Def { char pad[8]; int refs; } Def;
typedef struct Node Node;
typedef struct Inst { char pad[0x20]; Node *node; } Inst;
typedef struct Bank { char pad[0x40]; int used; } Bank;
typedef struct Owner { Node *node; } Owner;
typedef struct Sub { char pad[0x7c]; Alloc *alloc; } Sub;
typedef struct Sys { char pad[0x30]; Sub *sub; } Sys;
struct Node { char pad[0x28]; Sys *sys; char pad2[0xa8 - 0x2c]; Bank *bank; Owner *owner; };
typedef struct T { int p0; Node *node; int p8; int id; Inst *inst; } T;
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);
Def *ts4_if_get_u32_lbl_88B3302C_883F2F40(Alloc *a, int b, const char *file, int line);
Inst *ts4_if_get_u32_lbl_88B3302C_883DBC98(Alloc *a, int b, const char *file, int line);
int ts4_if_get_u32_off10_883E2B30(Def *d, Alloc *a);
void fn_883E2AC8(Def *d);
int fn_883E13B8(Inst *i, Def *d);
int fn_883E1F70(Inst *i, void *stream, void *arg);
int fn_883E3018(Inst *i, Alloc *a, unsigned char deep);

static Node *owner_node(Node *n) { return n->owner ? n->owner->node : 0; }

int fn_883F8550(T *t, void *stream, void *arg)
{
    Alloc *a;
    Def *d;
    Inst *in;
    int r;
    r = fn_883194F0(stream, &t->id, 4, 1, 0);
    if (r)
        return r;
    a = t->node->sys->sub->alloc;
    d = ts4_if_get_u32_lbl_88B3302C_883F2F40(a, 0, lbl_88039FA4, 0x72e);
    if (!d)
        return 0x2c;
    in = ts4_if_get_u32_lbl_88B3302C_883DBC98(a, 0, lbl_88039FA4, 0x736);
    if (!in) {
        ts4_if_get_u32_off10_883E2B30(d, a);
        return 0x2c;
    }
    fn_883E2AC8(d);
    fn_883E13B8(in, d);
    d->refs++;
    {
        Node *o = t->node;
        Bank *bk = owner_node(o) ? owner_node(o)->bank : o->bank;
        o->bank->used = bk->used + 0x90;
    }
    r = fn_883E1F70(in, stream, arg);
    if (r) {
        fn_883E3018(in, a, 1);
        return r;
    }
    in->node = t->node;
    t->inst = in;
    return 0;
}
