/* Swing_DLL.xex 0x883F1E88-0x883F1F10, 0x883F1FA0-0x883F2028, executable version 0.0.0.3. */
typedef struct Ln { struct Ln *next; } Ln;
typedef struct Ent { char pad0[0x18]; unsigned int type; int v; } Ent;
typedef struct O { char pad0[0x24]; Ln list; } O;

int ts4_get_param_883F1E88(O *o, int idx, void *out)
{
    Ln *head = &o->list;
    Ln *e;
    Ent *p;
    int n = idx - 0x30;
    if (n < 0 || head->next == head)
        goto nul;
    e = head->next;
    for (; n > 0; n--) {
        e = e->next;
        if (e == head)
            goto nul;
    }
    if (e != 0) {
        p = (Ent *)((char *)e - 4);
    } else {
nul:
        p = 0;
    }
    if (p != 0) {
        switch (p->type) {
        case 0:
        case 2:
            *(int *)out = p->v;
            break;
        case 1:
            *(float *)out = *(float *)&p->v;
            break;
        }
        return 0;
    }
    return 0x25;
}

int ts4_set_param_883F1FA0(O *o, int idx, void *out)
{
    Ln *head = &o->list;
    Ln *e;
    Ent *p;
    int n = idx - 0x30;
    if (n < 0 || head->next == head)
        goto nul;
    e = head->next;
    for (; n > 0; n--) {
        e = e->next;
        if (e == head)
            goto nul;
    }
    if (e != 0) {
        p = (Ent *)((char *)e - 4);
    } else {
nul:
        p = 0;
    }
    if (p != 0) {
        switch (p->type) {
        case 0:
        case 2:
            p->v = *(int *)out;
            break;
        case 1:
            *(float *)&p->v = *(float *)out;
            break;
        }
        return 0;
    }
    return 0x25;
}
