/* Swing_DLL.xex 0x888FF550: Swing_DLL.xex 0x888FF550: Calls 888FD9C8 on every pointer in the vector at +0x2C, then empties the vector.
 * /Oc. end via o->things.last, begin via the v local. */
typedef struct Thing Thing;
typedef struct ThingVec { Thing **first; Thing **last; } ThingVec;
typedef struct Owner { unsigned char pad[0x2c]; ThingVec things; } Owner;
void fn_888FD9C8(Thing *t);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline Thing **copy_ptrs(Thing **first, Thing **last, Thing **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Thing **)fn_88562DC0(dest, first, n);
        return (Thing **)((char *)dest + n);
    }
}

void fn_888FF550(Owner *o)
{
    ThingVec *v = &o->things;
    Thing **it, **end = o->things.last;
    for (it = v->first; it != end; it++) fn_888FD9C8(*it);
    v->last = copy_ptrs(v->last, v->last, v->first);
}
