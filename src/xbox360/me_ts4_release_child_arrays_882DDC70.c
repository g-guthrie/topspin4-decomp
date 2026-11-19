/* 0x882DDC70: releases every child in the arrays at +0x38 and +0x3C (counts are the info halfwords at +0xA and +8) and frees both arrays and the block at +0x40 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); the child is read into a local before the null test; with t->a[i] used twice the call gets a clrrwi. */
typedef struct Info { char pad[8]; unsigned short nb; unsigned short na; } Info;
typedef struct T { char pad[0x18]; Info *info; char p1c[0x38 - 0x1C]; void **a; void **b; void *c; } T;
void ts4_if_call_seq_fn_882DDC70_882E0E28(void *o, int del);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, unsigned int tag);
void ts4_release_child_arrays_882DDC70(T *t)
{
    unsigned int i; void *o;
    if (t->a) {
        for (i = 0; i < t->info->na; ++i)
            if ((o = t->a[i]) != 0) ts4_if_call_seq_fn_882DDC70_882E0E28(o, 1);
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->a, 0x24810000);
    }
    if (t->b) {
        for (i = 0; i < t->info->nb; ++i)
            if ((o = t->b[i]) != 0) ts4_if_call_seq_fn_882DDC70_882E0E28(o, 1);
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->b, 0x24810000);
    }
    ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(t->c, 0x24810000);
}
