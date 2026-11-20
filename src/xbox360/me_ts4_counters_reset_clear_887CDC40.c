/* Swing_DLL.xex 0x887CDC40: Swing_DLL.xex 0x887CDC40: Zeroes the count and the five-word block at +0x4, then empties the byte vector at +0x18.
 * /Oc. The dead 'addi r11,r3,4' comes from the fully unrolled inline zero loop over &o->sub. */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Sub { int w[5]; } Sub;
typedef struct Owner { int count; Sub sub; ByteVec data; } Owner;
static __inline void sub_clear(Sub *s) { int i; for (i = 0; i < 5; i++) s->w[i] = 0; }
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __inline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
void fn_887CDC40(Owner *o)
{
    ByteVec *v = &o->data;
    o->count = 0;
    sub_clear(&o->sub);
    v->last = copy_bytes(v->last, v->last, v->first);
}
