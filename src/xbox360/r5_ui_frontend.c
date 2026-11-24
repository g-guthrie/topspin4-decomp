typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

struct TS4R5ObjA8 {
    ts4_u8 reserved[0x226];
    ts4_u8 flag226;
};
struct TS4R5Obj120 {
    ts4_u8 reserved[0x39F];
    ts4_u8 flag39f;
};
struct TS4R5Obj11C {
    ts4_u8 reserved[0xE6];
    ts4_u8 flagE6;
};
struct TS4R5VObj {
    void **vtable;
};
struct TS4R5Screen {
    ts4_u8 r0[0x58];
    int mode58;
    ts4_u8 r5c[0x4C];
    struct TS4R5ObjA8 *objA8;
    ts4_u8 rac[0xC];
    struct TS4R5VObj *objB8;
    ts4_u8 rbc[0x60];
    struct TS4R5Obj11C *obj11C;
    struct TS4R5Obj120 *obj120;
    ts4_u8 r124;
    ts4_u8 flag125;
};

/* Per-frame update: latch the 'done' flag on a screen, pulsing a vcall(+8) while the 0x39F flag is raised. */
void ts4_r5_screen_latch_done_887CEDD0(struct TS4R5Screen *self)
{
    int mode;
    ts4_u8 flag;

    if (self->flag125 == 0) {
        mode = self->mode58;
        if (mode != 2 && mode != 1) {
            self->flag125 = 1;
            return;
        }
        flag = (mode == 2);
        if (self->objA8->flag226 != 0) {
            ts4_u8 a = flag;
            flag = (a != 0) || (mode == 1);
        }
        if (flag) {
            self->obj120->flag39f = 1;
            ((void (*)(void *))self->objB8->vtable[2])(self->objB8);
            self->obj120->flag39f = 0;
        }
        if (self->flag125 == 0) {
            mode = self->mode58;
            if (mode == 1 || mode == 2) {
                self->flag125 = self->obj11C->flagE6;
            }
        }
    }
}
