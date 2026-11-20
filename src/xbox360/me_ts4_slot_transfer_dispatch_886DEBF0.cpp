/* 0x886DEBF0: picks the slot-transfer handler. The first slot of a multi-slot owner
   (with a valid descriptor id) goes to fn_886DDED8; otherwise both slots valid ->
   fn_886DD7C8, else fn_886DE2A0. */
typedef struct Desc { char pad[0xc]; unsigned short id; } Desc;
typedef struct Inner { char pad[8]; Desc *desc; } Inner;
typedef struct Src { char pad[4]; Inner *inner; } Src;
typedef struct Owner { char pad[0x70]; int first_rel; /* self-relative offset to the first slot */ unsigned int count; } Owner;
typedef struct Slot { char pad[4]; int index; } Slot;
extern "C" {
int fn_886DD7C8(void *a, Owner *o, Src *s, Slot *d, Slot *e, void *f, void *g);
int fn_886DDED8(void *a, Owner *o, Src *s, Slot *d, Slot *e, void *f, void *g);
int fn_886DE2A0(void *a, Owner *o, Src *s, Slot *d, Slot *e, void *f, void *g);
int fn_886DEBF0(void *a, Owner *o, Src *s, Slot *d, Slot *e, void *f, void *g, bool flag);
}
static __inline Slot *rel_ptr(int *p) { return (Slot *)((char *)p + *p); }
static __inline bool is_first_of_many(Src *s, Owner *o, Slot *e) { return s->inner->desc->id != 0xffff && o->count > 1 && e == rel_ptr(&o->first_rel); }
int fn_886DEBF0(void *a, Owner *o, Src *s, Slot *d, Slot *e, void *f, void *g, bool flag)
{
    bool hit = false;
    if (flag)
        hit = is_first_of_many(s, o, e);
    if (hit)
        return fn_886DDED8(a, o, s, d, e, f, g);
    if (d->index != -1) {
        if (e->index != -1)
            return fn_886DD7C8(a, o, s, d, e, f, g);
        return fn_886DE2A0(a, o, s, d, e, f, g);
    }
    return fn_886DE2A0(a, o, s, d, e, f, g);
}
