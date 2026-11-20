/* 0x883EA1F8 near miss (1 off, /O1): visits each 0x1C-byte entry with a stack visitor (vtable lbl_880398A0), frees the entries, unloads two resources and frees each block's data and the block array. */
/* Residue: add r10,r30,r10 (offset first) for t->blocks[i]; member, pointer arithmetic, i[arr], helper and C++ forms all give add r10,r10,r30. */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_88039A20[];
extern char lbl_880398A0[];
typedef struct Visit { const void *vt; int a; int b; } Visit;
typedef struct E { char pad[0xC]; char sub[0x10]; } E;
typedef struct B { int p0, p4; void *data; } B;
typedef struct T { char pad[0x10]; E *ents; unsigned int nents; void *res; B *blocks; unsigned int nblocks; void *res2; } T;
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_call_seq_fn_883E4E70_883E5060(void *res);
void ts4_if_get_u32_off8_883E74F0(void *sub, Visit *v);
int ts4_bank_unload2_883EA1F8(T *t)
{
    unsigned int i;
    int r;
    Visit v;
    for (i = 0; i < t->nents; ++i) {
        v.vt = lbl_880398A0;
        v.b = 0;
        ts4_if_get_u32_off8_883E74F0(t->ents[i].sub, &v);
        v.vt = lbl_880398A0;
    }
    if (t->ents) fn_88315F10(lbl_88B3302C->heap, t->ents, lbl_88039A20, 0x9d8);
    if (t->res) {
        r = ts4_call_seq_fn_883E4E70_883E5060(t->res);
        if (r) return r;
    }
    t->ents = 0;
    t->res = 0;
    t->nents = 0;
    if (t->blocks) {
        for (i = 0; i < t->nblocks; ++i)
            fn_88315F10(lbl_88B3302C->heap, t->blocks[i].data, lbl_88039A20, 0x9e8);
        fn_88315F10(lbl_88B3302C->heap, t->blocks, lbl_88039A20, 0x9eb);
    }
    if (t->res2) {
        r = ts4_call_seq_fn_883E4E70_883E5060(t->res2);
        if (r) return r;
    }
    t->blocks = 0;
    t->res2 = 0;
    t->nblocks = 0;
    return 0;
}
