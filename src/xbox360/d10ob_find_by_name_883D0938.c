/* Swing_DLL.xex 0x883D0938-0x883D09CC, executable version 0.0.0.3. */
typedef struct Ln { struct Ln *next; } Ln;
typedef struct En { char pad0[0x1c]; void *name; } En;
int fn_88329868(void *a, void *b);

int ts4_find_by_name_883D0938(char *o, void *name, void **out)
{
    Ln *head;
    Ln *e;
    En *p;
    if (name == 0 || out == 0)
        return 0x25;
    head = (Ln *)(o + 0x10000 - 0x7fb8);
    *out = 0;
    for (e = head->next; e != head; e = e->next) {
        p = e != 0 ? (En *)((char *)e - 8) : 0;
        if (fn_88329868(p->name, name) == 0) {
            *out = e != 0 ? (char *)e - 8 : 0;
            return 0;
        }
    }
    return 0x25;
}
