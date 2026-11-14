/* Loader_DLL.xex 0x83167C98-0x83167D30, executable version 0.0.0.3. */
/* zlib deflate.c read_buf. */
typedef unsigned int u32;
typedef unsigned char Byte;
struct DState { char pad[0x18]; int noheader; };
struct ZStream {
    Byte *next_in; u32 avail_in; u32 total_in;
    Byte *next_out; u32 avail_out; u32 total_out;
    char *msg; struct DState *state;
    void *zalloc; void *zfree; void *opaque;
    int data_type; u32 adler; u32 reserved;
};
extern u32 fn_83169DA8(u32 adler, const Byte *buf, u32 len);
extern void *fn_833E3AD0(void *d, const void *s, u32 n);

int ts4l_zlib_read_buf_83167C98(struct ZStream *strm, Byte *buf, u32 size)
{
    u32 len = strm->avail_in;
    if (len > size) len = size;
    if (len == 0) return 0;
    strm->avail_in -= len;
    if (!strm->state->noheader) {
        strm->adler = fn_83169DA8(strm->adler, strm->next_in, len);
    }
    fn_833E3AD0(buf, strm->next_in, len);
    strm->next_in += len;
    strm->total_in += len;
    return (int)len;
}
