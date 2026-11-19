/* Swing_DLL.xex 0x88334700: reserves memory with fn_8832EDB0 for the pair array (count * 8) and, for each pair with a buffer,
 * width * rows * 4 bytes (rows = 6 in mode 7). Sibling of 88334648. agAE: /Oc. */
typedef struct Budget Budget;
typedef struct Pair { unsigned int key; void *buf; } Pair;
typedef struct Owner { char pad[0x130]; int count; char pad134[0x4ac - 0x134]; int width; int rows; char pad4b4[0x5630 - 0x4b4]; int mode; } Owner;
typedef struct Table { char pad[8]; Pair *pairs; Owner *owner; } Table;
int fn_8832EDB0(Budget *b, int kind, int align, unsigned int size);
int fn_88334700(Table *t, Budget *b)
{
    int i, rows;
    if (t->pairs) {
        fn_8832EDB0(b, 0, 0x20, t->owner->count * 8);
        rows = t->owner->rows;
        if (t->owner->mode == 7) rows = 6;
        for (i = 0; i < t->owner->count; i++)
            if (t->pairs[i].buf) fn_8832EDB0(b, 0, 0x20, t->owner->width * rows * 4);
    }
    return 0;
}
