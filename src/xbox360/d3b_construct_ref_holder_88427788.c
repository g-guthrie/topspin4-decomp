/* Swing_DLL.xex 0x88427788-0x8842780C, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Node { void *vtbl; unsigned short size; unsigned short refs; struct Src *src; u32 aux; int one; } Node;
typedef struct Src { void *vtbl; u32 aux; } Src;
typedef struct Holder { void *vtbl; unsigned short pad; unsigned short refs; Node *node; unsigned char flag; } Holder;
extern u32 lbl_88CACF08;
extern char lbl_8803EADC[], lbl_8803DDEC[];
void *KeTlsGetValue(u32 index);
void *fn_8841A510(void *pool, int size, int tag);
void fn_8841D800(void *node);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
INL void *pool_alloc(int tag, int size) { void *p = KeTlsGetValue(lbl_88CACF08); return fn_8841A510(p, size, tag); }

Holder *ts4_construct_ref_holder_88427788(Holder *self, Src *src, unsigned char flag)
{
    Node *n;
    self->flag = flag;
    self->vtbl = lbl_8803EADC;
    self->refs = 1;
    n = (Node *)pool_alloc(0x1a, 0x14);
    n->vtbl = lbl_8803DDEC;
    n->refs = 1;
    n->src = src;
    n->size = 0x14;
    n->aux = src->aux;
    n->one = 1;
    fn_8841D800(n);
    self->node = n;
    return self;
}
