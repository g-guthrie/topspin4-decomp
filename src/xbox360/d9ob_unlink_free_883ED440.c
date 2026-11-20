/* Swing_DLL.xex 0x883ED440-0x883ED4AC, executable version 0.0.0.3. */
typedef struct Ts4Ob2L2 { struct Ts4Ob2L2 *next; struct Ts4Ob2L2 *prev; } Ts4Ob2L2;
typedef struct Ts4Ob2N2 { char pad0[4]; Ts4Ob2L2 link; int count; } Ts4Ob2N2;
void fn_88315F10(void *heap, void *p, const char *tag, int line);
extern struct { char pad[4]; void *heap; } *lbl_88B3302C;
extern char lbl_88039ADC[];

int ts4_unlink_free_883ED440(Ts4Ob2N2 *o)
{
    o->link.prev->next = o->link.next;
    o->link.next->prev = o->link.prev;
    o->link.prev = &o->link;
    o->link.next = &o->link;
    o->count = 0;
    fn_88315F10(lbl_88B3302C->heap, o, lbl_88039ADC, 0xdc);
    return 0;
}
