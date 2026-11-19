/* 0x883EBC90: releases each 0x28-byte entry (vtable slot 2) of the array at +0x10, frees it and the buffer at +0x18, unloads the resource at +0x1C, releases each 0x18-byte block at +0x20, frees them and clears the fields */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the resource unload error. */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_88039A20[];
typedef struct E E;
typedef struct EVt { void *f0, *f1; void (*release)(E *e); } EVt;
struct E { EVt *vt; char pad[0x24]; };
typedef struct B { char pad[0x18]; } B;
typedef struct T { char pad[0x10]; E *ents; unsigned int nents; void *buf; void *res; B *blocks; unsigned int nblocks; } T;
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_call_seq_fn_883E4E70_883E5060(void *res);
void ts4_if_call_seq_fn_883E9A50_883EBC28(B *b);
int ts4_bank_unload_883EBC90(T *t)
{
    unsigned int i;
    int r;
    for (i = 0; i < t->nents; ++i)
        t->ents[i].vt->release(&t->ents[i]);
    if (t->ents) fn_88315F10(lbl_88B3302C->heap, t->ents, lbl_88039A20, 0x730);
    if (t->buf) fn_88315F10(lbl_88B3302C->heap, t->buf, lbl_88039A20, 0x734);
    if (t->res) {
        r = ts4_call_seq_fn_883E4E70_883E5060(t->res);
        if (r) return r;
    }
    for (i = 0; i < t->nblocks; ++i)
        ts4_if_call_seq_fn_883E9A50_883EBC28(&t->blocks[i]);
    if (t->blocks) fn_88315F10(lbl_88B3302C->heap, t->blocks, lbl_88039A20, 0x741);
    t->nblocks = 0;
    t->blocks = 0;
    t->ents = 0;
    t->res = 0;
    t->nents = 0;
    return 0;
}
