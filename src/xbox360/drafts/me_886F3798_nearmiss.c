/* near miss 886F3798 (14 off as written; 11 off with `u32 ia = s->id_a;` read before the module local and `id == (*it)->id`). Also LTCG context for me_ts4_bind_attach_886FCB48. */
typedef unsigned int u32;
typedef struct Ts4BindItem { char pad[4]; u32 id; } Ts4BindItem;
typedef struct Ts4BindModule { char pad[0x64]; Ts4BindItem **first; Ts4BindItem **last; } Ts4BindModule;
extern Ts4BindModule *lbl_88D45A70;
typedef struct Ts4BindSrc { char pad[0x20]; u32 id_a; char pad2[4]; u32 id_b; } Ts4BindSrc;
typedef struct Ts4Bind { char pad[4]; Ts4BindItem *a; Ts4BindItem *b; Ts4BindSrc *src; } Ts4Bind;
static __forceinline Ts4BindItem *ts4_bind_find(Ts4BindModule *m, u32 id)
{
    Ts4BindItem **last = m->last, **it = m->first;
    for (; it != last; ++it) if (id == (*it)->id) return *it;
    return 0;
}
void fn_886F3798(Ts4Bind *o, Ts4BindSrc *s)
{
    Ts4BindModule *m;
    u32 id;
    o->src = s;
    if (!s) return;
    id = s->id_a;
    m = lbl_88D45A70;
    o->a = ts4_bind_find(m, id);
    o->b = ts4_bind_find(m, s->id_b);
}
