/* Loader_DLL.xex 0x83359498-0x833594F4, 0x83488C48-0x83488CBC, executable version 0.0.0.3. */
/* An 8x8 block narrowing copy (16-bit samples to bytes) and a take-once buffered record read. */
typedef unsigned char ts4l_u8;
typedef unsigned short ts4l_u16;


/* Copy an 8x8 block of 16-bit samples (row pitch 20 samples) to bytes with the given destination stride. */
void ts4l_block8_narrow_83359498(ts4l_u8 *dst, ts4l_u16 *src, int stride)
{
    int i;
    for (i = 0; i < 8; i++) {
        dst[0] = (ts4l_u8)src[0];
        dst[1] = (ts4l_u8)src[1];
        dst[2] = (ts4l_u8)src[2];
        dst[3] = (ts4l_u8)src[3];
        dst[4] = (ts4l_u8)src[4];
        dst[5] = (ts4l_u8)src[5];
        dst[6] = (ts4l_u8)src[6];
        dst[7] = (ts4l_u8)src[7];
        src += 20;
        dst += stride;
    }
}

typedef struct { char d[332]; } Ts4lBlob332;
typedef struct { char pad[24]; ts4l_u8 flag; char pad2[3]; Ts4lBlob332 data; ts4l_u8 have; } Ts4lPending;

/* Hand out the pending 332-byte record once and clear the pending flags. */
int ts4l_take_pending_83488C48(Ts4lPending *s, Ts4lBlob332 *out)
{
    if (s->have == 0 || out == 0) return 0;
    *out = s->data;
    s->have = 0;
    s->flag = 0;
    return 1;
}
