/* Loader_DLL.xex 0x83453F60-0x834544B0, executable version 0.0.0.3. */
/* Library routine: zlib 1.1.x inflate (inflate.c). */

typedef unsigned char ts4l_u8;
typedef unsigned int ts4l_u32;

typedef struct ts4l_istate ts4l_istate;

typedef struct ts4l_izstream {
    ts4l_u8 *next_in;
    ts4l_u32 avail_in;
    ts4l_u32 total_in;
    ts4l_u8 *next_out;
    ts4l_u32 avail_out;
    ts4l_u32 total_out;
    char *msg;
    ts4l_istate *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    ts4l_u32 adler;
    ts4l_u32 reserved;
} ts4l_izstream;

struct ts4l_istate {
    int mode;
    union {
        ts4l_u32 method;
        struct {
            ts4l_u32 was;
            ts4l_u32 need;
        } check;
        ts4l_u32 marker;
    } sub;
    int nowrap;
    ts4l_u32 wbits;
    void *blocks;
};

extern char lbl_8300600C[];
extern char lbl_83006028[];
extern char lbl_8300603C[];
extern char lbl_83006054[];
extern char lbl_83005FFC[];

extern int fn_83465CD0(void *blocks, ts4l_izstream *z, int r);
extern void fn_83465B20(void *blocks, ts4l_izstream *z, ts4l_u32 *c);

#define TS4L_NEEDBYTE                                                                          \
    {                                                                                          \
        if (z->avail_in == 0)                                                                  \
            return r;                                                                          \
        r = f;                                                                                 \
    }
#define TS4L_NEXTBYTE (z->avail_in--, z->total_in++, *z->next_in++)

int ts4l_zlib_inflate_83453F60(ts4l_izstream *z, int f)
{
    int r;
    ts4l_u32 b;

    if (z == 0 || z->state == 0 || z->next_in == 0)
        return -2;
    f = f == 4 ? -5 : 0;
    r = -5;
    while (1)
        switch (z->state->mode) {
        case 0:
            TS4L_NEEDBYTE
            if (((z->state->sub.method = TS4L_NEXTBYTE) & 0xf) != 8) {
                z->state->mode = 13;
                z->msg = lbl_8300600C;
                z->state->sub.marker = 5;
                break;
            }
            if ((z->state->sub.method >> 4) + 8 > z->state->wbits) {
                z->state->mode = 13;
                z->msg = lbl_83006028;
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = 1;
        case 1:
            TS4L_NEEDBYTE
            b = TS4L_NEXTBYTE;
            if (((z->state->sub.method << 8) + b) % 31) {
                z->state->mode = 13;
                z->msg = lbl_8300603C;
                z->state->sub.marker = 5;
                break;
            }
            if (!(b & 0x20)) {
                z->state->mode = 7;
                break;
            }
            z->state->mode = 2;
        case 2:
            TS4L_NEEDBYTE
            z->state->sub.check.need = (ts4l_u32)TS4L_NEXTBYTE << 24;
            z->state->mode = 3;
        case 3:
            TS4L_NEEDBYTE
            z->state->sub.check.need += (ts4l_u32)TS4L_NEXTBYTE << 16;
            z->state->mode = 4;
        case 4:
            TS4L_NEEDBYTE
            z->state->sub.check.need += (ts4l_u32)TS4L_NEXTBYTE << 8;
            z->state->mode = 5;
        case 5:
            TS4L_NEEDBYTE
            z->state->sub.check.need += (ts4l_u32)TS4L_NEXTBYTE;
            z->adler = z->state->sub.check.need;
            z->state->mode = 6;
            return 2;
        case 6:
            z->state->mode = 13;
            z->msg = lbl_83005FFC;
            z->state->sub.marker = 0;
            return -2;
        case 7:
            r = fn_83465CD0(z->state->blocks, z, r);
            if (r == -3) {
                z->state->mode = 13;
                z->state->sub.marker = 0;
                break;
            }
            if (r == 0)
                r = f;
            if (r != 1)
                return r;
            r = f;
            fn_83465B20(z->state->blocks, z, &z->state->sub.check.was);
            if (z->state->nowrap) {
                z->state->mode = 12;
                break;
            }
            z->state->mode = 8;
        case 8:
            TS4L_NEEDBYTE
            z->state->sub.check.need = (ts4l_u32)TS4L_NEXTBYTE << 24;
            z->state->mode = 9;
        case 9:
            TS4L_NEEDBYTE
            z->state->sub.check.need += (ts4l_u32)TS4L_NEXTBYTE << 16;
            z->state->mode = 10;
        case 10:
            TS4L_NEEDBYTE
            z->state->sub.check.need += (ts4l_u32)TS4L_NEXTBYTE << 8;
            z->state->mode = 11;
        case 11:
            TS4L_NEEDBYTE
            z->state->sub.check.need += (ts4l_u32)TS4L_NEXTBYTE;
            if (z->state->sub.check.was != z->state->sub.check.need) {
                z->state->mode = 13;
                z->msg = lbl_83006054;
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = 12;
        case 12:
            return 1;
        case 13:
            return -3;
        default:
            return -2;
        }
}
