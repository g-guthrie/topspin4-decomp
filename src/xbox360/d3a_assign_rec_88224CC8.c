/* Swing_DLL.xex 0x88224CC8-0x88224D4C, executable version 0.0.0.3. */
typedef unsigned int u32;
struct rec { u32 w[7]; u32 sub[7]; u32 tail; };
extern void fn_88255F90(void *dst, void *src);
struct rec *ts4_assign_rec_88224CC8(struct rec *self, struct rec *other)
{
    self->w[0] = other->w[0];
    self->w[1] = other->w[1];
    self->w[2] = other->w[2];
    self->w[3] = other->w[3];
    self->w[4] = other->w[4];
    self->w[5] = other->w[5];
    self->w[6] = other->w[6];
    fn_88255F90(self->sub, other->sub);
    self->tail = other->tail;
    return self;
}
