/* CX33: remove-by-key from the vector at +0x14 (Swing_DLL.xex 0x889122D8). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct I6In { u32 w0; u32 w4; } I6In;
typedef struct I6Ref { I6In *inner; } I6Ref;
typedef struct I6El { void **vt; I6Ref *w4; } I6El;
typedef struct I6Vec { I6El **first; I6El **last; } I6Vec;
typedef struct I6Hub { u8 pad[0x14]; I6Vec v; } I6Hub;
typedef struct I6Key { u32 w0; u32 w4; } I6Key;
typedef void (*I6Del)(I6El *e, int flags);
extern void *fn_88562DC0(void *dst, void *src, u32 n);

static __inline u8 matches(I6El *e, I6Key **kp)
{
    I6In *in = e->w4->inner;
    int c;
    if (in != 0)
        c = in->w4 == (*kp)->w4;
    else
        c = 0;
    return (u8)c;
}

void ts4_hub_remove_by_key_889122D8(I6Hub *h, I6Key **kp)
{
    I6Vec *v = &h->v;
    I6El **p = v->first;
    I6El **q;
    if (p == h->v.last)
        return;
    q = p + 1;
    do {
        I6El *e = *p;
        if (matches(e, kp)) {
            ((I6Del)e->vt[0])(e, 1);
            if (q != v->last)
                fn_88562DC0(p, q, (u32)((char *)v->last - (char *)q));
            v->last--;
        } else {
            q++;
            p++;
        }
    } while (p != h->v.last);
}
