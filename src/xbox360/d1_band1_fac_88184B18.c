/* Swing_DLL.xex 0x88184B18-0x881891E8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *lbl_88D45B38;
extern void *fn_88613268(void *heap, u32 size, u32 a, u32 b, u32 c);
extern void *fn_888C9588(void *self);
extern void *fn_888DDF98(void *self);
extern void *fn_888DDE20(void *self);
extern void *fn_888E1EE0(void *self);
extern void *fn_888D03A0(void *self);
extern void *fn_888C80A0(void *self);
extern void *fn_88617D88(void *self);
extern void *lbl_880DB954[];
extern void *ts4_call_seq_fn_88617D88_888C7F30(void *self);
extern void *lbl_880DB97C[];
extern void *ts4_call_seq_fn_88617D88_888C7980(void *self);
extern void *fn_888DF9C0(void *self);
extern void *lbl_880DB834[];
extern void *fn_888B92C0(void *self);
extern void *lbl_880DC524[];
extern void *fn_888B1D08(void *self);
extern void *lbl_880DC680[];
extern void *fn_888B9410(void *self);
extern void *fn_888AF5C0(void *self);
extern void *fn_888B1230(void *self);
extern void *fn_888B0FF8(void *self);
extern void *fn_888B0CA8(void *self);

void *ts4_create_object_88188DE0(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 60, 4, 0, 2);
    if (p != 0) {
        fn_888B1D08(p);
        *(void **)(p + 0) = lbl_880DC680;
        return p;
    }
    return 0;
}

void *ts4_create_object_88188E58(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 60, 4, 0, 0);
    if (p != 0) {
        fn_888B1D08(p);
        *(void **)(p + 0) = lbl_880DC680;
        return p;
    }
    return 0;
}

void *ts4_create_object_88188F80(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 128, 4, 0, 2);
    if (p != 0) {
        return fn_888AF5C0(p);
    }
    return 0;
}

void *ts4_create_object_88188FD8(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 128, 4, 0, 0);
    if (p != 0) {
        return fn_888AF5C0(p);
    }
    return 0;
}

void *ts4_create_object_88189030(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 224, 16, 0, 2);
    if (p != 0) {
        return fn_888B1230(p);
    }
    return 0;
}

void *ts4_create_object_88189088(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 224, 16, 0, 0);
    if (p != 0) {
        return fn_888B1230(p);
    }
    return 0;
}

