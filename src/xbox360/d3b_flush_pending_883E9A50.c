/* Swing_DLL.xex 0x883E9A50-0x883E9AD4, executable version 0.0.0.3. */
typedef struct Src { char pad[0x18]; unsigned flags; } Src;
typedef struct Obj { char pad[8]; Src *src; void *dst; int arg; unsigned char pending; } Obj;
int fn_883DD7A0(Src *s, void *d, int arg);

int ts4_flush_pending_883E9A50(Obj *self)
{
    if (!self->pending) return 0;
    if (self->src == 0 || self->dst == 0) return 0x21;
    if (self->src->flags & 0x300) {
        int r = fn_883DD7A0(self->src, self->dst, self->arg);
        if (r != 0) return r;
    }
    self->pending = 0;
    return 0;
}
