/* Family FAM2: one-shot type registrations (Swing_DLL.xex 0x88638D10, 0x886529C8, 0x88771378, 0x887F48B8,
   0x88890140).  Each interns the type NAME with fn_88608590, scans the global registry vector
   lbl_88D45B20 for an entry already carrying that id and, if none is found, allocates an 8-byte
   entry {VTBL, id} from the shared heap lbl_88D45B38 and appends it with fn_881898E8. */
typedef unsigned int u32;
typedef struct Ts4TypeEntry { void *vt; u32 id; } Ts4TypeEntry;
typedef struct Ts4TypeRegistry { Ts4TypeEntry **first, **last; } Ts4TypeRegistry;
extern Ts4TypeRegistry *lbl_88D45B20;
extern void *lbl_88D45B38;
extern u32 fn_88608590(u32 zero, const char *name);
extern void *fn_88613268(void *heap, int size, int align, int flags, int tag);
extern void fn_881898E8(Ts4TypeRegistry *list, Ts4TypeEntry **entry);
extern char lbl_880F6340[], lbl_880F539C[], lbl_880EFB50[], lbl_880E44A8[], lbl_880DD880[];
extern char lbl_880F6474[], lbl_880F59B8[], lbl_880EFF08[], lbl_880E49D0[], lbl_880DEF50[];

static __inline Ts4TypeEntry *type_entry_init(Ts4TypeEntry *e, void *vt, u32 id)
{
    e->id = id;
    e->vt = vt;
    return e;
}

#define TS4_TYPE_REGISTER(A, NAME, VTBL) \
void ts4_type_register_##A(void); \
void ts4_type_register_##A(void) \
{ \
    u32 id = fn_88608590(0, NAME); \
    Ts4TypeRegistry *reg = lbl_88D45B20; \
    Ts4TypeEntry **end = reg->last; \
    Ts4TypeEntry **it; \
    Ts4TypeEntry *e; \
    void *mem; \
    for (it = reg->first; it != end; ++it) \
        if ((*it)->id == id) \
            return; \
    mem = fn_88613268(lbl_88D45B38, 8, 4, 0, 2); \
    { \
        Ts4TypeEntry *r = mem ? type_entry_init((Ts4TypeEntry *)mem, VTBL, id) : 0; \
        e = r; \
    } \
    fn_881898E8(reg, &e); \
}

/* Swing_DLL.xex addresses */
TS4_TYPE_REGISTER(88638D10, lbl_880F6340, lbl_880F6474)
TS4_TYPE_REGISTER(886529C8, lbl_880F539C, lbl_880F59B8)
TS4_TYPE_REGISTER(88771378, lbl_880EFB50, lbl_880EFF08)
TS4_TYPE_REGISTER(887F48B8, lbl_880E44A8, lbl_880E49D0)
TS4_TYPE_REGISTER(88890140, lbl_880DD880, lbl_880DEF50)
