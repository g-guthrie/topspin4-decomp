/* Swing_DLL.xex 0x883DB6C8-0x883DB754, executable version 0.0.0.3. */
typedef struct Ln { struct Ln *next; } Ln;
typedef struct A { char pad0[0x34]; Ln list; } A;
extern void *lbl_88CAC988;
int fn_883D38C8(void *g, void *e, void *out, unsigned int fl, int z);
int fn_883DA438(void *o, void *e, void *out, unsigned int fl);

int ts4_open_nth_883DB6C8(A *o, int n, unsigned int fl, unsigned int *out)
{
    Ln *head;
    Ln *e;
    void *p = 0;
    int i;
    if (out != 0) {
        *out = 0;
        i = n;
        head = &o->list;
        if (n < 0 || head->next == head)
            goto nul;
        e = head->next;
        for (; i > 0; i--) {
            e = e->next;
            if (e == head)
                goto nul;
        }
        if (e != 0) {
            p = (char *)e - 8;
        } else {
nul:
            p = 0;
        }
    }
    if (p != 0) {
        if (fl & 4)
            return fn_883D38C8(lbl_88CAC988, p, out, fl, 0);
        return fn_883DA438(o, p, out, fl);
    }
    return 0x25;
}
