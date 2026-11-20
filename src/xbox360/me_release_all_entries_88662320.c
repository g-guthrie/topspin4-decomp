/* 0x88662320 (hand match): release every 0x14-byte entry of the owner's vector, erase the
 * whole range, then reset the two counters that follow it. */
typedef struct Entry { char p[0x14]; } Entry;
typedef struct Vec { Entry *first; Entry *last; } Vec;
typedef struct Owner { char p[8]; Vec v; int pad10; int count; int total; } Owner;
void ts4_if_get_u32_offc_8865AAC0(Entry *e);
Entry *fn_8826B898(Vec *v, Entry *first, Entry *last);
void ts4_release_all_entries_88662320(Owner *o)
{
    Vec *v = &o->v;
    unsigned int n = v->last - v->first;
    int i;
    for (i = 0; i < n; i++)
        ts4_if_get_u32_offc_8865AAC0(&o->v.first[i]);
    fn_8826B898(v, v->first, v->last);
    o->count = 0;
    o->total = 0;
}
