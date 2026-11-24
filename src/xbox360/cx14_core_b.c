/* CW14 part b: LTCG-only game flow functions (0x8883C000-0x88850000). Built with /Oc on the LTCG route. */
typedef unsigned int u32;

struct Cx14Game;
extern struct Cx14Game *lbl_88D459E8;
extern char lbl_880E16D4[], lbl_880E165C[];
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *);
typedef struct Cx14Obj { char *vt; char pad[0x18]; char *vt2; } Cx14Obj;

/* 0x8883CD50: set two vtables, clear the global game pointer, chain to the base release */
void ts4_obj_reset_8883CD50(Cx14Obj *self)
{
    struct Cx14Game *zero = 0;
    char *a = lbl_880E16D4;
    char *b = lbl_880E165C;
    self->vt = a;
    self->vt2 = b;
    lbl_88D459E8 = zero;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
