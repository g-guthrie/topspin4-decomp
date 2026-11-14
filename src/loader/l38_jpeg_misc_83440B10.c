/* Loader_DLL.xex 0x83440B10-0x83440C38, 0x83443428-0x83443480, 0x83461208-0x8346124C (libjpeg read_raw_data, marker limits, edge expand), executable version 0.0.0.3. */
typedef unsigned long u32;
typedef struct Ts4lCinfo Ts4lCinfo;
typedef struct { void (*error_exit)(Ts4lCinfo *c); void (*emit)(Ts4lCinfo *c, int lvl); u32 pad[3]; int msg_code; int parm0; } Ts4lErr;
typedef struct { void (*monitor)(Ts4lCinfo *c); u32 pass_counter; u32 pass_limit; } Ts4lProg;
typedef struct { u32 pad[3]; int (*decompress)(Ts4lCinfo *c, void *d); } Ts4lCoef;
struct Ts4lCinfo {
    Ts4lErr *err; u32 pad0; Ts4lProg *progress; u32 pad1[2]; int state;
    char pad2[0x74 - 0x18]; u32 out_h; char pad3[0x8c - 0x78]; u32 out_scan;
    char pad4[0x13c - 0x90]; u32 min_dct; u32 max_v; char pad5[0x1b0 - 0x144]; Ts4lCoef *coef;
};
u32 ts4l_read_raw_data_83440B10(Ts4lCinfo *c, void *data, u32 max_lines)
{
    u32 n;
    if (c->state != 0xce) { c->err->msg_code = 20; c->err->parm0 = c->state; c->err->error_exit(c); }
    if (c->out_scan >= c->out_h) { c->err->msg_code = 123; c->err->emit(c, -1); return 0; }
    if (c->progress != 0) { c->progress->pass_counter = c->out_scan; c->progress->pass_limit = c->out_h; c->progress->monitor(c); }
    n = c->max_v * c->min_dct;
    if (max_lines < n) { c->err->msg_code = 23; c->err->error_exit(c); }
    if (!c->coef->decompress(c, data)) return 0;
    c->out_scan += n;
    return n;
}
void ts4l_save_markers_83443428(Ts4lCinfo *c, int marker, u32 limit)
{
    u32 *p = *(u32 **)((char *)c + 0x1bc);
    if (marker == 0xfe) { p[7] = limit; return; }
    if (marker >= 0xe0 && marker <= 0xef) { p[8 + marker - 0xe0] = limit; return; }
    c->err->msg_code = 68; c->err->parm0 = marker; c->err->error_exit(c);
}
void ts4l_expand_edge_83461208(unsigned char **rows, int nrows, int start, int end)
{
    int n = end - start;
    unsigned char **rp;
    int k;
    if (n <= 0) return;
    if (nrows <= 0) return;
    rp = rows - 1;
    do {
        unsigned char *p = *++rp + start;
        unsigned char v = p[-1];
        for (k = n; k != 0; k--) *p++ = v;
    } while (--nrows != 0);
}
