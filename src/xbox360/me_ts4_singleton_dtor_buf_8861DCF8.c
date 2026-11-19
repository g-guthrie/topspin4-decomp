/* Swing_DLL.xex 0x8861DCF8: singleton destructor with a finalized buffer member at +0x1c */
/* Matched by agL with fn_check, plain route only (LTCG merges the file-static instance into a pool symbol). */
extern char lbl_880F8D00[];
extern void ts4_object_finalize(void *p);
extern void ts4_destroy_owned_object(void *obj);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
/* File-static singleton instance pointer of the original translation unit. */
static void *lbl_88D45B4C;

typedef struct Obj { void *vtbl; char pad[0x18]; void *buf; } Obj;

/* Singleton destructor: vtable, clear the instance pointer, finalize and free the buffer member at +0x1c,
   then the base destructor. */
void fn_8861DCF8(Obj *self)
{
    self->vtbl = lbl_880F8D00;
    lbl_88D45B4C = 0;
    ts4_object_finalize(&self->buf);
    if (self->buf)
        ts4_destroy_owned_object(self->buf);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
