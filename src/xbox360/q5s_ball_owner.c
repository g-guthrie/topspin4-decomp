/* Emitter owner: set a float on a child, defaulting the key to the first list's current item.
 * Byte-matches on the LTCG route (/Oc) with q5s_ball_child.c as context (888AF6B8 inlines);
 * see work/specs/Q5S/q5s_ball_owner.json. */
typedef unsigned int u32;
typedef struct Ts4EmitItem { char pad[4]; u32 value; } Ts4EmitItem;
typedef struct Ts4EmitItemList { char pad[0x1c]; Ts4EmitItem **begin; Ts4EmitItem **end; int cap; int cur; } Ts4EmitItemList;
void ts4_emit_current_item_value_888AF6B8(Ts4EmitItemList *self, u32 *out);
struct Ts4EmitChild;
typedef void (*Ts4ChildSetF)(struct Ts4EmitChild *, float);
typedef struct Ts4EmitChild { void **vt; } Ts4EmitChild;
typedef struct Ts4EmitListVec { Ts4EmitItemList **first, **last, **cap; } Ts4EmitListVec;
typedef struct Ts4EmitSvc { char pad[0x1c]; Ts4EmitListVec lists; } Ts4EmitSvc;
typedef struct Ts4EmitOwner { char pad[0x10]; Ts4EmitSvc *svc; } Ts4EmitOwner;
Ts4EmitChild *ts4_find_child_by_id_888AD568(Ts4EmitSvc *self, u32 *key);
static __inline int ts4_lv_size(const Ts4EmitListVec *v) { Ts4EmitItemList **e = v->last; Ts4EmitItemList **b = v->first; return e - b; }
static __inline Ts4EmitItemList *const *ts4_lv_at(const Ts4EmitListVec *v, int i) { return &v->first[i]; }

/* Swing_DLL.xex 0x888AF6E8 */
void ts4_emit_owner_set_f_888AF6E8(Ts4EmitOwner *self, u32 key, float v)
{
    u32 k = key;
    Ts4EmitChild *o;
    if (k == 0) {
        unsigned n = ts4_lv_size(&self->svc->lists);
        if (n > 0)
            ts4_emit_current_item_value_888AF6B8(*ts4_lv_at(&self->svc->lists, 0), &k);
    }
    {
        u32 id = k;
        o = ts4_find_child_by_id_888AD568(self->svc, &id);
    }
    if (o)
        ((Ts4ChildSetF)o->vt[0x88 / 4])(o, v);
}
