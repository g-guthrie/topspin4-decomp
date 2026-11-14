/* Loader_DLL.xex 0x83454560-0x834546A4, executable version 0.0.0.3.
 * zlib 1.1.x inflate.c: inflateSync, inflateSyncPoint (second copy). */
typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct inflate_state { int mode; uInt marker; uInt pad[3]; void *blocks; };
typedef struct z_stream_s {
    Byte *next_in; uInt avail_in; uLong total_in;
    Byte *next_out; uInt avail_out; uLong total_out;
    char *msg; struct inflate_state *state;
    void *zalloc; void *zfree; void *opaque;
    int data_type; uLong adler; uLong reserved;
} z_stream;

extern const Byte lbl_8307AC44[4];
extern int ts4l_zlib_inflateReset_83453CF8(z_stream *z);
extern int ts4_get_u32_off0_834665F0(void *blocks);

int ts4l_zlib_inflateSync_83454560(z_stream *z)
{
    uInt n;
    Byte *p;
    uInt m;
    uLong r, w;

    if (z == 0 || z->state == 0) return -2;
    if (z->state->mode != 13) {
        z->state->mode = 13;
        z->state->marker = 0;
    }
    if ((n = z->avail_in) == 0) return -5;
    p = z->next_in;
    m = z->state->marker;
    while (n && m < 4) {
        if (*p == lbl_8307AC44[m]) m++;
        else if (*p) m = 0;
        else m = 4 - m;
        p++, n--;
    }
    z->total_in += p - z->next_in;
    z->next_in = p;
    z->avail_in = n;
    z->state->marker = m;
    if (m != 4) return -3;
    r = z->total_in;
    w = z->total_out;
    ts4l_zlib_inflateReset_83453CF8(z);
    z->total_in = r;
    z->total_out = w;
    z->state->mode = 7;
    return 0;
}

int ts4l_zlib_inflateSyncPoint_83454678(z_stream *z)
{
    if (z == 0 || z->state == 0 || z->state->blocks == 0)
        return -2;
    return ts4_get_u32_off0_834665F0(z->state->blocks);
}
