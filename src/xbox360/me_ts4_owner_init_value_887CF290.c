/* Swing_DLL.xex 0x887CF290: Swing_DLL.xex 0x887CF290: Zeroes the four-word block at +0x8, empties the byte vector at +0x18, stores the value at +0x4 and clears the three flag bytes.
 * /Oc and /O1. Dead 'addi r11,r3,8' = unrolled inline zero loop over &o->sub. */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Sub { int w[4]; } Sub;
typedef struct Owner {
    unsigned char f0, f1, f2;  /* 0x00 */
    int value;                 /* 0x04 */
    Sub sub;                   /* 0x08 */
    ByteVec data;              /* 0x18 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
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
static __inline void sub_clear(Sub *s) { int i; for (i = 0; i < 4; i++) s->w[i] = 0; }
void fn_887CF290(Owner *o, int value)
{
    ByteVec *v;
    sub_clear(&o->sub);
    v = &o->data;
    v->last = copy_bytes(v->last, v->last, v->first);
    o->value = value;
    o->f0 = 0;
    o->f1 = 0;
    o->f2 = 0;
}
