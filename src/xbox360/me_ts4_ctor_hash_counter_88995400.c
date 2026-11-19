/* Swing_DLL.xex 0x88995400: constructor; vtable lbl_880D2B14, hash 0xA0BDE62E at +8, count 1 at +0xc, clears +4/+0x10/+0x14/+0x20
 * and zeroes the 8 bytes at +0x18. agO: lookalike of 88889240 (pointer-local hash store); plain and LTCG. */
extern char lbl_880D2B14[];
void *ts4_memset(void *dst, int c, unsigned n);
typedef struct Obj { void *vtbl; int f4; unsigned hash; int count; int f10; int f14; char buf[8]; int f20; } Obj;

Obj *fn_88995400(Obj *self)
{
    self->f4 = 0;
    { unsigned *ph = &self->hash; *ph = 0xA0BDE62Eu; }
    self->vtbl = lbl_880D2B14;
    self->count = 1;
    self->f10 = 0;
    self->f14 = 0;
    self->f20 = 0;
    ts4_memset(self->buf, 0, 8);
    return self;
}
