/* Loader_DLL.xex 0x83443D80-0x83443EAC (libjpeg jpeg_read_scanlines), executable version 0.0.0.3. */
typedef unsigned long u32;
typedef struct Ts4lCinfo Ts4lCinfo;
typedef struct { void (*error_exit)(Ts4lCinfo *c); void (*emit)(Ts4lCinfo *c, int lvl); u32 pad[3]; int msg_code; int parm0; } Ts4lErr;
typedef struct { void (*monitor)(Ts4lCinfo *c); u32 pass_counter; u32 pass_limit; } Ts4lProg;
typedef struct { void *p0; void (*start)(Ts4lCinfo *c); u32 p8; int active; } Ts4lHook;
typedef struct { void *p0; void (*process)(Ts4lCinfo *c, void *lines, u32 *row_ctr, u32 max); } Ts4lMain;
struct Ts4lCinfo {
    Ts4lErr *err; u32 pad0; Ts4lProg *progress; u32 pad1[2]; int state;
    char pad2[0x20 - 0x18]; u32 out_h; char pad3[0xe8 - 0x24]; u32 out_scan;
    char pad4[0x154 - 0xec]; Ts4lHook *hook; Ts4lMain *main;
};
u32 ts4l_read_scanlines_83443D80(Ts4lCinfo *c, void *lines, u32 max_lines)
{
    u32 row_ctr;
    u32 rem;
    if (c->state != 0x65) { c->err->msg_code = 20; c->err->parm0 = c->state; c->err->error_exit(c); }
    if (c->out_scan >= c->out_h) { c->err->msg_code = 123; c->err->emit(c, -1); }
    if (c->progress != 0) { c->progress->pass_counter = c->out_scan; c->progress->pass_limit = c->out_h; c->progress->monitor(c); }
    if (c->hook->active != 0) c->hook->start(c);
    rem = c->out_h - c->out_scan;
    if (max_lines > rem) max_lines = rem;
    row_ctr = 0;
    c->main->process(c, lines, &row_ctr, max_lines);
    c->out_scan += row_ctr;
    return row_ctr;
}
