/* Ball/effect emitter lists: select the current item by key, refresh the current item, set a range.
 * All functions here byte-match on the LTCG route (/Oc); see work/specs/Q5S/q5s_ball_emit.json.
 * Codegen: the vector size helper loads end before begin, and the index access goes through an inline at(). */
typedef unsigned int u32;
#ifdef _MSC_VER
typedef unsigned int q5_uptr;
#else
typedef unsigned long q5_uptr;
#endif

struct Ts4EmitListItem;
typedef void (*Ts4EmitListItemFn)(struct Ts4EmitListItem *);
typedef struct Ts4EmitListItem { void **vt; u32 key; } Ts4EmitListItem;
typedef struct Ts4EmitKey { u32 key; } Ts4EmitKey;
typedef struct Ts4EmitItemVec { Ts4EmitListItem **first, **last, **cap; } Ts4EmitItemVec;
struct Ts4EmitKeyedList;
typedef void (*Ts4EmitKeyedListFn)(struct Ts4EmitKeyedList *);
typedef struct Ts4EmitKeyedList {
    void **vt; char pad4[0x18]; Ts4EmitItemVec items; int cur; int prev; char pad30[8]; Ts4EmitKey *want;
} Ts4EmitKeyedList;
static __inline int ts4_item_vec_size(const Ts4EmitItemVec *v)
{
    Ts4EmitListItem **e = v->last;
    Ts4EmitListItem **b = v->first;
    return e - b;
}
static __inline Ts4EmitListItem *const *ts4_item_vec_at(const Ts4EmitItemVec *v, int i) { return &v->first[i]; }

/* Swing_DLL.xex 0x888AE188: cur = index of the item whose key equals want->key. */
void ts4_emit_list_select_wanted_888AE188(Ts4EmitKeyedList *self)
{
    Ts4EmitKey *k = self->want;
    if (k != 0) {
        int i = 0;
        int n = ts4_item_vec_size(&self->items);
        if (n > 0) {
            u32 key = k->key;
            do {
                if ((*ts4_item_vec_at(&self->items, i))->key == key) {
                    self->cur = i;
                    return;
                }
            } while (++i < n);
        }
    }
}

/* Swing_DLL.xex 0x888AE270: virtual +0x34, wrap cur, notify the current item when forced or changed. */
void ts4_emit_list_refresh_888AE270(Ts4EmitKeyedList *self, unsigned char force)
{
    unsigned n;
    ((Ts4EmitKeyedListFn)self->vt[0x34 / 4])(self);
    n = ts4_item_vec_size(&self->items);
    if (n > 0) {
        if (self->cur >= 0) {
            if (self->cur >= (int)n)
                self->cur = 0;
            if (force || self->cur != self->prev) {
                Ts4EmitListItem *it = *ts4_item_vec_at(&self->items, self->cur);
                ((Ts4EmitListItemFn)it->vt[1])(it);
            }
            if (self->cur != self->prev)
                self->prev = self->cur;
        }
    }
}

/* Swing_DLL.xex 0x888ADBA8: store lo/hi into the linked record when changed, then push both and zero
 * through virtuals +0x74/+0x78/+0x7c. */
extern const float lbl_8814B440;
typedef struct Ts4EmitLoHiRec { char pad[0x10c]; float lo; float hi; } Ts4EmitLoHiRec;
struct Ts4EmitLoHiObj;
typedef void (*Ts4EmitSetF)(struct Ts4EmitLoHiObj *, float);
typedef struct Ts4EmitLoHiObj { void **vt; int pad; int link; } Ts4EmitLoHiObj;
static Ts4EmitLoHiRec *ts4_lohi_rec(int *o) { return (Ts4EmitLoHiRec *)(*o + (char *)o); }
void ts4_emit_set_lohi_888ADBA8(Ts4EmitLoHiObj *self, float a, float b)
{
    Ts4EmitLoHiRec *r;
    float hi;
    if (self->link == 0)
        return;
    r = ts4_lohi_rec((int *)(q5_uptr)self->link);
    if (a != r->lo)
        r->lo = a;
    if (b != r->hi)
        r->hi = b;
    hi = r->hi;
    ((Ts4EmitSetF)self->vt[0x74 / 4])(self, r->lo);
    ((Ts4EmitSetF)self->vt[0x78 / 4])(self, hi);
    ((Ts4EmitSetF)self->vt[0x7c / 4])(self, lbl_8814B440);
}
