/* 0x887858B0: release the registry buffer (+0x20C) of every 0x214-byte record in the second vector, then erase both record vectors */
/* Matched on /Oc (agAL). Plain route. Registry release inline with the registry as a parameter; end read into a local first and the loop test written end != e (cmplw end, e). */
typedef unsigned char u8;
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
typedef struct Rec214 { u8 text[0x20c]; void *buf; unsigned int w210; } Rec214;
typedef struct Vec214 { Rec214 *first; Rec214 *last; Rec214 *end; } Vec214;
extern Rec214 *ts4_vec214_erase_88214598(Vec214 *v, Rec214 *dst, Rec214 *first);
typedef struct Tsu { Vec214 a; Vec214 b; } Tsu;

static __inline void release(Ts4Registry *registry, void *key)
{
    void *entry;
    if (key == 0)
        return;
    entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0)
        ts4_node_visit_8860DBC8(entry, key);
    else
        ts4_node_visit_8860DBC8(registry->fallback, key);
}

static __inline void vclear(Vec214 *v)
{
    ts4_vec214_erase_88214598(v, v->first, v->last);
}

void ts4_tsu_cleanup_begin(Tsu *t)
{
    Rec214 *end = t->b.last;
    Rec214 *e;
    for (e = t->b.first; end != e; e++)
        release(lbl_88D45B38, e->buf);
    vclear(&t->b);
    vclear(&t->a);
}
