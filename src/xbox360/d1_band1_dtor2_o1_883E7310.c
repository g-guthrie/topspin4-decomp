/* flags: /O1 */
/* Swing_DLL.xex 0x883E7310-0x883FFB48, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *lbl_88039850[];
extern void ts4_tsu_cleanup_end(void *self);
extern void *lbl_88039864[];
extern void *lbl_88039874[];
extern void *lbl_8803988C[];
extern void *lbl_88039904[];
extern void *lbl_880397D4[];
extern void fn_883E7580(void *self);
extern void *lbl_88039798[];
extern void *lbl_88039A98[];
extern void *lbl_88039B9C[];
extern void *lbl_88039FC8[];
extern void *lbl_8803A12C[];
extern void *lbl_8803978C[];

void *ts4_deleting_destructor_883E7310(void *self, u32 flags)
{
    *(void **)self = lbl_88039850;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E7368(void *self, u32 flags)
{
    *(void **)self = lbl_88039864;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E73B0(void *self, u32 flags)
{
    *(void **)self = lbl_88039874;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E73F8(void *self, u32 flags)
{
    *(void **)self = lbl_8803988C;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E7608(void *self, u32 flags)
{
    *(void **)self = lbl_88039904;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883E7658(void *self, u32 flags)
{
    *(void **)self = lbl_880397D4;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883EA8E8(void *self, u32 flags)
{
    fn_883E7580(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883EA938(void *self, u32 flags)
{
    *(void **)self = lbl_88039798;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883EA980(void *self, u32 flags)
{
    *(void **)self = lbl_88039904;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883ED078(void *self, u32 flags)
{
    *(void **)self = lbl_88039A98;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883EE9A0(void *self, u32 flags)
{
    *(void **)self = lbl_88039B9C;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883FA058(void *self, u32 flags)
{
    *(void **)self = lbl_88039FC8;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883FD3F0(void *self, u32 flags)
{
    *(void **)self = lbl_8803A12C;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

void *ts4_deleting_destructor_883FFB48(void *self, u32 flags)
{
    *(void **)self = lbl_8803978C;
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}
