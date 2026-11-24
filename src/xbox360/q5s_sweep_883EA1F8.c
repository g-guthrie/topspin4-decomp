/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x883EA1F8: visits each 0x1C-byte entry with a stack visitor (vtable lbl_880398A0), frees the entries, unloads two
 * resources and frees each block's data and the block array. Flags /O1.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_883EA1F8_nearmiss.c (Q5S sweep, 2026-11-24): the `rpadN` locals are OP1 symbol-numbering pads (docs/agents/regalloc.md, family `pad`); the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2).
 * See work/specs/Q5S/sweep_883EA1F8.json for route and flags. */
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
{ int rpad0 = 0; int rpad1 = 0; int rpad2 = 0; int rpad3 = 0; int rpad4 = 0; int rpad5 = 0; int rpad6 = 0; int rpad7 = 0;  T* bank = t;  T* bank2 = bank; 
    unsigned int i;
    int r;
    Visit v;
    for (i = 0; i < bank2->nents; ++i) {
        v.vt = lbl_880398A0;
        v.b = 0;
        ts4_if_get_u32_off8_883E74F0(bank2->ents[i].sub, &v);
        v.vt = lbl_880398A0;
    }
    if (bank2->ents) fn_88315F10(lbl_88B3302C->heap, bank2->ents, lbl_88039A20, 0x9d8);
    if (bank->res) {
        r = ts4_call_seq_fn_883E4E70_883E5060(bank->res);
        if (r) return r;
    }
    bank2->ents = 0;
    bank2->res = 0;
    bank->nents = 0;
    if (bank2->blocks) {
        for (i = 0; i < bank2->nblocks; ++i)
            fn_88315F10(lbl_88B3302C->heap, bank2->blocks[i].data, lbl_88039A20, 0x9e8);
        fn_88315F10(lbl_88B3302C->heap, bank2->blocks, lbl_88039A20, 0x9eb);
    }
    if (bank2->res2) {
        r = ts4_call_seq_fn_883E4E70_883E5060(bank2->res2);
        if (r) return r;
    }
    bank2->blocks = 0;
    bank2->res2 = 0;
    bank2->nblocks = 0;
    return 0;
}
