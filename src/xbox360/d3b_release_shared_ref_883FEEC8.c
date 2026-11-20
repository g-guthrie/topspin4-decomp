/* Swing_DLL.xex 0x883FEEC8-0x883FEF4C, executable version 0.0.0.3. */
typedef struct Shared { char pad[0x18]; int refs; } Shared;
typedef struct Owner { char pad[0x14]; Shared *shared; unsigned flag; void *handle; } Owner;
int ts4_if_addr_lbl_8803A21C_883FEAB0(Shared *s);
void ts4_if_get_fn_8832BFC0_88317EC0(void *h);

int ts4_release_shared_ref_883FEEC8(Owner *self)
{
    if (self->shared != 0) {
        self->shared->refs--;
        if (self->shared->refs == 0) {
            int r = ts4_if_addr_lbl_8803A21C_883FEAB0(self->shared);
            if (r != 0) return r;
        }
    }
    if (self->flag == 0 && self->handle != 0) ts4_if_get_fn_8832BFC0_88317EC0(self->handle);
    self->handle = 0;
    return 0;
}
