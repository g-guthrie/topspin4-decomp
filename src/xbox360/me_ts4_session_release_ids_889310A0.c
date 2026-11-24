/* Swing_DLL.xex 0x889310A0: Swing_DLL.xex 0x889310A0: Releases every id in the vector at +0x10 through the session context (vtable +0x70), then empties the vector.
 * /Oc. end read through the owner (o->ids.last), begin through the v local: fixes both the load order and the v/global register swap. */
typedef unsigned int u32;
typedef struct Session Session;
typedef struct SessionVtbl { void *slots[0x70 / 4]; void (*release_id)(Session *self, u32 id); /* 0x70 */ } SessionVtbl;
struct Session { const SessionVtbl *vt; };
typedef struct IdVec { u32 *first; u32 *last; u32 *end; } IdVec;
typedef struct Owner { char pad[0x10]; IdVec ids; } Owner;
extern Session *g_ts4_session_context;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __inline u32 *copy_ids(u32 *first, u32 *last, u32 *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (u32 *)fn_88562DC0(dest, first, n);
        return (u32 *)((char *)dest + n);
    }
}
void fn_889310A0(Owner *o)
{
    IdVec *v = &o->ids;
    u32 *it, *end = o->ids.last;
    for (it = v->first; it != end; it++)
        g_ts4_session_context->vt->release_id(g_ts4_session_context, *it);
    v->last = copy_ids(v->last, v->last, v->first);
}
