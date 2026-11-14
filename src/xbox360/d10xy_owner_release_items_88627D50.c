/* Swing_DLL.xex 0x88627D50-0x88627DE8, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct obj;
struct ovt { void (*dtor)(struct obj *self, u32 flags); };
struct obj { struct ovt *vt; };
struct pvec { struct obj **first; struct obj **last; };
struct owner { u32 pad0[2]; unsigned char flag; char pad9[7]; char sub[12]; struct pvec items; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_88625798(struct obj *o);
extern void fn_881B9148(void *p);
INL struct obj **cpp(struct obj **first, struct obj **last, struct obj **dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (struct obj **)fn_88562DC0(dest, first, n);
        return (struct obj **)((char *)dest + n);
    }
}
void ts4_owner_release_items_88627D50(struct owner *self)
{
    struct obj **end = self->items.last;
    struct pvec *v = &self->items;
    struct obj **p = v->first;
    for (; p != end; p++) {
        fn_88625798(*p);
        if (*p != 0)
            (*p)->vt->dtor(*p, 1);
    }
    v->last = cpp(v->last, v->last, v->first);
    self->flag = 0;
    fn_881B9148(self->sub);
}
