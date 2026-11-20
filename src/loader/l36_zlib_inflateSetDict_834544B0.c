/* Loader_DLL.xex 0x834544B0-0x83454560, executable version 0.0.0.3.
 * zlib 1.1.x inflate.c: inflateSetDictionary (second zlib copy). */
typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct inflate_state { int mode; uInt pad4; uInt pad8; uInt padc; uInt wbits; void *blocks; };
typedef struct z_stream_s {
    Byte *next_in; uInt avail_in; uLong total_in;
    Byte *next_out; uInt avail_out; uLong total_out;
    char *msg; void *state;
    void *zalloc; void *zfree; void *opaque;
    int data_type; uLong adler; uLong reserved;
} z_stream;

extern uLong fn_834637F0(uLong adler, const Byte *buf, uInt len);
extern void ts4l_advance_834665A0(void *blocks, const Byte *d, uInt n);

int ts4l_zlib_inflateSetDictionary_834544B0(z_stream *z, const Byte *dictionary, uInt dictLength)
{
    uInt length = dictLength;

    if (z == 0 || z->state == 0 || ((struct inflate_state *)z->state)->mode != 6) return -2;
    if (fn_834637F0(1L, dictionary, dictLength) != z->adler) return -3;
    z->adler = 1L;
    if (length >= ((uInt)1 << ((struct inflate_state *)z->state)->wbits)) {
        length = (1 << ((struct inflate_state *)z->state)->wbits) - 1;
        dictionary += dictLength - length;
    }
    ts4l_advance_834665A0(((struct inflate_state *)z->state)->blocks, dictionary, length);
    ((struct inflate_state *)z->state)->mode = 7;
    return 0;
}
