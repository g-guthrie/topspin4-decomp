/* flags: /O1 */
/* Swing_DLL.xex 0x882A9340-0x883E72C8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *lbl_88000A3C[];
extern void ts4_tsu_cleanup_end(void *self);
extern void fn_882B4520(void *self);
extern void fn_882B5C98(void *self);
extern void fn_882C0B38(void *self);
extern void *lbl_88039180[];
extern void *lbl_88039378[];
extern void *lbl_880394A8[];
extern void *lbl_88039634[];
extern void *lbl_880395D8[];
extern void *lbl_8803977C[];
extern void *lbl_8803978C[];
extern void *lbl_880397A8[];
extern void *lbl_88039800[];
extern void *lbl_88039824[];

void *ts4_deleting_destructor_882A9340(void *self, u32 flags)
{
    *(void **)self = lbl_88000A3C;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_882C0A98(void *self, u32 flags)
{
    fn_882B4520(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_882C0AE8(void *self, u32 flags)
{
    fn_882B5C98(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_882C16D8(void *self, u32 flags)
{
    fn_882C0B38(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883D0580(void *self, u32 flags)
{
    *(void **)self = lbl_88039180;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883D7E88(void *self, u32 flags)
{
    *(void **)self = lbl_88039378;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883DEDD0(void *self, u32 flags)
{
    *(void **)self = lbl_880394A8;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E3810(void *self, u32 flags)
{
    *(void **)self = lbl_88039634;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E49E0(void *self, u32 flags)
{
    *(void **)self = lbl_880395D8;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E7198(void *self, u32 flags)
{
    *(void **)self = lbl_8803977C;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E71E0(void *self, u32 flags)
{
    *(void **)self = lbl_8803978C;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E7228(void *self, u32 flags)
{
    *(void **)self = lbl_880397A8;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E7280(void *self, u32 flags)
{
    *(void **)self = lbl_88039800;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E72C8(void *self, u32 flags)
{
    *(void **)self = lbl_88039824;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}
