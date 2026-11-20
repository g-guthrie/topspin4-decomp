/* Loader_DLL.xex 0x832A1AA0-0x832A21D0, executable version 0.0.0.3. */
typedef struct L29C {
    char pad0[0x34]; unsigned short f34;
    char pad1[0x17c - 0x36]; int f17c; unsigned f180;
    char pad2[0x55c - 0x184]; int f55c;
} L29C;
typedef struct L29S {
    char pad0[0x120]; int f120;
    char pad1[0x3e70 - 0x124]; L29C c;
    char pad2[0x54c8 - 0x3e70 - sizeof(L29C)]; int f54c8;
    char pad3[0x5510 - 0x54cc]; int f5510;
    char pad4[0xb0ac - 0x5514]; int fb0ac;
    char pad5[0xb138 - 0xb0b0]; int fb138; int fb13c;
} L29S;

extern void fn_832FA6A0(L29S *s, L29C *c);
extern int ts4_tailcall_fn_834970A8_8349D160(L29S *s, L29C *c, void *a, int row, unsigned start, unsigned end);
extern int fn_834C3D38(L29S *s, L29C *c, void *a, int row, unsigned start, unsigned end);

#define L29_BODY(NAME, CALL) \
int NAME(L29S *s, void *a, int row) \
{ \
    L29C *c = &s->c; \
    int ret; \
    int saved, v; \
    unsigned start, end, half; \
    if (c != 0) { \
        v = s->f5510; \
        saved = s->f120; \
        s->f120 = v; \
        s->f54c8 = c->f55c; \
        if (s->fb0ac == 0 && s->fb13c == 0 && (s->fb138 == 0 || v != 4)) { \
            if (row == 0) fn_832FA6A0(s, c); \
            end = (row + 1) * c->f180; \
            half = c->f34 >> 1; \
            start = c->f180 * row; \
            if (end > half || row == c->f17c - 1) end = half; \
            ret = CALL(s, c, a, row, start, end); \
            s->f120 = saved; \
            return ret; \
        } \
        return 0; \
    } \
    return -9; \
}

L29_BODY(ts4l_scan_rows_chk_832A1AA0, ts4_tailcall_fn_834970A8_8349D160)
L29_BODY(ts4l_scan_rows_chk_832A20D8, fn_834C3D38)
