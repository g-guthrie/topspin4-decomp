/* NEAR MISS (3 off): the table pointer lands in r5, where the target uses r11. */
/* Swing_DLL.xex 0x886F9A60: reset a view's scroll state and bind the scene's current camera to its 0x496663FF entry. */
typedef unsigned int u32;
typedef struct Ts4IdPair { u32 key; int value; } Ts4IdPair;
typedef struct Ts4Entry44 { char pad[8]; int camera; char p0c[0x38]; } Ts4Entry44;
typedef struct Ts4IdTable { void *vt; Ts4IdPair *first; Ts4IdPair *last; char p0c[0x18]; Ts4Entry44 *entries; char p28[0x2c]; int camera; } Ts4IdTable;
typedef struct Ts4SceneRoot { char pad[0x10]; Ts4IdTable *ids; } Ts4SceneRoot;
typedef struct Ts4ViewCfg { char pad[0x64]; int w; int h; } Ts4ViewCfg;
extern Ts4SceneRoot *lbl_88D45AD4;
extern Ts4ViewCfg *lbl_88D45A4C;
typedef struct Ts4View { char pad[0x34]; int scroll; int w; int h; } Ts4View;
static __inline int ts4_id_table_lookup(Ts4IdTable *t, u32 key)
{
    Ts4IdPair *p;
    for (p = t->first; p != t->last; p++)
        if (p->key == key) break;
    if (p != t->last) return p->value;
    return -1;
}
int ts4_view_bind_camera_886F9A60(Ts4View *v)
{
    Ts4ViewCfg *c;
    Ts4SceneRoot *r;
    int i;
    v->scroll = 0;
    c = lbl_88D45A4C;
    r = lbl_88D45AD4;
    v->w = c->w;
    v->h = c->h;
    i = ts4_id_table_lookup(r->ids, 0x496663FF);
    r->ids->entries[i].camera = r->ids->camera;
    return 1;
}
