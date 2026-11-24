/* Swing_DLL.xex 0x88737A60: starts each pending id (fn_88737420) that is non-negative and not already active; on the first that is not, empties the pending vector.
 * /Oc. Pending slot read through the owner (m->pending.first[i]), active end read before begin, compared as end != it. */
typedef struct IdVec { unsigned int *first; unsigned int *last; unsigned int *end; } IdVec;
typedef struct Mgr {
    unsigned char p0[0x14];
    IdVec active;
    unsigned char p1[0x3c - 0x20];
    IdVec pending;
} Mgr;
void fn_88737420(Mgr *m, int id);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline unsigned int *copy_ids(unsigned int *first, unsigned int *last, unsigned int *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (unsigned int *)fn_88562DC0(dest, first, n);
        return (unsigned int *)((char *)dest + n);
    }
}

static __inline unsigned int ids_size(IdVec *v) { return v->last - v->first; }

static __inline unsigned char can_start(Mgr *m, int id)
{
    IdVec *a = &m->active;
    unsigned int *it, *end;
    if (id < 0) return 0;
    end = m->active.last;
    for (it = a->first; end != it; it++)
        if (id == *it) return 0;
    return 1;
}

void fn_88737A60(Mgr *m)
{
    IdVec *v = &m->pending;
    unsigned int i;
    for (i = 0; i < ids_size(v); i++) {
        int id = m->pending.first[i];
        if (can_start(m, id) != 1) {
            v->last = copy_ids(v->last, v->last, v->first);
            break;
        }
        fn_88737420(m, id);
    }
}
