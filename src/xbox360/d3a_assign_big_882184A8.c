/* Swing_DLL.xex 0x882184A8-0x8821852C, executable version 0.0.0.3. */
typedef unsigned char u8;
struct big { u8 base[0xc]; u8 a[100]; u8 b[512]; };
extern void fn_881BD170(struct big *self, struct big *other);
struct big *ts4_assign_big_882184A8(struct big *self, struct big *other)
{
    int i;
    fn_881BD170(self, other);
    for (i = 0; i < 100; i++) {
        self->a[i] = other->a[i];
    }
    for (i = 0; i < 512; i++) {
        self->b[i] = other->b[i];
    }
    return self;
}
