/* Swing_DLL.xex 0x883E8C08-0x883E8C8C, executable version 0.0.0.3. */
typedef struct Mgr { int pad; void *heap; } Mgr;
typedef struct Obj { char pad[0x10]; void *buf; void *cnt; void *aux; char tail[4]; } Obj;
extern Mgr *lbl_88B3302C;
extern char lbl_88039A20[];
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_call_seq_fn_883E4E70_883E5060(void *p);
void ts4_if_call_seq_u32_off4_883E6250(void *p);

int ts4_release_buffer_883E8C08(Obj *self)
{
    if (self->buf != 0) fn_88315F10(lbl_88B3302C->heap, self->buf, lbl_88039A20, 0x44f);
    if (self->aux != 0) {
        int r = ts4_call_seq_fn_883E4E70_883E5060(self->aux);
        if (r != 0) return r;
    }
    self->buf = 0;
    self->aux = 0;
    self->cnt = 0;
    ts4_if_call_seq_u32_off4_883E6250(self->tail);
    return 0;
}
