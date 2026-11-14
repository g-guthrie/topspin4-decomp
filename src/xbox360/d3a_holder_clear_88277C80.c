/* Swing_DLL.xex 0x88277C80-0x88277D18, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct vt;
struct obj { struct vt *vt; };
struct vt { void *s[5]; void (*f14)(struct obj *self); };
struct ovt { void (*dtor)(struct obj *self, u32 flags); };
struct pvec { struct obj **first; struct obj **last; };
struct holder { u32 pad[14]; struct pvec items; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
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
void ts4_holder_clear_88277C80(struct holder *self)
{
    struct obj **end = self->items.last;
    struct pvec *v = &self->items;
    struct obj **p = v->first;
    for (; p != end; p++) {
        ((struct vt *)(*p)->vt)->f14(*p);
        if (*p != 0) {
            ((struct ovt *)(*p)->vt)->dtor(*p, 1);
        }
    }
    v->last = cpp(v->last, v->last, v->first);
}
