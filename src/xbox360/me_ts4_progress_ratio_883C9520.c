/* 0x883C9520: position (+0xAC->+0x1C, clamped at 0) over the length at +0xA6 when flag 0x100000 is set */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); or 1 - pos/len(+0xA4) when flag 0x200000 is set, else lbl_88001A68. */
extern const float lbl_88001A20;
extern const float lbl_88001A68;
typedef struct S { char pad[0x1c]; short pos; } S;
typedef struct T { char pad[0x60]; unsigned flags; char pad2[0xa4 - 0x64]; short len_b; short len_a; char pad3[0xac - 0xa8]; S *s; } T;
float ts4_progress_ratio_883C9520(T *t)
{
    float v;
    short p = t->s->pos;
    if (p < 0)
        v = lbl_88001A20;
    else
        v = (float)p;
    if (t->flags & 0x100000)
        return v / (float)t->len_a;
    if (t->flags & 0x200000)
        return lbl_88001A68 - v / (float)t->len_b;
    return lbl_88001A68;
}
