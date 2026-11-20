/* Swing_DLL.xex 0x88761508: look up a named id in the scene table, then call the entry helper and the activate helper. */
typedef unsigned int u32;
typedef struct Ts4IdPair { u32 key; int value; } Ts4IdPair;
typedef struct Ts4IdTable { Ts4IdPair *first; Ts4IdPair *last; char pad08[0x18]; char *ents; } Ts4IdTable;
typedef struct Ts4SceneRoot { char pad[0x18]; Ts4IdTable *ids; } Ts4SceneRoot;
extern Ts4SceneRoot *lbl_88D45AD4;
int fn_88608590(int, const char *);
void fn_88760BA0(void *e);
void ts4_pool_rel_8c_88220D90(Ts4IdTable *t, int value);
static __inline int ts4_id_table_lookup(Ts4IdTable *t, u32 key)
{
    Ts4IdPair *p;
    for (p = t->first; p != t->last; p++)
        if (p->key == key) break;
    if (p == t->last) return -1;
    return p->value;
}
void ts4_scene_activate_named_88761508(const char *name)
{
    Ts4SceneRoot *r = lbl_88D45AD4;
    u32 key = fn_88608590(0, name);
    int v = ts4_id_table_lookup(r->ids, key);
    if (v != -1) {
        fn_88760BA0(r->ids->ents + v * 0x8c);
        ts4_pool_rel_8c_88220D90(r->ids, v);
    }
}
