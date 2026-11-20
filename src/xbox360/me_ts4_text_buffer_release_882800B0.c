/* Swing_DLL.xex 0x882800B0: Releases a text buffer: empties its heap byte vector (+0x800), points +0x80C back at itself, clears the first text byte, then frees the heap block.
 * /Oc. The free test must read through the 'ByteVec *h' local (or an inline taking it); the direct field read is hoisted above the stores. */
typedef struct ByteVec { char *first; char *last; } ByteVec;
typedef struct Buffer {
    unsigned char text[0x800];   /* 0x000 */
    ByteVec heap;                /* 0x800 */
    unsigned char pad808[4];
    struct Buffer *self;         /* 0x80c */
} Buffer;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
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

void fn_882800B0(Buffer *b)
{
    ByteVec *h = &b->heap;
    vec_clear(h);
    b->self = b;
    b->text[0] = 0;
    if (h->first) ts4_destroy_owned_object(h->first);
}
