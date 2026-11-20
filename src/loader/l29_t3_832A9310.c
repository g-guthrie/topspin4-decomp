/* Loader_DLL.xex 0x832A9310-0x832A93AC, executable version 0.0.0.3. */
typedef struct L29C {
    char pad0[0x34]; unsigned short f34;
    char pad1[0x17c - 0x36]; int f17c; unsigned f180;
} L29C;
typedef struct L29S {
    char pad0[0x3e70]; L29C c;
} L29S;

extern void fn_832A8DE8(L29S *s, int v);
extern void fn_832A10F0(L29S *s);
extern void fn_832FCB08(L29S *s);
extern int fn_834ECE00(L29S *s, L29C *c, void *a, int row, unsigned start, unsigned end);
extern int fn_834D13F8(L29S *s, L29C *c, void *a, int row, unsigned start, unsigned end);

int ts4l_scan_rows_832A9310(L29S *s, void *a, int row)
{
    L29C *c = &s->c;
    unsigned start, end, half;
    if (c != 0) {
        if (row == 0) {
            fn_832A8DE8(s, 1);
            fn_832A10F0(s);
            fn_832FCB08(s);
        }
        end = (row + 1) * c->f180;
        half = c->f34 >> 1;
        start = c->f180 * row;
        if (end > half || row == c->f17c - 1) end = half;
        return fn_834D13F8(s, c, a, row, start, end);
    }
    return -9;
}

int ts4l_scan_rows_832A95B8(L29S *s, void *a, int row)
{
    L29C *c = &s->c;
    unsigned start, end, half;
    if (c != 0) {
        if (row == 0) {
            fn_832A8DE8(s, 1);
            fn_832A10F0(s);
            fn_832FCB08(s);
        }
        end = (row + 1) * c->f180;
        half = c->f34 >> 1;
        start = c->f180 * row;
        if (end > half || row == c->f17c - 1) end = half;
        return fn_834ECE00(s, c, a, row, start, end);
    }
    return -9;
}
