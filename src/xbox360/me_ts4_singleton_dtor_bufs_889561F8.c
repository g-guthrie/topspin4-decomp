/* Swing_DLL.xex 0x889561F8: singleton destructor freeing three buffer members */
/* Matched by agL with fn_check, plain route only (LTCG merges the file-static instance into a pool symbol). */
extern char lbl_880D4FD8[];
extern void ts4_if_call_seq_u32_off4_88161CF8(void *p);
extern void ts4_destroy_owned_object(void *obj);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
/* File-static singleton instance pointer of the original translation unit. */
static void *lbl_88D4589C;

typedef struct Obj { void *vtbl; char pad[0x24]; void *buf28; char pad2[8]; void *buf34; char pad3[0xc]; void *buf44; } Obj;

/* Singleton destructor: vtable, clear the instance pointer, finalize the member at +0x44, free three buffers,
   then the base destructor. */
void fn_889561F8(Obj *self)
{
    self->vtbl = lbl_880D4FD8;
    lbl_88D4589C = 0;
    ts4_if_call_seq_u32_off4_88161CF8(&self->buf44);
    ts4_destroy_owned_object(self->buf44);
    ts4_destroy_owned_object(self->buf34);
    ts4_destroy_owned_object(self->buf28);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
