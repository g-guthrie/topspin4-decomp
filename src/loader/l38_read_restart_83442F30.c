/* Loader_DLL.xex 0x83442F30-0x83443014 (libjpeg read_restart_marker), executable version 0.0.0.3. */
typedef unsigned long u32;
typedef struct Ts4lCinfo Ts4lCinfo;
typedef struct { void (*error_exit)(Ts4lCinfo *c); void (*emit)(Ts4lCinfo *c, int lvl); u32 pad[3]; int msg_code; int parm0; } Ts4lErr;
typedef struct { char p0[0x14]; int (*resync)(Ts4lCinfo *c, int desired); } Ts4lSrc;
typedef struct { char p0[0x14]; int next_restart_num; } Ts4lMarker;
struct Ts4lCinfo {
    Ts4lErr *err; u32 pad0; char pad1[0x18 - 8]; Ts4lSrc *src;
    char pad2[0x1a4 - 0x1c]; int unread_marker; char pad3[0x1bc - 0x1a8]; Ts4lMarker *marker;
};
extern int fn_834429C0(Ts4lCinfo *c);
int ts4l_read_restart_marker_83442F30(Ts4lCinfo *c)
{
    if (c->unread_marker == 0) {
        if (!fn_834429C0(c)) return 0;
    }
    if (c->unread_marker == 0xd0 + c->marker->next_restart_num) {
        c->err->msg_code = 98;
        c->err->parm0 = c->marker->next_restart_num;
        c->err->emit(c, 3);
        c->unread_marker = 0;
    } else {
        if (!c->src->resync(c, c->marker->next_restart_num)) return 0;
    }
    c->marker->next_restart_num = (c->marker->next_restart_num + 1) & 7;
    return 1;
}
