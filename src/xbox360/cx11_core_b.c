/* CW11 part b: small helpers (0x88606000-0x88610000). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int Cx11Up;
#else
typedef unsigned long Cx11Up;
#endif

/* 0x88606D00: clear the two words at 0xb4 (a two-iteration loop; the compiler unrolls it but keeps the dead base addi) */
typedef struct Cx11PairHolder { u8 pad[0xb4]; u32 w[2]; } Cx11PairHolder;
void ts4_clear_pair_88606D00(Cx11PairHolder *o)
{
    int i;
    for (i = 0; i < 2; i++) o->w[i] = 0;
}

/* Handler lists hang off the global service (lbl_88D45B1C): service->0x4 is a context holding {begin,end} pointer ranges. */
typedef struct Cx11Handler Cx11Handler;
typedef struct Cx11HandlerVt { void *s0[2]; u32 (*slot2)(Cx11Handler *, void *); void *s3[2]; u32 (*slot5)(Cx11Handler *, void *); } Cx11HandlerVt;
struct Cx11Handler { const Cx11HandlerVt *vt; };
typedef struct Cx11HandlerVec { Cx11Handler **begin; Cx11Handler **end; } Cx11HandlerVec;
typedef struct Cx11HandlerCtx { u8 pad[0x10]; Cx11Handler **begin_b; Cx11Handler **end_b; u8 pad2[4]; Cx11HandlerVec a; } Cx11HandlerCtx;
typedef struct Cx11HandlerSvc { u8 pad[4]; Cx11HandlerCtx *ctx; } Cx11HandlerSvc;
extern Cx11HandlerSvc *lbl_88D45B1C;

/* 0x88607740: first handler in the list at 0x1c..0x20 whose slot 2 accepts the event, or null */
Cx11Handler *ts4_find_handler_slot2_88607740(void *event)
{
    Cx11Handler *result = 0;
    Cx11HandlerCtx *c = lbl_88D45B1C->ctx;
    Cx11Handler **end = c->a.end;
    Cx11Handler **it;
    for (it = c->a.begin; end != it; ++it) {
        if ((u8)(*it)->vt->slot2(*it, event) == 1) {
            result = *it;
            break;
        }
    }
    return result;
}

/* 0x886077C0: same search over the list at 0x10..0x14 using slot 5 */
Cx11Handler *ts4_find_handler_slot5_886077C0(void *event)
{
    Cx11Handler *result = 0;
    Cx11HandlerCtx *c = lbl_88D45B1C->ctx;
    Cx11Handler **end = c->end_b;
    Cx11Handler **it;
    for (it = c->begin_b; end != it; ++it) {
        if ((u8)(*it)->vt->slot5(*it, event) == 1) {
            result = *it;
            break;
        }
    }
    return result;
}

/* 0x88607838: first handler in the list at 0x10..0x14 whose slot 2 accepts the event, or null */
Cx11Handler *ts4_find_handler_slot2_list_b_88607838(void *event)
{
    Cx11Handler *result = 0;
    Cx11HandlerCtx *c = lbl_88D45B1C->ctx;
    Cx11Handler **end = c->end_b;
    Cx11Handler **it;
    for (it = c->begin_b; end != it; ++it) {
        if ((u8)(*it)->vt->slot2(*it, event) == 1) {
            result = *it;
            break;
        }
    }
    return result;
}

/* 0x88608428 / 0x8860EBE0: erase one pointer value from a pointer vector (find, move the tail down, shrink) */
typedef struct Cx11PtrVec { void **begin; void **end; } Cx11PtrVec;
extern void fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Cx11VecOwnerA { u8 pad[0x20]; Cx11PtrVec v; } Cx11VecOwnerA;
void ts4_ptrvec_remove_88608428(Cx11VecOwnerA *o, void *value)
{
    void **end = o->v.end;
    Cx11PtrVec *v = &o->v;
    void **it = v->begin;
    if (it != end) {
        do {
            if (value == *it) {
                void **src = it + 1;
                if (src != v->end) fn_88562DC0(it, src, (char *)v->end - (char *)src);
                v->end--;
                return;
            }
            it++;
        } while (it != end);
    }
}
typedef struct Cx11VecOwnerB { u8 pad[0x14b4]; Cx11PtrVec v; } Cx11VecOwnerB;
void ts4_ptrvec_remove_8860EBE0(Cx11VecOwnerB *o, void *value)
{
    void **end = o->v.end;
    Cx11PtrVec *v = &o->v;
    void **it = v->begin;
    if (it != end) {
        do {
            if (*it == value) {
                void **src = it + 1;
                if (src != v->end) fn_88562DC0(it, src, (char *)v->end - (char *)src);
                v->end--;
                return;
            }
            it++;
        } while (it != end);
    }
}

/* 0x8860BA68: upper-case every byte of a char vector in place */
extern int ts4_ascii_lower_to_upper_88564790(int c);
typedef struct Cx11CharVec { char *begin; char *end; } Cx11CharVec;
void ts4_charvec_upcase_8860BA68(Cx11CharVec *v)
{
    u32 n = v->end - v->begin;
    u32 i;
    for (i = 0; i < n; i++) {
        char *p = v->begin + i;
        *p = ts4_ascii_lower_to_upper_88564790(v->begin[i]);
    }
}

/* 0x8860C0B8: return the object itself when its id (0x4) equals the given id, else null */
typedef struct Cx11IdObj { u8 pad[4]; u32 f4; } Cx11IdObj;
Cx11IdObj *ts4_self_if_id_equal_8860C0B8(Cx11IdObj *o, u32 *id)
{
    if (*id - o->f4 == 0) return o;
    return 0;
}

/* 0x8860C128: map a name hash to a small kind code (0 for unknown) */
u32 ts4_hash_to_kind_8860C128(u32 h)
{
    u32 r = 0;
    if (h == 0x99f5620b) return r;
    else if (h == 0x14588b45) r = 2;
    else if (h == 0x93cae023) r = 3;
    else if (h == 0xbc7c2723) r = 4;
    else if (h == 0xc9a1c481) r = 5;
    else if (h == 0x3f34a24d) r = 1;
    return r;
}

/* 0x8860C0D8: does an active slot (flag byte at +0x14 of each 0x6c-byte slot) carry the given x and y values? */
typedef struct Cx11Slot { u32 y; u8 pad4[0x10]; u8 flag; u8 pad15[0x2b]; u32 x; u8 pad44[0x28]; } Cx11Slot;
typedef struct Cx11SlotTab { u8 pad[0x4c]; Cx11Slot s[16]; } Cx11SlotTab;
u32 ts4_slot_table_has_8860C0D8(Cx11SlotTab *t, u32 x, u32 y)
{
    u32 r = 0;
    u32 i;
    for (i = 0; i < 16; i++) {
        if (t->s[i].flag != 0 && x == t->s[i].x && y == t->s[i].y) {
            r = 1;
            break;
        }
    }
    return r;
}

/* 0x88608FE0: for every listed target that is the argument's reference target, call its slot 22; stop once the reference is cleared */
typedef struct Cx11Tgt Cx11Tgt;
typedef struct Cx11Arg Cx11Arg;
typedef struct Cx11Cx11TgtVt { void *s[22]; void (*slot22)(Cx11Tgt *, Cx11Arg *); } Cx11Cx11TgtVt;
struct Cx11Tgt { const Cx11Cx11TgtVt *vt; };
typedef struct Cx11Ref { u8 pad[4]; Cx11Tgt *f4; } Cx11Ref;
struct Cx11Arg { Cx11Ref *ref; };
typedef struct Cx11Disp { u8 pad[0x24]; Cx11Tgt **begin; Cx11Tgt **end; } Cx11Disp;
void ts4_dispatch_to_target_88608FE0(Cx11Disp *d, Cx11Arg *a)
{
    Cx11Tgt **end = d->end;
    Cx11Tgt **it = d->begin;
    for (; end != it; ++it) {
        if (*it == a->ref->f4) {
            (*it)->vt->slot22(*it, a);
            if ((long)a->ref == 0) break;
        }
    }
}

/* 0x8860E1C8: value stored next to the slot whose key matches (slots are {value,key} pairs from 0x30), or -1 */
typedef struct Cx11KeySlot { u32 val; u32 key; } Cx11KeySlot;
typedef struct Cx11KeyTab { u8 pad[0x30]; Cx11KeySlot s[0x8c]; } Cx11KeyTab;
int ts4_value_by_key_8860E1C8(Cx11KeyTab *t, u32 key)
{
    int r = -1;
    int i;
    for (i = 0; i < 0x8c; i++)
        if (t->s[i].key == key) { r = t->s[i].val; break; }
    return r;
}

/* 0x8860ED28: round n up to a multiple of the alignment at 0x1c */
typedef struct Cx11Align { u8 pad[0x1c]; u32 align; } Cx11Align;
u32 ts4_align_up_8860ED28(Cx11Align *o, u32 n)
{
    if (n % o->align == 0) return n;
    return n + (o->align - n % o->align);
}

/* 0x8860B718: remove the item with the given id from the registry's item vector (at 0x74) and return it, or null;
   0x8860B7A8: same, matching another item's id, returning whether one was removed */
typedef struct Cx11Item { u8 pad[4]; u32 id; } Cx11Item;
typedef struct Cx11ItemVec { Cx11Item **begin; Cx11Item **end; } Cx11ItemVec;
typedef struct Cx11Reg { u8 pad[0x74]; Cx11ItemVec v; } Cx11Reg;
Cx11Item *ts4_registry_remove_by_id_8860B718(Cx11Reg *r, u32 id)
{
    Cx11ItemVec *v = &r->v;
    Cx11Item **end = r->v.end;
    Cx11Item **it = v->begin;
    Cx11Item *result = 0;
    Cx11Item *found;
    for (; it != end; ++it) {
        found = *it;
        if (found->id == id) {
            Cx11Item **src = it + 1;
            if (src != v->end) fn_88562DC0(it, src, (char *)v->end - (char *)src);
            result = found;
            v->end--;
            break;
        }
    }
    return result;
}
u32 ts4_registry_remove_item_8860B7A8(Cx11Reg *r, Cx11Item *x)
{
    Cx11ItemVec *v = &r->v;
    Cx11Item **end = r->v.end;
    Cx11Item **it = v->begin;
    u32 result = 0;
    for (; it != end; ++it) {
        if ((*it)->id == x->id) {
            Cx11Item **src = it + 1;
            if (src != v->end) fn_88562DC0(it, src, (char *)v->end - (char *)src);
            result = 1;
            v->end--;
            break;
        }
    }
    return result;
}

/* 0x8860D098: when the guard object at 0x178 reports ready (slot 17), is the value in the item array at 0x180? */
typedef struct Cx11G Cx11G;
typedef struct Cx11GVt { void *s[0x44 / 4]; u32 (*f44)(Cx11G *); } Cx11GVt;
struct Cx11G { const Cx11GVt *vt; };
typedef struct Cx11Own { u8 pad[0x178]; Cx11G *g; u8 pad2[4]; u32 *items; u32 count; } Cx11Own;
u32 ts4_contains_when_ready_8860D098(Cx11Own *o, u32 v)
{
    u32 r = 0;
    if ((u8)o->g->vt->f44(o->g)) {
        u32 n = o->count;
        u32 *p = o->items;
        u32 i = 0;
        if (n != 0) {
            do {
                if (v == *p) { r = 1; break; }
                i++;
                p++;
            } while (i < n);
        }
    }
    return r;
}

/* 0x8860E7B8: first enabled entry of the list at 0x24..0x28 whose slot 17 accepts the argument (returns the last result);
   0x8860E9F0: call slot 14 on enabled entries until one reports non-zero */
typedef struct Cx11Ob Cx11Ob;
typedef struct Cx11ObVt { void *s[14]; u32 (*f38)(Cx11Ob *, u32, u32, u32); void *s2[2]; u32 (*f44)(Cx11Ob *, u32); } Cx11ObVt;
struct Cx11Ob { const Cx11ObVt *vt; u8 pad[0x1c]; u8 enabled; };
typedef struct Cx11Lst { u8 pad[0x24]; Cx11Ob **begin; Cx11Ob **end; } Cx11Lst;
u32 ts4_first_accepting_8860E7B8(Cx11Lst *l, u32 arg)
{
    Cx11Ob **end = l->end;
    Cx11Ob **it;
    u32 r = 0;
    for (it = l->begin; end != it; ++it) {
        Cx11Ob *x = *it;
        if (x->enabled != 0) {
            r = x->vt->f44(x, arg);
            if ((u8)r == 1) break;
        }
    }
    return r;
}
u32 ts4_notify_all_8860E9F0(Cx11Lst *l, u32 a, u32 b, u32 c)
{
    Cx11Ob **end = l->end;
    Cx11Ob **it;
    u32 r = 0;
    for (it = l->begin; end != it && (u8)r == 0; ++it) {
        Cx11Ob *x = *it;
        if (x->enabled != 0) r = x->vt->f38(x, a, b, c);
    }
    return r;
}

/* 0x8860E668: call slot 19 on every enabled entry of the list at 0x24..0x28 and AND the results together */
typedef struct Cx11ObB Cx11ObB;
typedef struct Cx11ObVtB { void *s[19]; u32 (*f4c)(Cx11ObB *, u32, u32, u32); } Cx11ObVtB;
struct Cx11ObB { const Cx11ObVtB *vt; u8 pad[0x1c]; u8 enabled; };
typedef struct Cx11LstB { u8 pad[0x24]; Cx11ObB **begin; Cx11ObB **end; } Cx11LstB;
u32 ts4_all_accept_8860E668(Cx11LstB *l, u32 a, u32 b, u32 c)
{
    Cx11ObB **end = l->end;
    Cx11ObB **it = l->begin;
    u32 r = 1;
    if (end != it) {
        do {
            Cx11ObB *x = *it;
            if (x->enabled != 0) r = (u8)x->vt->f4c(x, a, b, c) & (u8)r;
            it++;
        } while (it != end);
    }
    return r;
}

/* 0x8860DF40: find the first populated entry (12-byte entries from 0xec, up to ten) accepted by fn_881F04B8, visit it and return 1;
   0x8860DFC0: dispatch to the first populated entry whose [hi,lo] range contains x, until one returns non-zero */
typedef struct Cx11Ent { u32 lo; u32 hi; void *p; } Cx11Ent;
typedef struct Cx11Tree { u8 pad[0xec]; Cx11Ent ents[10]; } Cx11Tree;
extern u32 fn_881F04B8(void *p, void *a);
extern void ts4_node_visit_8860DBC8(void *p, void *a);
u32 ts4_tree_visit_first_match_8860DF40(Cx11Tree *t, void *a)
{
    u32 r = 0;
    if (t->ents[0].p != 0) {
        Cx11Ent *end = &t->ents[10];
        Cx11Ent *e = &t->ents[0];
        for (; e < end; e++) {
            if (e->p == 0) break;
            if ((u8)fn_881F04B8(e->p, a) != 0) {
                ts4_node_visit_8860DBC8(e->p, a);
                r = 1;
                break;
            }
        }
    }
    return r;
}
typedef struct Cx11Tree2 { u8 pad[0x28]; u32 limit; u8 pad2[0xec - 0x2c]; Cx11Ent ents[10]; } Cx11Tree2;
struct Cx11Nd;
u32 ts4_node_dispatch_8860DCF8(struct Cx11Nd *n, u32 a, u32 b, u32 c);
u32 ts4_tree_dispatch_range_8860DFC0(Cx11Tree2 *t, u32 x, u32 b, u32 c)
{
    u32 r = 0;
    if (x <= t->limit) {
        if (t->ents[0].p != 0) {
            Cx11Ent *end = &t->ents[10];
            Cx11Ent *e = &t->ents[0];
            for (; e < end; e++) {
                if (e->p == 0) break;
                if (x <= e->lo && x >= e->hi) {
                    r = ts4_node_dispatch_8860DCF8((struct Cx11Nd *)e->p, x, b, c);
                    if (r != 0) break;
                }
            }
        }
    }
    return r;
}

/* 0x8860DCF8: call slot 36 on an active node, record whether it declined, and on a decline offer the event down the sibling chain (0x40)
   until one accepts. Recurses through the placeholder ts4_node_dispatch_8860DCF8, which is also what the earlier function above calls. */
typedef struct Cx11Nd Cx11Nd;
typedef struct Cx11NdVt { void *s[36]; u32 (*f90)(Cx11Nd *, u32, u32, u32); } Cx11NdVt;
struct Cx11Nd { const Cx11NdVt *vt; u8 pad[0x3c]; Cx11Nd *next; u8 pad2[0xe4 - 0x44]; u8 active; u8 pad3[0x171 - 0xe5]; u8 seen; u8 miss; };
#ifdef _MSC_VER
__declspec(noinline)
#endif
u32 ts4_node_dispatch_8860DCF8(Cx11Nd *n, u32 a, u32 b, u32 c)
{
    u32 r;
    if (n->active == 0) return 0;
    r = n->vt->f90(n, a, b, c);
    n->miss = (r == 0);
    if (r == 0) {
        if (n->seen == 0) n->seen = 1;
        n = n->next;
        while (n != 0) {
            r = ts4_node_dispatch_8860DCF8(n, a, b, c);
            n = n->next;
            if (r == 0) continue;
            break;
        }
    }
    return r;
}

/* 0x88608EE8: forward to slot 12 of the second object's vtable with the flag 0x60 or-ed in and an id of -1; returns the first argument */
typedef struct Cx11B Cx11B;
typedef struct Cx11BVt { void *s[12]; void (*f30)(void *a, Cx11B *b, u32 c, u32 d, int e, u32 f); } Cx11BVt;
struct Cx11B { const Cx11BVt *vt; };
void *ts4_call_slot12_with_flag_88608EE8(void *a, Cx11B *b, u32 c, u32 d, u32 e)
{
    b->vt->f30(a, b, c, d | 0x60, -1, e);
    return a;
}

/* 0x886084C8: CRC-32 (table at lbl_880C84C0) of a C string, folding each byte through ts4_if_fn_88567730 (case fold); null gives ~0 */
extern u32 lbl_880C84C0[];
extern int ts4_if_fn_88567730(int c);
#ifdef _MSC_VER
__declspec(noinline)
#endif
u32 ts4_crc32_cstr_nocase_886084C8(const u8 *s)
{
    u32 crc = 0;
    const u8 *p = s;
    if (p != 0) {
        u32 c = *p;
        crc = (u32)-1;
        if (c != 0) {
            do {
                char t = (char)ts4_if_fn_88567730(c);
                crc = lbl_880C84C0[((int)t ^ crc) & 0xff] ^ (crc >> 8);
                c = *++p;
            } while (c != 0);
        }
    }
    return ~crc;
}

/* 0x88608A40: copy the name string (at most 0x1ff bytes) into dst and cut it at the extension dot found by fn_885647D0 */
extern const char *ts4_if_call_seq_lbl_880C1320_88606800(void *a);
extern char *fn_885647D0(const char *s, int c);
void ts4_name_without_ext_88608A40(void *a, char *dst)
{
    const char *src = ts4_if_call_seq_lbl_880C1320_88606800(a);
    char *end = dst + 0x1ff;
    char *p = dst;
    char *dot;
    while (p != end) {
        u8 c = src[p - dst];
        if (c == 0) break;
        *p = c;
        p++;
    }
    *p = 0;
    if (*dst != 0) {
        dot = fn_885647D0(dst, 0x2e);
        if (dot != 0) *dot = 0;
    }
}

/* 0x886090A0: copy a path, turn backslashes into slashes, skip a drive prefix, force a leading slash, and hash it with the case-folding CRC.
   strcpy is the compiler intrinsic here. */
#ifdef _MSC_VER
extern char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
#else
#include <string.h>
#endif
u32 *ts4_hash_normalized_path_886090A0(u32 *out, const char *path)
{
    char arr[0x210];
    char *buf = arr + 1;
    char *p;
    strcpy(buf, path);
    p = buf;
    if (*p != 0) {
        do {
            if (*p == '\\') *p = '/';
            p++;
        } while (*p != 0);
    }
    p = buf;
    if (buf[1] == ':') p = buf + 2;
    if (*p != '/') {
        p[-1] = '/';
        p--;
    }
    *out = ts4_crc32_cstr_nocase_886084C8((const u8 *)p);
    return out;
}

/* 0x88608858 / 0x886088C8: heap block search: first block (forward from the head's successor / backward from the end's predecessor)
   with room for `size` words once the start is aligned; stores the aligned start and returns the block */
typedef struct Cx11Blk { u8 pad[8]; u32 f8; struct Cx11Blk *next; } Cx11Blk;
typedef struct Cx11Hp { u8 pad[0x180]; Cx11Blk *head; Cx11Blk *end; } Cx11Hp;
Cx11Blk *ts4_heap_find_fit_88608858(Cx11Hp *h, int size, int align, u32 *out)
{
    Cx11Blk *result = 0;
    Cx11Blk *end = h->end;
    Cx11Blk *b = h->head->next;
    for (; end != b; b = b->next) {
        int avail = (int)(b->f8 >> 2) + 8;
        if (avail >= size) {
            u32 start = (u32)(((((Cx11Up)b + align + 0xb) & (u32)-align)) - 0xc);
            avail = avail - (int)(start - (Cx11Up)b);
            if (avail >= size) {
                *out = start;
                result = b;
                break;
            }
        }
    }
    return result;
}
typedef struct Cx11Blk2 { u8 pad[8]; u32 f8; u8 padc[4]; struct Cx11Blk2 *prev; } Cx11Blk2;
typedef struct Cx11Hp2 { u8 pad[0x180]; Cx11Blk2 *head; Cx11Blk2 *end; } Cx11Hp2;
Cx11Blk2 *ts4_heap_find_fit_back_886088C8(Cx11Hp2 *h, int size, int align, u32 *out)
{
    Cx11Blk2 *result = 0;
    Cx11Blk2 *head = h->head;
    Cx11Blk2 *b = h->end->prev;
    for (; b != head; b = b->prev) {
        int avail = (int)(b->f8 >> 2) + 8;
        if (avail >= size) {
            u32 start = (u32)((((Cx11Up)b + (avail - size) + 0xc) & (u32)-align) - 0xc);
            int off = (int)(start - (Cx11Up)b);
            if (off > 0) {
                avail = avail - off;
                if (avail >= size) {
                    *out = start;
                    result = b;
                    break;
                }
            }
        }
    }
    return result;
}

/* 0x886060D8: bounded wide-string copy: copies up to n-1 characters, always terminating */
typedef unsigned short Cx11U16;
void ts4_wstrncpy_886060D8(Cx11U16 *dst, const Cx11U16 *src, u32 n)
{
    int off = (int)((char *)src - (char *)dst);
    do {
        Cx11U16 c = *(Cx11U16 *)((char *)dst + off);
        *dst = c;
        if (c == 0) return;
        n--;
        dst++;
    } while (n > 1);
    *dst = 0;
}
