/* Swing_DLL.xex 0x88656ED0, 0x88656FD0: slot table of a 4-entry id list */
typedef struct W9aE { char pad[0x18]; unsigned key; } W9aE;
typedef struct W9aH { int rel; int count; } W9aH;
typedef struct W9aP { char pad[0x48]; W9aH h; } W9aP;
typedef struct W9aSubV { void **vt; } W9aSubV;
typedef struct W9aS { char p0[0x1c]; W9aSubV sub; char p1[0x78 - 0x20]; unsigned w78; } W9aS;
extern unsigned ts4_alloc_slot_by_id_88656ED0(W9aS *s, unsigned k);
extern unsigned fn_88656378(W9aS *s, unsigned k);
extern void ts4_zero_record_886562A0(W9aS *s, unsigned i);
#define VC30(o) (((unsigned char (*)(void *))((o)->vt[0x30 / 4]))(o))
#define VC4C(o, a) (((W9aP *(*)(void *, int))((o)->vt[0x4c / 4]))(o, a))
#ifdef _MSC_VER
__declspec(noinline)
#endif
unsigned ts4_alloc_slot_by_id_88656ED0(W9aS *s, unsigned key)
{
    unsigned r = 4;
    if (s->w78 == 0 && VC30(&s->sub)) {
        r = fn_88656378(s, key);
        if (r == 4) {
            W9aH *h;
            W9aE *found = 0, *e, *end;
            W9aP *p = VC4C(&s->sub, 0);
            r = 0;
            h = &p->h;
            end = 0;
            if (h->rel != -1) end = (W9aE *)((char *)h + (h->count * 0x1c + h->rel));
            e = 0;
            if (h->rel != -1) e = (W9aE *)((char *)h + h->rel);
            for (; end != e; e++) {
                if (e->key == 0) { found = e; break; }
                r++;
            }
            if (found) { found->key = key; ts4_zero_record_886562A0(s, r); }
        }
        if (r > 4) r = 4;
    }
    return r;
}

unsigned ts4_find_slot_by_id_88656FD0(W9aS *s, unsigned key, unsigned c)
{
    unsigned r = 4;
    if (s->w78 == c) {
        unsigned i = 4;
        if (VC30(&s->sub)) {
            W9aH *h;
            W9aE *e, *end;
            W9aP *p = VC4C(&s->sub, 0);
            i = 0;
            h = &p->h;
            end = 0;
            if (h->rel != -1) end = (W9aE *)((char *)h + (h->count * 0x1c + h->rel));
            e = 0;
            if (h->rel != -1) e = (W9aE *)((char *)h + h->rel);
            for (; end != e; e++) {
                if (key == e->key) break;
                i++;
            }
        }
        if (i >= 4) r = ts4_alloc_slot_by_id_88656ED0(s, key);
        else r = i;
    }
    return r;
}
