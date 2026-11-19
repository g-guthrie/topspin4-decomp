/* Swing_DLL.xex 0x887CC0B0: destructor; frees the buffer at +0x364, clears +0x224, drops itself from lbl_88D45B1C->+0x224
 * (restoring +0x220) and runs the base destructor. agO: void **pb local keeps the load after the vtable store; plain and LTCG. */
extern char lbl_880EA2B0[];
extern char lbl_880F7940[];
typedef struct Ts4Globals { char pad[0x220]; void *prev; void *current; } Ts4Globals;
extern Ts4Globals *lbl_88D45B1C;
extern void ts4_destroy_owned_object(void *obj);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
typedef struct Obj { void *vtbl; char pad[0x220]; int f224; char pad2[0x13c]; void *buf364; } Obj;

void fn_887CC0B0(Obj *self)
{
    Ts4Globals *g;
    self->vtbl = lbl_880EA2B0;
    { void **pb = &self->buf364; ts4_destroy_owned_object(*pb); }
    g = lbl_88D45B1C;
    self->f224 = 0;
    self->vtbl = lbl_880F7940;
    if ((void *)self == g->current)
        g->current = g->prev;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
