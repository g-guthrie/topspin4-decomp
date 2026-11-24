/* Swing_DLL.xex 0x88702BF0 (/Oc): Ts4ObjOwner::Reset. Detaches and destroys (virtual slots 2 and 0, flags 1) the
 * front object until the owned pointer vector is empty (each destroy removes the object from the vector), then
 * clears the vector (erase(begin, end): copy the empty tail down), drops the active flag and trims the 0x10 vector.
 * Matched as a C++ member with an STL-style vector: `begin() != end()` gives the signed cmpw with the end loaded
 * first, and clear() as an erase member puts the vector base in its own register. */
extern "C" void *fn_88562DC0(void *dst, const void *src, unsigned int n); /* memmove */

struct Ts4OwnedObj;
struct Ts4OwnedObjVtbl {
    void (*destroy)(Ts4OwnedObj *self, int flags); /* 0x00 */
    void *slot4;
    void (*detach)(Ts4OwnedObj *self);             /* 0x08 */
};
struct Ts4OwnedObj { const Ts4OwnedObjVtbl *vt; };

struct Ts4Vec204 { void *first; void *last; void *end; };
extern "C" void ts4_vec204_move_tail_881B9148(Ts4Vec204 *v);

static inline Ts4OwnedObj **ts4_copy_ptrs(Ts4OwnedObj **first, Ts4OwnedObj **last, Ts4OwnedObj **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Ts4OwnedObj **)fn_88562DC0(dest, first, n);
        return (Ts4OwnedObj **)((char *)dest + n);
    }
}

struct Ts4OwnedObjVec {
    Ts4OwnedObj **first;
    Ts4OwnedObj **last;
    Ts4OwnedObj **cap;
    Ts4OwnedObj **begin() { return first; }
    Ts4OwnedObj **end() { return last; }
    Ts4OwnedObj **erase(Ts4OwnedObj **f, Ts4OwnedObj **l) { last = ts4_copy_ptrs(l, last, f); return f; }
    void clear() { erase(begin(), end()); }
};

struct Ts4ObjOwner {
    char pad0[8];
    unsigned char active;  /* 0x08 */
    char pad9[7];
    Ts4Vec204 v10;         /* 0x10 */
    Ts4OwnedObjVec objs;   /* 0x1c */
    void Reset();
};

void Ts4ObjOwner::Reset()
{
    while (objs.begin() != objs.end()) {
        Ts4OwnedObj *p = *objs.begin();
        p->vt->detach(p);
        p->vt->destroy(p, 1);
    }
    objs.clear();
    active = 0;
    ts4_vec204_move_tail_881B9148(&v10);
}
