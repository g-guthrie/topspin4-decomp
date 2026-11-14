/* Loader_DLL.xex 0x83169B68-0x83169B94, executable version 0.0.0.3.
 * zlib 1.1.x inflate.c: inflateSyncPoint (first copy). */
typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct inflate_state {
    int mode;
    uInt marker;
    uInt pad[3];
    void *blocks;
};
typedef struct z_stream_s {
    Byte *next_in;
    uInt avail_in;
    uLong total_in;
    Byte *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    struct inflate_state *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    uLong adler;
    uLong reserved;
} z_stream;

extern int ts4_get_u32_off0_8316CC88(void *blocks);

int ts4l_zlib_inflateSyncPoint_83169B68(z_stream *z)
{
    if (z == 0 || z->state == 0 || z->state->blocks == 0)
        return -2;
    return ts4_get_u32_off0_8316CC88(z->state->blocks);
}
