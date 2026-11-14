/* Swing_DLL.xex 0x882EE920-0x882EE9A4, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
struct writer;
struct ctx { void (*on_error)(struct writer *w); u32 pad[4]; u32 code; };
struct buf { char *ptr; int remain; u32 pad; int (*flush)(struct writer *w); };
struct writer { struct ctx *ctx; u32 pad[5]; struct buf *buf; };
void ts4_put_byte_882EE920(struct writer *self, int value)
{
    struct buf *b = self->buf;
    *b->ptr++ = (char)value;
    b->remain--;
    if (b->remain == 0) {
        if (b->flush(self) == 0) {
            self->ctx->code = 0x18;
            self->ctx->on_error(self);
        }
    }
}
