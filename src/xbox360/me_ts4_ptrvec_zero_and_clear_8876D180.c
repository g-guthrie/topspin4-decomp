/* Swing_DLL.xex 0x8876D180: Swing_DLL.xex 0x8876D180: Zeroes every slot of the pointer vector at +0x8, then empties it.
 * /Oc. Hoisted unsigned count with 'i != n'; index through o->items.first (not the v local) for the stwx operand order. */
typedef struct PtrVec { void **first; void **last; void **end; } PtrVec;
typedef struct Owner { char pad[8]; PtrVec items; } Owner;
static __inline unsigned vec_size(const PtrVec *v) { return v->last - v->first; }
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __inline void **copy_ptrs(void **first, void **last, void **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (void **)fn_88562DC0(dest, first, n);
        return (void **)((char *)dest + n);
    }
}
void fn_8876D180(Owner *o)
{
    PtrVec *v = &o->items;
    unsigned i, n = vec_size(v);
    for (i = 0; i != n; i++) o->items.first[i] = 0;
    v->last = copy_ptrs(v->last, v->last, v->first);
}
