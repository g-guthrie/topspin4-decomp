/* Swing_DLL.xex 0x882DDA00: if the stream has data, calls its copy callback for element (first+index) at
 * base + data + index*stride*4 (stride 4 when wide); E_FAIL when no callback. agAE: /O1. */
typedef long HRESULT;
typedef struct Hdr { char pad[8]; char *base; } Hdr;
typedef HRESULT (*CopyFn)(void *ctx, unsigned int index, void *data, void *user, unsigned int count);
typedef struct Stream {
    Hdr *hdr; char pad4[4]; unsigned short wide; unsigned short first; unsigned short count; char padE[6];
    char *data; char pad18[4]; CopyFn copy; void *user;
} Stream;
HRESULT fn_882DDA00(Stream *s, void *ctx, unsigned int index)
{
    if (s->data) {
        unsigned int stride = 1;
        HRESULT hr;
        if (s->wide) stride = 4;
        if (!s->copy) return 0x80004005;
        hr = s->copy(ctx, s->first + index, s->data + (stride * index * 4 + (unsigned)s->hdr->base), s->user, s->count);
        if (hr < 0) return hr;
    }
    return 0;
}
