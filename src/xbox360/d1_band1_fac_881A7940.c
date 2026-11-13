/* Swing_DLL.xex 0x881A7940-0x881B3160, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *lbl_88D45B38;
extern void *fn_88613268(void *heap, u32 size, u32 a, u32 b, u32 c);
extern void *fn_88878F30(void *self);
extern void *fn_88617D88(void *self);
extern void *lbl_880E06B0[];
extern void *fn_88866658(void *self);
extern void *fn_888664F0(void *self);
extern void *ts4_call_seq_fn_88617D88_88866480(void *self);
extern void *fn_888663D0(void *self);
extern void *fn_888662C8(void *self);
extern void *fn_888682F0(void *self);
extern void *fn_88622888(void *self);
extern void *ts4_call_seq_fn_88617D88_88855F10(void *self);
extern void *fn_8883D798(void *self);
extern void *fn_888417A8(void *self);
extern void *ts4_call_seq_fn_88617D88_88850648(void *self);
extern void *lbl_880E1724[];
extern void *lbl_880E174C[];
extern void *lbl_880E3748[];
extern void *fn_88803D00(void *self);
extern void *lbl_880E3828[];
extern void *lbl_880E3838[];
extern void *fn_888041C0(void *self);
extern void *ts4_call_seq_fn_88804B18_88804B88(void *self);

void *ts4_create_object_881ABF28(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 200, 4, 0, 2);
    if (p != 0) {
        return fn_88866658(p);
    }
    return 0;
}

void *ts4_create_object_881ABF80(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 200, 4, 0, 0);
    if (p != 0) {
        return fn_88866658(p);
    }
    return 0;
}

void *ts4_create_object_881ABFD8(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 212, 4, 0, 2);
    if (p != 0) {
        return fn_888664F0(p);
    }
    return 0;
}

void *ts4_create_object_881AC030(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 212, 4, 0, 0);
    if (p != 0) {
        return fn_888664F0(p);
    }
    return 0;
}

void *ts4_create_object_881AC1E8(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 48, 4, 0, 2);
    if (p != 0) {
        return fn_888662C8(p);
    }
    return 0;
}

void *ts4_create_object_881AC240(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 48, 4, 0, 0);
    if (p != 0) {
        return fn_888662C8(p);
    }
    return 0;
}

