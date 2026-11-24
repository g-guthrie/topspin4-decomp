/* Swing_DLL.xex 0x886A6E98: Swing_DLL.xex 0x886A6E98: Releases the entries at +0x88, then walks the host vector at +0x78 back to front: pushes each host's id and the host itself back onto the pool's two free stacks (around a host reset, 886A6B68); empties the vector and commits the pool (vtable +8).
 * /Oc. Reverse loop *(it - 1) then it--; inline stack_push; last via o, first via v. */
typedef struct PtrStack { void **base; char pad4[0x14 - 4]; void **top; } PtrStack;   /* 0x18, grows down */
typedef struct Pool { const struct PoolVtbl *vt; PtrStack ids; PtrStack hosts; } Pool;
typedef struct PoolVtbl { void *slots[2]; void (*commit)(Pool *self); /* 0x08 */ } PoolVtbl;
typedef struct Host { char pad[0x64]; void *id; } Host;
typedef struct HostVec { Host **first; Host **last; Host **end; } HostVec;
typedef struct Owner {
    char pad[0x74];
    Pool *pool;             /* 0x74 */
    HostVec hosts;          /* 0x78 */
    char pad84[0x88 - 0x84];
    void *entries;          /* 0x88 */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_release_all_entries_88662320(void *entries);
void ts4_host_reset_886A6B68(Host *h);
static __forceinline Host **copy_hosts(Host **first, Host **last, Host **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Host **)fn_88562DC0(dest, first, n);
        return (Host **)((char *)dest + n);
    }
}
static __inline void stack_push(PtrStack *s, void *p)
{
    if (s->top != s->base) {
        s->top--;
        *s->top = p;
    }
}
void fn_886A6E98(Owner *o)
{
    HostVec *v;
    Host **it, **first;
    ts4_release_all_entries_88662320(o->entries);
    v = &o->hosts;
    it = o->hosts.last;
    first = v->first;
    while (it != first) {
        Host *h = *(it - 1);
        if (h) {
            stack_push(&o->pool->ids, h->id);
            ts4_host_reset_886A6B68(h);
            stack_push(&o->pool->hosts, h);
        }
        it--;
    }
    v->last = copy_hosts(v->last, v->last, v->first);
    o->pool->vt->commit(o->pool);
}
