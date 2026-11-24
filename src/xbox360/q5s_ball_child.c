/* Ball/effect child objects (vtables 0x880DC550..): small accessors and setters.
 * All functions here byte-match on the LTCG route (/Oc); see work/specs/Q5S/q5s_ball_child.json. */
#include "vx1_vector.h"

__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#ifdef _MSC_VER
#pragma intrinsic(__vsldoi)
typedef unsigned int q5_uptr;
#else
typedef unsigned long q5_uptr;
#endif

typedef unsigned int u32;
typedef struct Ts4Vec3f { float x, y, z; } Ts4Vec3f;

/* Self-relative link: the word holds an offset from its own address; -1 means none. */
typedef struct Ts4EmitRecFlag { char pad[0x94]; unsigned char active; } Ts4EmitRecFlag;
typedef struct Ts4EmitRecId { char pad[0x64]; u32 id; } Ts4EmitRecId;
typedef struct Ts4EmitRange { int pad0; Ts4Vec3f lo3, hi3; char pad1c[0xc]; float lo; float hi; } Ts4EmitRange;

typedef struct Ts4EmitLinkHolder { char pad[8]; int *link; } Ts4EmitLinkHolder;

static Ts4EmitRecFlag *ts4_link_flag(int *o) { return *o != -1 ? (Ts4EmitRecFlag *)(*o + (char *)o) : 0; }
static Ts4EmitRecId *ts4_link_id(int *o) { return *o != -1 ? (Ts4EmitRecId *)(*o + (char *)o) : 0; }
static Ts4EmitRange *ts4_link_range(int *o) { return (Ts4EmitRange *)(*o + (char *)o); }

/* Swing_DLL.xex 0x888AF298: active byte of the linked record (0 when unlinked). */
unsigned char ts4_emit_link_active_888AF298(Ts4EmitLinkHolder *self)
{
    int *o = self->link;
    if ((long)o != 0) {
        Ts4EmitRecFlag *p = ts4_link_flag(o);
        if (p)
            return p->active;
    }
    return 0;
}

/* Swing_DLL.xex 0x888AF6B8: value of the current item, when the list is not empty. */
typedef struct Ts4EmitItem { char pad[4]; u32 value; } Ts4EmitItem;
typedef struct Ts4EmitItemList { char pad[0x1c]; Ts4EmitItem **begin; Ts4EmitItem **end; int cap; int cur; } Ts4EmitItemList;
void ts4_emit_current_item_value_888AF6B8(Ts4EmitItemList *self, u32 *out)
{
    unsigned n = self->end - self->begin;
    if (n > 0)
        *out = self->begin[self->cur]->value;
}

/* Swing_DLL.xex 0x888AEE68: clamp the +0x90 float to non-negative. */
static const float kZero = 0.0f;
static __inline float ts4_fsel_max(float a, float b) { return (a - b >= kZero) ? a : b; }
typedef struct Ts4EmitF90 { char pad[0x90]; float value; } Ts4EmitF90;
void ts4_emit_clamp_nonneg_888AEE68(Ts4EmitF90 *self)
{
    self->value = ts4_fsel_max(kZero, self->value);
}

/* Swing_DLL.xex 0x888AF408: id of the linked record, or the global default's +0x27c. */
typedef struct Ts4EmitDefaults { char pad[0x27c]; u32 id; } Ts4EmitDefaults;
extern Ts4EmitDefaults *lbl_88D45B1C;
void ts4_emit_link_id_888AF408(u32 *out, Ts4EmitLinkHolder *self)
{
    int *o = self->link;
    if ((long)o != 0)
        *out = ts4_link_id(o)->id;
    else
        *out = lbl_88D45B1C->id;
}

/* Swing_DLL.xex 0x888AEDD0: copy the ranges from the linked record and mark all dirty. */
typedef struct Ts4EmitRangeOwner {
    char pad0[8]; int *link; Ts4Vec3f lo3, hi3; char pad24[0xc]; float w;
    unsigned char dirty0, dirty1, dirty2, dirty3; char pad38[0x44]; unsigned char use_hi;
} Ts4EmitRangeOwner;
static __inline void ts4_cp3(Ts4Vec3f *d, const Ts4Vec3f *s) { d->x = s->x; d->y = s->y; d->z = s->z; }
void ts4_emit_load_ranges_888AEDD0(Ts4EmitRangeOwner *self)
{
    int *o = self->link;
    Ts4EmitRange *r;
    if ((long)o == 0)
        return;
    r = ts4_link_range(o);
    ts4_cp3(&self->lo3, &r->lo3);
    ts4_cp3(&self->hi3, &r->hi3);
    self->w = self->use_hi ? r->hi : r->lo;
    self->dirty0 = 1; self->dirty1 = 1; self->dirty2 = 1; self->dirty3 = 1;
}

/* Swing_DLL.xex 0x888AF2D0: clear the linked record's active flag, unregister, release. */
struct Ts4EmitObj;
typedef struct Ts4EmitObjVt { void *slots[27]; void (*release)(struct Ts4EmitObj *, int); } Ts4EmitObjVt;
typedef struct Ts4EmitObj { Ts4EmitObjVt *vt; int pad; int *link; } Ts4EmitObj;
extern char *lbl_88D45964;
void ts4_ptr_vec_erase_key_888AD5E0(char *self, u32 key);
void ts4_emit_release_888AF2D0(Ts4EmitObj *self)
{
    int *o = self->link;
    if ((long)o != 0) {
        Ts4EmitRecFlag *r = ts4_link_flag(o);
        if (r) {
            r->active = 0;
            ts4_ptr_vec_erase_key_888AD5E0(lbl_88D45964, (u32)(q5_uptr)self);
        }
    }
    self->vt->release(self, 0);
}

/* Swing_DLL.xex 0x888AE7F8 / 0x888AE880: look a child up by id and pass it two vec3s. */
struct Ts4EmitChild;
typedef void (*Ts4ChildSetVV)(struct Ts4EmitChild *, __vector4, __vector4);
typedef void (*Ts4ChildSetVVFF)(struct Ts4EmitChild *, __vector4, __vector4, float, float);
typedef struct Ts4EmitChild { void **vt; } Ts4EmitChild;
typedef struct Ts4EmitSvc Ts4EmitSvc;
typedef struct Ts4EmitOwner { char pad[0x10]; Ts4EmitSvc *svc; } Ts4EmitOwner;
Ts4EmitChild *ts4_find_child_by_id_888AD568(Ts4EmitSvc *self, u32 *key);
static __inline __vector4 ts4_load3(const Ts4Vec3f *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}
void ts4_emit_child_set_vv_888AE7F8(Ts4EmitOwner *self, u32 key, const Ts4Vec3f *a, const Ts4Vec3f *b)
{
    Ts4EmitSvc *svc = self->svc;
    if (svc) {
        u32 id = key;
        Ts4EmitChild *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o)
            ((Ts4ChildSetVV)o->vt[0x54 / 4])(o, ts4_load3(a), ts4_load3(b));
    }
}
void ts4_emit_child_set_vvff_888AE880(Ts4EmitOwner *self, u32 key, const Ts4Vec3f *a, const Ts4Vec3f *b,
                                      const float *lo, const float *hi)
{
    Ts4EmitSvc *svc = self->svc;
    if (svc) {
        u32 id = key;
        Ts4EmitChild *o = ts4_find_child_by_id_888AD568(svc, &id);
        if (o)
            ((Ts4ChildSetVVFF)o->vt[0x50 / 4])(o, ts4_load3(a), ts4_load3(b), *lo, *hi);
    }
}
