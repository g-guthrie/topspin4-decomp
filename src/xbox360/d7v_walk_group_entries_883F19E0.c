/* Swing_DLL.xex 0x883F19E0-0x883F1A68 and 0x883F1C48-0x883F1CD8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4X5Link { struct Ts4X5Link *next; } Ts4X5Link;
typedef struct Ts4X5Group { char pad0[0x30]; u32 padlink; Ts4X5Link inner; } Ts4X5Group;
typedef struct Ts4X5Cfg { char pad[0x40]; u32 f40; char pad44[0xC0]; float f104; } Ts4X5Cfg;
typedef struct Ts4X5Obj { char pad0[4]; Ts4X5Cfg *cfg; char pad8[4]; Ts4X5Link groups; } Ts4X5Obj;
int fn_883E2390(void *entry, u32 arg);

int ts4_walk_group_entries_883F19E0(Ts4X5Obj *o)
{
    Ts4X5Link *g;
    Ts4X5Link *e;
    Ts4X5Group *grp;
    int r;
    for (g = o->groups.next; g != &o->groups; g = g->next) {
        grp = g != 0 ? (Ts4X5Group *)((char *)g - 4) : 0;
        e = grp->inner.next;
        for (; e != &grp->inner; e = e->next) {
            r = fn_883E2390(e != 0 ? (char *)e - 4 : (char *)0, o->cfg->f40);
            if (r != 0 && r != 0x24)
                return r;
        }
    }
    return 0;
}
