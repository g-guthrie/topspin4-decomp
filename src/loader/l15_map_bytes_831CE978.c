/* Loader_DLL.xex 0x831CE978-0x831CEA10, executable version 0.0.0.3. */
/* Byte-wise table translation through a callback; the second variant keeps the
 * callback pointer XOR-encoded in its context block. */
typedef unsigned char (*Ts4lByteFn)(unsigned char);
typedef struct { char pad[0xc8]; unsigned enc; } Ts4lByteCtx;

void ts4l_map_bytes_831CE978(unsigned char *dst, unsigned char *src, unsigned n, Ts4lByteFn fn)
{
    unsigned i;

    for (i = 0; i < n; i++)
        dst[i] = fn(src[i]);
}

void ts4l_map_bytes_encoded_831CE9C0(unsigned char *dst, unsigned char *src, unsigned n, Ts4lByteCtx *ctx)
{
    unsigned i;
    Ts4lByteFn fn = (Ts4lByteFn)(unsigned long)(ctx->enc ^ 0xab7638deu);

    for (i = 0; i < n; i++)
        dst[i] = fn(src[i]);
}
