/* Swing_DLL.xex 0x8827E170-0x8827E218, executable version 0.0.0.3. */
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
struct holder2 { u32 pad[9]; unsigned char active; unsigned char pad2[3]; struct pvec items; };
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
void ts4_holder2_clear_8827E170(struct holder2 *self)
{
    struct pvec *v;
    if (self->active != 0) {
        struct obj **p;
        struct obj **end;
        v = &self->items;
        end = v->last; p = v->first;
        if (end != p) {
            do {
                ((struct vt *)(*p)->vt)->f14(*p);
                if (*p != 0) {
                    ((struct ovt *)(*p)->vt)->dtor(*p, 1);
                }
                p++;
            } while (p != end);
        }
    }
    v = &self->items;
    v->last = cpp(v->last, v->last, v->first);
}
