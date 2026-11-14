/* Swing_DLL.xex 0x883EDB00-0x883EDB94, executable version 0.0.0.3. */
typedef struct Ln { struct Ln *next; } Ln;
typedef struct W { void **vt; char pad0[0x14]; Ln list; } W;
int ts4_if_get_fn_883CB130_883CB300(unsigned int v, int k);

int ts4_visit_883EDB00(W *o, unsigned char flag)
{
    Ln *head = &o->list;
    Ln *e;
    Ln *nx;
    unsigned int tmp;
    int r;
    for (e = head->next; e != head; e = nx) {
        nx = e->next;
        if (flag != 0) {
            W *p = (W *)((char *)e - 4);
            if (((int (*)(void *, void *))p->vt[2])(p, &tmp) == 0)
                ts4_if_get_fn_883CB130_883CB300(tmp, 1);
        }
        r = ((int (*)(void *, void *))o->vt[2])(o, (char *)e - 4);
        if (r != 0)
            return r;
    }
    return 0;
}
