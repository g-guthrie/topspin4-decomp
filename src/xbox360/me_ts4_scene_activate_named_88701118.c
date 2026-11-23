/* Swing_DLL.xex 0x88701118: look up a named entry in the scene's id table and activate it when present. */
typedef unsigned int u32;
typedef struct Ts4IdPair { u32 key; int value; } Ts4IdPair;
typedef struct Ts4IdTable Ts4IdTable;
typedef struct Ts4IdTableVt { void *s0; void (*activate)(Ts4IdTable *t, int value); } Ts4IdTableVt;
struct Ts4IdTable { Ts4IdTableVt *vt; Ts4IdPair *first; Ts4IdPair *last; };
typedef struct Ts4SceneRoot { char pad[0x10]; Ts4IdTable *ids; } Ts4SceneRoot;
extern Ts4SceneRoot *lbl_88D45AD4;
extern const char lbl_880F1084[];
int ts4_crc32_cstr_seed_88608590(int, const char *);
static __inline int ts4_id_table_lookup(Ts4IdTable *t, u32 key)
{
    Ts4IdPair *p;
    for (p = t->first; p != t->last; p++)
        if (p->key == key) break;
    if (p == t->last) return -1;
    return p->value;
}
void ts4_scene_activate_named_88701118(void)
{
    Ts4IdTable *t = lbl_88D45AD4->ids;
    int v = ts4_id_table_lookup(t, ts4_crc32_cstr_seed_88608590(0, lbl_880F1084));
    if (v != -1)
        t->vt->activate(t, v);
}
