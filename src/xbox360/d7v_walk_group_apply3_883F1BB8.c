/* Swing_DLL.xex 0x883F1BB8-0x883F1C48, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4X8Link { struct Ts4X8Link *next; } Ts4X8Link;
typedef struct Ts4X8Group { char pad0[0x30]; u32 padlink; Ts4X8Link inner; } Ts4X8Group;
typedef struct Ts4X8Cfg { char pad0[0xF8]; float f0; float f1; float f2; } Ts4X8Cfg;
typedef struct Ts4X8Obj { char pad0[4]; Ts4X8Cfg *cfg; char pad8[4]; Ts4X8Link groups; } Ts4X8Obj;
int fn_883E24D8(void *entry, float a, float b, float c);

int ts4_walk_group_apply3_883F1BB8(Ts4X8Obj *o)
{
    Ts4X8Link *g;
    Ts4X8Link *e;
    Ts4X8Group *grp;
    int r;
    for (g = o->groups.next; g != &o->groups; g = g->next) {
        grp = g != 0 ? (Ts4X8Group *)((char *)g - 4) : 0;
        e = grp->inner.next;
        for (; e != &grp->inner; e = e->next) {
            r = fn_883E24D8(e != 0 ? (char *)e - 4 : (char *)0, o->cfg->f0, o->cfg->f1, o->cfg->f2);
            if (r != 0 && r != 0x24)
                return r;
        }
    }
    return 0;
}
