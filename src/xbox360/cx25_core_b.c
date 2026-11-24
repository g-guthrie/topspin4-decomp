/* CX25 part b: game core 0x881EEBB0-0x8820F390 (self-relative element arrays, small tables), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- string equality, by-value argument form (length at -0xc of the character data) ---- */
int fn_885630C0(const char *a, const char *b, int n);
static __inline u8 cx25b_streq(const char *a, const char *b)
{
    int n = ((int *)a)[-3];
    if (n != ((int *)b)[-3]) return 0;
    return fn_885630C0(a, b, n) == 0;
}

/* ---- self-relative arrays of variable-size elements; the element size comes from a virtual call ---- */
typedef struct Cx25bInfo { u8 pad[0xc]; u32 size; } Cx25bInfo;
typedef struct Cx25bElem Cx25bElem;
typedef struct Cx25bElemVt { Cx25bInfo *(*info)(Cx25bElem *); } Cx25bElemVt;
struct Cx25bElem { const Cx25bElemVt *vt; u8 pad[8]; const char *name; };
typedef struct Cx25bArr { u8 pad[0x10]; u32 count; Cx25bElem first; } Cx25bArr;

/* 0x881F07F8: find the element whose name equals *name, stepping by each element's own size */
Cx25bElem *ts4_elem_find_881F07F8(Cx25bArr *a, const char **name)
{
    u32 n = a->count;
    Cx25bElem *e = &a->first;
    u32 i = 0;
    if (n != 0) {
        do {
            if (cx25b_streq(e->name, *name)) return e;
            e = (Cx25bElem *)((char *)e + e->vt->info(e)->size);
            i++;
        } while (i < n);
    }
    return 0;
}

typedef struct Cx25bArr14 { u8 pad[0x14]; Cx25bElem first; } Cx25bArr14;

/* 0x881F0888: address of the idx-th element */
Cx25bElem *ts4_elem_at_881F0888(Cx25bArr14 *a, u32 idx)
{
    Cx25bElem *e = &a->first;
    if (idx != 0) {
        u32 n = idx;
        do {
            e = (Cx25bElem *)((char *)e + e->vt->info(e)->size);
        } while (--n != 0);
    }
    return e;
}

/* 0x88201798: map one of three known hashes to 1..3; the fourth hash gives 0, everything else 4 */
u32 ts4_hash_to_kind_88201798(u32 h)
{
    u32 r = 4;
    if (h == 0x01403330u) return 1;
    if (h == 0x33EB4F4Cu) return 2;
    if (h == 0x3705EF5Du) return 3;
    if ((h + 0x94446197u) == 0) r = 0;
    return r;
}

/* ---- 8-byte record vector ---- */
typedef struct Cx25bR8 { u32 a, b; } Cx25bR8;
typedef struct Cx25bV8 { u32 p0; Cx25bR8 *data; u32 count; } Cx25bV8;
extern void ts4_grow_reserve_8_881DA390(Cx25bV8 *v, u32 n);

/* 0x8820AB98: append a record (grow first), return its index */
u32 ts4_v8_push_back_8820AB98(Cx25bV8 *v, Cx25bR8 *val)
{
    Cx25bR8 *p;
    ts4_grow_reserve_8_881DA390(v, v->count + 1);
    p = v->data + v->count;
    if (p != 0) {
        u32 x = val->a;
        u32 y = val->b;
        p->b = y;
        p->a = x;
    }
    return v->count++;
}

/* 0x88207848: value of the record with the largest key not above `key`; returns whether one was found */
u32 ts4_table_nearest_88207848(u32 key, Cx25bV8 *t, u32 *out)
{
    int best = 0x7fffffff;
    u32 val = (u32)-1;
    int i;
    int n = (int)t->count;
    for (i = 0; i < n; i++) {
        Cx25bR8 *e = &t->data[i];
        if (e->a <= key && (int)(key - e->a) < best) {
            best = (int)(key - e->a);
            val = e->b;
        }
    }
    if (val != (u32)-1) {
        *out = val;
        return 1;
    }
    return 0;
}

/* ---- zero-initialised block slots ---- */
typedef struct Cx25bSvc Cx25bSvc;
typedef struct Cx25bSvcVt { void *s[4]; char *(*get_block)(Cx25bSvc *); } Cx25bSvcVt;
struct Cx25bSvc { const Cx25bSvcVt *vt; };
extern Cx25bSvc *lbl_88D3E418;
extern Cx25bSvc *ts4_if_get_u32_lbl_88D45B38_8819A938(void);
typedef struct Cx25bSlot { char *block; u32 pad; } Cx25bSlot;

/* 0x8820B310: point each of n 8-byte slots at a fresh service block (+0x10) */
void ts4_slots_init_8820B310(Cx25bSlot *slots, u32 n)
{
    while (n != 0) {
        Cx25bSlot *s = slots;
        n--;
        slots++;
        if (s != 0) {
            Cx25bSvc *g = lbl_88D3E418;
            if (g == 0) g = ts4_if_get_u32_lbl_88D45B38_8819A938();
            s->block = g->vt->get_block(g) + 0x10;
        }
    }
}

/* ---- doubly linked list with 12-byte payloads (head +0x14, tail +0x18, count +0x1c) ---- */
typedef struct Cx25bDNode Cx25bDNode;
struct Cx25bDNode { Cx25bDNode *next; Cx25bDNode *prev; u32 data[3]; };
typedef struct Cx25bDList { u8 pad[0x14]; Cx25bDNode *head; Cx25bDNode *tail; u32 count; } Cx25bDList;
extern Cx25bDNode *fn_8818F1D8(Cx25bDList *l);
extern void fn_88201580(void *dst, void *src);
extern void ts4_if_get_u32_lbl_88D3E418_882016F8(void *dst, void *src);


/* 0x88204538 */
Cx25bDNode *ts4_dlist_insert_before_88204538(Cx25bDList *l, Cx25bDNode *pos, void *src)
{
    Cx25bDNode *n;
    if (pos == 0) {
        Cx25bDNode *first = l->head;
        n = fn_8818F1D8(l);
        if (n != 0) fn_88201580(n->data, src);
        n->next = first;
        n->prev = 0;
        l->count++;
        if (l->head != 0) l->head->prev = n;
        else l->tail = n;
        l->head = n;
    } else {
        Cx25bDNode *prev = pos->prev;
        n = fn_8818F1D8(l);
        if (n != 0) fn_88201580(n->data, src);
        n->prev = prev;
        n->next = pos;
        l->count++;
        if (pos->prev != 0) pos->prev->next = n;
        else l->head = n;
        pos->prev = n;
    }
    return n;
}

/* 0x88204728 */
Cx25bDNode *ts4_dlist_insert_after_88204728(Cx25bDList *l, Cx25bDNode *pos, void *src)
{
    Cx25bDNode *n;
    if (pos == 0) {
        Cx25bDNode *last = l->tail;
        n = fn_8818F1D8(l);
        if (n != 0) ts4_if_get_u32_lbl_88D3E418_882016F8(n->data, src);
        n->prev = last;
        n->next = 0;
        l->count++;
        if (l->tail != 0) l->tail->next = n;
        else l->head = n;
        l->tail = n;
    } else {
        Cx25bDNode *next = pos->next;
        n = fn_8818F1D8(l);
        if (n != 0) ts4_if_get_u32_lbl_88D3E418_882016F8(n->data, src);
        n->prev = pos;
        n->next = next;
        l->count++;
        if (pos->next != 0) pos->next->prev = n;
        else l->tail = n;
        pos->next = n;
    }
    return n;
}

/* ---- pointer vector ---- */
typedef struct Cx25bPV { u32 p0; u32 *data; u32 count; } Cx25bPV;
extern void fn_881F26C0(void *p, u32 n);
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

/* 0x8820AF78: release n pointers starting at idx (via the array releaser), close the gap */
void ts4_pv_erase_range_8820AF78(Cx25bPV *v, u32 idx, u32 n)
{
    u32 rest = v->count - idx - n;
    fn_881F26C0(v->data + idx, n);
    if (rest != 0)
        fn_88562DC0(v->data + idx, v->data + (idx + n), rest * 4);
    v->count -= n;
}

/* ---- three owned buffers ---- */
extern void fn_881992A8(u32 z, void *p);
typedef struct Cx25bBuf { u32 a; void *ptr; u32 n; u32 d; } Cx25bBuf;
typedef struct Cx25bTri { u8 pad[0xc]; Cx25bBuf b0; Cx25bBuf b1; Cx25bBuf b2; } Cx25bTri;
static __inline void cx25b_free_buf(Cx25bBuf *b)
{
    if (b->ptr != 0) {
        fn_881992A8(0, b->ptr);
        b->ptr = 0;
    }
    b->n = 0;
    b->d = 0;
    b->a = 0;
}

/* 0x88209F50 */
u32 ts4_tri_clear_88209F50(Cx25bTri *t)
{
    Cx25bBuf *b = &t->b0;
    if (b->ptr != 0) {
        fn_881F26C0(b->ptr, b->n);
        if (b->ptr != 0) fn_881992A8(0, b->ptr);
        b->ptr = 0;
    }
    b->n = 0;
    b->d = 0;
    b->a = 0;
    {
        Cx25bBuf *c = &t->b2;
        if (c->ptr != 0) {
            fn_881992A8(0, c->ptr);
            c->ptr = 0;
        }
        c->n = 0;
        c->a = 0;
        c->d = 0;
    }
    cx25b_free_buf(&t->b1);
    return 1;
}

/* ---- small flag and kind helpers ---- */
typedef struct Cx25bKd { u8 pad[0x68]; u8 kind : 3; u8 rest : 5; } Cx25bKd;
typedef struct Cx25bZ { u8 pad[0x7c]; u32 f7c; } Cx25bZ;

/* 0x8820CBA8 */
void ts4_set_kind_from_hash_8820CBA8(void *unused, Cx25bKd *o, u32 *hash)
{
    u32 kind = 1;
    (void)unused;
    if (*hash == 0xDA554856u) kind = 0;
    else if (*hash == 0x750B5A10u) kind = 2;
    o->kind = kind;
}

/* 0x88204A78 */
int ts4_f7c_is_zero_88204A78(void *unused, Cx25bZ *o)
{
    (void)unused;
    return 0 == o->f7c;
}

/* ---- pointer vector with an allocator-owned buffer: resize and reserve ---- */
extern void *ts4_if_call_seq_u32_off0_8818C588(void *self, u32 bytes);
typedef struct Cx25bPV2 { u32 p0; u32 *data; u32 count; u32 cap; } Cx25bPV2;
extern void ts4_pv_reserve_881F25F0(Cx25bPV2 *v, u32 n);

/* 0x881F2510 */
void ts4_pv_resize_881F2510(Cx25bPV2 *v, u32 n)
{
    if (n == 0) {
        if (v->data != 0) {
            fn_881F26C0(v->data, v->count);
            if (v->data != 0) fn_881992A8(0, v->data);
            v->data = 0;
        }
        v->count = 0;
        v->cap = 0;
        return;
    }
    if (n <= v->cap) {
        if (v->count > n) {
            u32 *nb;
            fn_881F26C0(v->data + n, v->count - n);
            nb = (u32 *)ts4_if_call_seq_u32_off0_8818C588(v, n * 4);
            fn_88562DC0(nb, v->data, v->count * 4);
            if (v->data != 0) fn_881992A8(0, v->data);
            v->data = nb;
            v->cap = n;
            v->count = n;
        }
    } else {
        ts4_pv_reserve_881F25F0(v, n);
    }
}

/* 0x881F25F0 */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_pv_reserve_881F25F0(Cx25bPV2 *v, u32 n)
{
    if (n > v->cap) {
        if (v->data == 0) {
            v->data = (u32 *)ts4_if_call_seq_u32_off0_8818C588(v, n * 4);
            if (v->data != 0) v->cap = n;
        } else {
            u32 step = v->count >> 3;
            u32 sum;
            u32 nc;
            u32 *nb;
            if (step < 4) step = 4;
            else if (step > 0x400) step = 0x400;
            sum = v->cap + step;
            nc = (n < sum) ? sum : n;
            nb = (u32 *)ts4_if_call_seq_u32_off0_8818C588(v, nc * 4);
            if (nb != 0) {
                fn_88562DC0(nb, v->data, v->count * 4);
                if (v->data != 0) fn_881992A8(0, v->data);
                v->data = nb;
                v->cap = nc;
            }
        }
    }
}

/* ---- two-axis range object clamped against the limits of a sub-object ---- */
typedef struct Cx25bLim Cx25bLim;
typedef struct Cx25bLimVt { void *s[10]; u32 (*lim_b)(Cx25bLim *); u32 (*lim_a)(Cx25bLim *); } Cx25bLimVt;
struct Cx25bLim { const Cx25bLimVt *vt; };
typedef struct Cx25bRng Cx25bRng;
typedef struct Cx25bRngVt { void *s[30]; void (*move)(Cx25bRng *, u32, u32); void *s2[5]; void (*changed)(Cx25bRng *); } Cx25bRngVt;
struct Cx25bRng {
    const Cx25bRngVt *vt; u8 pad[0x20]; Cx25bLim *lim; u8 pad2[0x39]; u8 wrap; u8 pad2b[0x1a];
    u32 b; u32 a; u8 pad3[0x2c]; u32 min_a; u32 min_b;
};

/* 0x88209320 */
void ts4_range_set_88209320(Cx25bRng *o, u32 a, u32 b)
{
    u32 old_b = o->b;
    u32 old_a = o->a;
    if (a < o->min_a) a = o->min_a;
    if (b < o->min_b) b = o->min_b;
    if (a >= o->lim->vt->lim_a(o->lim)) a = o->lim->vt->lim_a(o->lim) - 1;
    if (b >= o->lim->vt->lim_b(o->lim)) b = o->lim->vt->lim_b(o->lim) - 1;
    o->b = b;
    o->a = a;
    if (b != old_b || a != old_a) o->vt->changed(o);
}

/* 0x88209400 */
void ts4_range_step_back_b_88209400(Cx25bRng *o)
{
    u32 b = o->b;
    if (b <= o->min_b) {
        if (o->wrap != 0) b = o->lim->vt->lim_b(o->lim) - 1;
    } else {
        b = b - 1;
    }
    o->vt->move(o, o->a, b);
}

/* 0x88209520 */
void ts4_range_step_back_a_88209520(Cx25bRng *o)
{
    u32 a = o->a;
    if (a <= o->min_a) {
        if (o->wrap != 0) a = o->lim->vt->lim_a(o->lim) - 1;
    } else {
        a = a - 1;
    }
    o->vt->move(o, a, o->b);
}


/* ---- sorted name table (offsets into a string blob) ---- */
#ifdef _MSC_VER
extern int strcmp(const char *a, const char *b);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif
typedef struct Cx25bNames { u8 pad[0x14]; int count; u32 *offs; char *base; } Cx25bNames;

/* 0x88206EA0: CRT-style binary search of a sorted name table; the dead local fixes the operand order of the indexed load */
int ts4_names_bsearch_88206EA0(Cx25bNames *o, const char *key)
{
    int pad0 = 0;
    int lo = 0;
    int hi = o->count - 1;
    int num = o->count;
    (void)pad0;
    while (lo <= hi) {
        int half = num / 2;
        if (half != 0) {
            int mid = lo + ((num & 1) ? half : half - 1);
            int c = strcmp(key, o->base + o->offs[mid] + 1);
            if (c == 0) return mid;
            if (c < 0) {
                hi = mid - 1;
                num = (num & 1) ? half : half - 1;
            } else {
                lo = mid + 1;
                num = half;
            }
        } else if (num != 0) {
            if (strcmp(key, o->base + o->offs[lo] + 1) == 0) return lo;
            return -1;
        } else {
            break;
        }
    }
    return -1;
}

/* ---- object with an on/off byte and virtual transition hooks ---- */
typedef struct Cx25bTg Cx25bTg;
typedef struct Cx25bTgVt { void *s[26]; void (*on)(Cx25bTg *); void (*off)(Cx25bTg *); } Cx25bTgVt;
struct Cx25bTg { const Cx25bTgVt *vt; u8 pad[0x1e]; u8 state; u8 flags; };

/* 0x88200DE8: set the on/off state, running the matching virtual hook when it changes, and mark the object dirty when turned on */
void ts4_set_state_88200DE8(Cx25bTg *o, u8 v)
{
    u8 on = v;
    int cur = o->state != 0;
    if ((int)on != cur) {
        if (on != 0) o->vt->on(o);
        else o->vt->off(o);
    }
    o->state = v;
    if (on != 0) o->flags |= 0x80;
}

/* ---- grid with a virtual width ---- */
typedef struct Cx25bGr Cx25bGr;
typedef struct Cx25bGrVt { void *s[11]; u32 (*width)(Cx25bGr *); } Cx25bGrVt;
struct Cx25bGr { const Cx25bGrVt *vt; u8 pad[0xc]; u32 *cells; };

/* 0x88207150: cell at (x, y) of a row-major grid whose row width is a virtual call */
u32 ts4_grid_cell_88207150(Cx25bGr *g, u32 x, u32 y)
{
    u32 idx = g->vt->width(g) * y + x;
    return g->cells[idx];
}
