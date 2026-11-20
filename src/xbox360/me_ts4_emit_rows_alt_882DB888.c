/* 0x882DB888: sibling of 0x882BFD50 with fn_882D22B0 as converter and fn_882DB430 as positioner: filters/converts the buffer, positions, copies rows*16 bytes to dst + (base-first)*16, sets +0xA0 */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
void *memcpy(void *d, const void *s, unsigned long n);
typedef struct T { char pad0[0x10]; int convert; char pad1[0x28]; int base; int x0; char pad2[0x8]; int y0; char pad3[0x4]; void *filter; char pad4[0x10]; unsigned int rows; char pad5[0x14]; char *dst; int first; char pad6[0x14]; unsigned int rows_done; int dirty; } T;
void *fn_882B4570(T *t, void *buf);
void *fn_882D22B0(T *t, void *buf);
int fn_882DB430(T *t, int x, int y, int partial);
void ts4_emit_rows_alt_882DB888(T *t, int x, int y, void *buf)
{
    if (t->filter)
        buf = fn_882B4570(t, buf);
    if (t->convert)
        buf = fn_882D22B0(t, buf);
    {
        int px = t->x0 + x;
        int py = t->y0 + y;
        if (fn_882DB430(t, px, py, t->rows - t->rows_done != 0) < 0)
            return;
    }
    memcpy(t->dst + (t->base - t->first) * 16, buf, t->rows * 16);
    t->dirty = 1;
}
