/* Swing_DLL.xex 0x888885F8: destructor; frees the buffer at +0x24, drops itself from lbl_88D45B1C->+0x224
 * (restoring +0x220) and runs the base destructor. agO: lookalike of 887CC0B0. */
extern char lbl_880DF380[];
extern char lbl_880F7940[];
typedef struct Ts4Globals { char pad[0x220]; void *prev; void *current; } Ts4Globals;
extern Ts4Globals *lbl_88D45B1C;
extern void ts4_destroy_owned_object(void *obj);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
typedef struct Obj { void *vtbl; char pad[0x20]; void *buf24; } Obj;

void fn_888885F8(Obj *self)
{
    Ts4Globals *g;
    self->vtbl = lbl_880DF380;
    { void **pb = &self->buf24; ts4_destroy_owned_object(*pb); }
    g = lbl_88D45B1C;
    self->vtbl = lbl_880F7940;
    if ((void *)self == g->current)
        g->current = g->prev;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
