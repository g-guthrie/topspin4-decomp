/* 0x883FB3E8: releases each entry handle (+4, stride 0x20) of the table at +0x10, frees the table, releases the resource at +0x80, then the two sub-objects of the block at +0x20 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the first non-zero error; the block release is an inline helper (the target does addi r31,r31,0x20). */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_8803A098[];
typedef struct Ent { int p0; int obj; char pad[0x18]; } Ent;
typedef struct Sub { int w[6]; } Sub;
typedef struct T { char pad[0xC]; int n; Ent *ents; char p14[0x20 - 0x14]; struct In { int p0, p4; Sub a; Sub b; } in; char p58[0x80 - 0x58]; void *res; } T;
int ts4_if_call_seq_fn_88400C60_88400CD0(int o);
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_if_call_seq_fn_8832F930_88317A28(void *o);
int ts4_if_call_seq_u32_off14_883FAF58(Sub *s);
int ts4_loop_call_seq_u32_off8_883FADF0(Sub *s);
static int in_release(struct In *in)
{
    int r = ts4_if_call_seq_u32_off14_883FAF58(&in->a);
    if (r) return r;
    return ts4_loop_call_seq_u32_off8_883FADF0(&in->b);
}
int ts4_entry_table_release_883FB3E8(T *t)
{
    int i, r;
    if (t->ents) {
        for (i = 0; i < t->n; ++i) {
            if (t->ents[i].obj) {
                r = ts4_if_call_seq_fn_88400C60_88400CD0(t->ents[i].obj);
                if (r) return r;
            }
        }
        fn_88315F10(lbl_88B3302C->heap, t->ents, lbl_8803A098, 0x2aa);
        t->ents = 0;
    }
    if (t->res) {
        r = ts4_if_call_seq_fn_8832F930_88317A28(t->res);
        if (r) return r;
        t->res = 0;
    }
    return in_release(&t->in);
}
