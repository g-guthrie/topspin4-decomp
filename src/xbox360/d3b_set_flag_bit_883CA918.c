/* Swing_DLL.xex 0x883CA918-0x883CA9B0, executable version 0.0.0.3. */
typedef struct Link { char pad[0x18]; void *handle; } Link;
typedef struct Obj { char pad[0x60]; unsigned flags; char pad2[0x48]; Link *link; } Obj;
int ts4_call_then_conditionally_forward_result_88317BD8(void *handle, unsigned char arg);

int ts4_set_flag_bit_883CA918(Obj *self, unsigned char on)
{
    if ((self->link ? self->link->handle : 0) != 0) {
        int r = ts4_call_then_conditionally_forward_result_88317BD8(self->link ? self->link->handle : 0, on);
        if (r != 0) return r;
    }
    self->flags &= ~0x4000u;
    if (on) self->flags |= 0x4000u;
    return 0;
}
