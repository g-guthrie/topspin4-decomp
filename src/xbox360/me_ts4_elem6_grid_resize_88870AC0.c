/* Swing_DLL.xex 0x88870AC0: stores width*height at +0xC and resizes a vector of 6-byte elements to depth*width*height.
 * /Oc. resize inline owns an uninitialised default (_Insert_n fn_881A8148, memmove fn_88562DC0). */
typedef struct Elem6 { unsigned short c[3]; } Elem6;
typedef struct Desc { unsigned char p0[0x68]; unsigned int depth; unsigned char p1[4]; unsigned int width; unsigned int height; } Desc;
typedef struct Elem6Grid { Elem6 *first; Elem6 *last; Elem6 *end; unsigned int plane; } Elem6Grid;
void fn_881A8148(Elem6Grid *v, Elem6 *where, unsigned int count, const Elem6 *val);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline Elem6 *copy_elems(Elem6 *first, Elem6 *last, Elem6 *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Elem6 *)fn_88562DC0(dest, first, n);
        return (Elem6 *)((char *)dest + n);
    }
}

static __inline void resize(Elem6Grid *v, unsigned int n)
{
    Elem6 val;
    unsigned int size = v->last - v->first;
    if (n < size)
        v->last = copy_elems(v->last, v->last, v->first + n);
    else
        fn_881A8148(v, v->last, n - size, &val);
}

void fn_88870AC0(Elem6Grid *b, const Desc *d)
{
    b->plane = d->width * d->height;
    resize(b, d->depth * b->plane);
}
