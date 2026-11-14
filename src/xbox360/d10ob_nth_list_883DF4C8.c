/* Swing_DLL.xex 0x883DF4C8-0x883DF540, executable version 0.0.0.3. */
typedef struct Ln { struct Ln *next; } Ln;
typedef struct A { char pad0[0x48]; char *l; } A;

int ts4_nth_883DF4C8(A *o, int n, void **out)
{
    Ln *head;
    Ln *e;
    char *p;
    int i;
    if (out == 0 || o->l == 0)
        return 0x25;
    i = n;
    head = (Ln *)(o->l + 4);
    if (n < 0 || head->next == head)
        goto nul;
    e = head->next;
    for (; i > 0; i--) {
        e = e->next;
        if (e == head)
            goto nul;
    }
    if (e != 0) {
        p = (char *)e - 4;
    } else {
nul:
        p = 0;
    }
    *out = p;
    return p == 0 ? 0x5b : 0;
}
