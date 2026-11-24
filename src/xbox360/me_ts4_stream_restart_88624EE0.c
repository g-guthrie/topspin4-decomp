/* Swing_DLL.xex 0x88624EE0: Swing_DLL.xex 0x88624EE0: Restarts a text stream: finalizes it, clears the counter, reloads (8861BBA0), dispatches the queue, empties the text buffer; returns 1 if the counter is still zero.
 * /Oc only. The '+ 0' in the return is needed for the target's addi r11,r11,0 (cntlzw test). */
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
void fn_8827FAB0(TextBuf *b);
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
void fn_8861BBA0(Stream *s, void *arg);
void ts4_queue_dispatch_88624E20(Stream *s);
int fn_88624EE0(Stream *s, void *arg)
{
    ts4_object_finalize(s);
    s->a = 0;
    fn_8861BBA0(s, arg);
    ts4_queue_dispatch_88624E20(s);
    buf_reset(&s->buf);
    return 0 == (s->a + 0);   /* the "+ 0" reproduces the target's addi r11,r11,0 */
}
