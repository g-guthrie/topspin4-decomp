/* Swing_DLL.xex 0x883D3C10-0x883D3C60, executable version 0.0.0.3. */
typedef struct Ts4Ob2Ln { struct Ts4Ob2Ln *next; } Ts4Ob2Ln;
typedef struct Ts4Ob2Fv { char pad0[0x14]; float f14; } Ts4Ob2Fv;
typedef struct Ts4Ob2Fe { char pad0[0x14]; Ts4Ob2Fv *v; } Ts4Ob2Fe;
typedef struct Ts4Ob2Fo { char pad0[0x34]; Ts4Ob2Ln list; } Ts4Ob2Fo;

int ts4_count_less_883D3C10(void *unused, Ts4Ob2Fe *ref, Ts4Ob2Fo *o)
{
    Ts4Ob2Ln *e;
    Ts4Ob2Fe *p;
    int n = 0;
    float f;
    (void)unused;
    if (o->list.next == &o->list)
        return 0;
    f = ref->v->f14;
    for (e = o->list.next; e != &o->list; e = e->next) {
        p = e != 0 ? (Ts4Ob2Fe *)((char *)e - 4) : 0;
        if (p->v->f14 < f)
            n++;
    }
    return n;
}
