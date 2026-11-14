/* Swing_DLL.xex 0x883EDD58-0x883EDDCC, executable version 0.0.0.3. */
typedef struct Ts4Ob2Ln { struct Ts4Ob2Ln *next; } Ts4Ob2Ln;
typedef int (*Ts4Ob2Vf2)(void *, void *);
typedef struct Ts4Ob2Hd { char pad0[0x18]; Ts4Ob2Ln list; } Ts4Ob2Hd;

int ts4_each_vcall_883EDD58(Ts4Ob2Hd *o)
{
    Ts4Ob2Ln *e;
    char *p;
    char tmp[8];
    int r;
    for (e = o->list.next; e != &o->list; e = e->next) {
        p = e != 0 ? (char *)e - 4 : (char *)0;
        r = ((Ts4Ob2Vf2)(*(void ***)p)[0x38 / 4])(p, tmp);
        if (r != 0)
            return r;
    }
    return 0;
}
