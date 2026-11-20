/* Swing_DLL.xex 0x883F7090-0x883F7104, executable version 0.0.0.3. */
typedef struct Ts4Ob2Ln { struct Ts4Ob2Ln *next; } Ts4Ob2Ln;
typedef struct Ts4Ob2It { char pad0[0x34]; int f34; } Ts4Ob2It;
typedef struct Ts4Ob2Gr { char pad0[0x34]; int f34; char pad38[0x40]; Ts4Ob2Ln list; } Ts4Ob2Gr;
typedef struct Ts4Ob2Ow { char pad0[0x10]; Ts4Ob2Gr *g; } Ts4Ob2Ow;

int ts4_count_set_883F7090(Ts4Ob2Ow *o, int *out)
{
    Ts4Ob2Gr *g;
    Ts4Ob2Ln *e;
    Ts4Ob2It *p;
    int n;
    if (out == 0)
        return 0x25;
    *out = 0;
    g = o->g;
    if (g != 0) {
        n = g->f34 != 0;
        for (e = g->list.next; e != &g->list; e = e->next) {
            p = e != 0 ? (Ts4Ob2It *)((char *)e - 4) : 0;
            n += p->f34 != 0;
        }
        *out = n;
    }
    return 0;
}
