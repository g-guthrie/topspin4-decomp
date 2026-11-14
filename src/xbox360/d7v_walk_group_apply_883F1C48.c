/* Swing_DLL.xex 0x883F1C48, 0x883F1CD8, 0x883F1D68, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4X6Link { struct Ts4X6Link *next; } Ts4X6Link;
typedef struct Ts4X6Group { char pad0[0x30]; u32 padlink; Ts4X6Link inner; } Ts4X6Group;
typedef struct Ts4X6Cfg { char pad0[0x8C]; float f8c; float f90; char pad94[0x70]; float f104; } Ts4X6Cfg;
typedef struct Ts4X6Obj { char pad0[4]; Ts4X6Cfg *cfg; char pad8[4]; Ts4X6Link groups; } Ts4X6Obj;
int fn_883E2598(void *entry, float value);
int fn_883E2640(void *entry, float value);
int fn_883E2790(void *entry, float value);

#define TS4_X6_WALK(NAME, CALLEE, FIELD) \
int NAME(Ts4X6Obj *o) \
{ \
    Ts4X6Link *g; \
    Ts4X6Link *e; \
    Ts4X6Group *grp; \
    int r; \
    for (g = o->groups.next; g != &o->groups; g = g->next) { \
        grp = g != 0 ? (Ts4X6Group *)((char *)g - 4) : 0; \
        e = grp->inner.next; \
        for (; e != &grp->inner; e = e->next) { \
            r = CALLEE(e != 0 ? (char *)e - 4 : (char *)0, o->cfg->FIELD); \
            if (r != 0 && r != 0x24 && r != 0x52) \
                return r; \
        } \
    } \
    return 0; \
}
TS4_X6_WALK(ts4_walk_group_apply_a_883F1C48, fn_883E2598, f104)
TS4_X6_WALK(ts4_walk_group_apply_b_883F1CD8, fn_883E2640, f90)
TS4_X6_WALK(ts4_walk_group_apply_c_883F1D68, fn_883E2790, f8c)
