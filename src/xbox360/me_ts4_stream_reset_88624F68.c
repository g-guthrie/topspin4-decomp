/* Swing_DLL.xex 0x88624F68: Swing_DLL.xex 0x88624F68: Resets a text stream: finalizes it, empties the 0x800-byte text buffer and its vector, zeroes the counters, sets the flag, re-inits the buffer (882800B0), frees the owned object.
 * /Oc and /O1. Inline buf_reset over the cw4 copy_bytes clear. */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct TextBuf {
    char data[0x800];
    ByteVec vec;        /* 0x800 */
    char *cursor;       /* 0x80c */
} TextBuf;
typedef struct Stream {
    void *owned;        /* 0x00 */
    char pad4[0xc - 4];
    TextBuf buf;        /* 0x0c */
    int a;              /* 0x81c */
    int b;              /* 0x820 */
    unsigned char flag; /* 0x824 */
} Stream;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_object_finalize(Stream *s);
void fn_882800B0(TextBuf *b);
void ts4_destroy_owned_object(void *obj);
static __forceinline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
static __inline void vec_clear(ByteVec *v) { v->last = copy_bytes(v->last, v->last, v->first); }
static __inline void buf_reset(TextBuf *b) { vec_clear(&b->vec); b->cursor = b->data; b->data[0] = 0; }
void fn_88624F68(Stream *s)
{
    ts4_object_finalize(s);
    buf_reset(&s->buf);
    s->a = 0;
    s->b = 0;
    s->flag = 1;
    fn_882800B0(&s->buf);
    if (s->owned) ts4_destroy_owned_object(s->owned);
}
