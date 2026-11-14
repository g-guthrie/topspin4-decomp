/* Swing_DLL.xex 0x88189418-0x881A78E8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *lbl_88D45B38;
extern void *fn_88613268(void *heap, u32 size, u32 a, u32 b, u32 c);
extern void *fn_888B92C0(void *self);
extern void *fn_888B9170(void *self);
extern void *fn_888B9020(void *self);
extern void *fn_889C1690(void *self);
extern void *fn_8841B550(void *self);
extern void *lbl_880DCE70[];
extern void *fn_88617D88(void *self);
extern void *lbl_880DCE14[];
extern void *fn_88197E10(void *self);
extern void *lbl_880DD6D8[];
extern void *lbl_880DD88C[];
extern void *fn_8888D278(void *self);
extern void *ts4_call_seq_fn_88617D88_88887AD8(void *self);
extern void *fn_88889240(void *self);
extern void *fn_88888C80(void *self);
extern void *fn_88887FA0(void *self);
extern void *lbl_880DF40C[];
extern void *fn_88886608(void *self);
extern void *fn_88636DC8(void *self);
extern void *lbl_880DF490[];
extern void *lbl_880DF940[];
extern void *fn_8887EE60(void *self);
extern void *fn_8887CAD0(void *self);
extern void *fn_8887DBF8(void *self);
extern void *fn_88878F30(void *self);

void *ts4_create_object_88189470(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 336, 4, 0, 2);
    if (p != 0) {
        return fn_888B9170(p);
    }
    return 0;
}

void *ts4_create_object_881894C8(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 336, 4, 0, 0);
    if (p != 0) {
        return fn_888B9170(p);
    }
    return 0;
}

void *ts4_create_object_88189520(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 200, 4, 0, 2);
    if (p != 0) {
        return fn_888B9020(p);
    }
    return 0;
}

void *ts4_create_object_88189578(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 200, 4, 0, 0);
    if (p != 0) {
        return fn_888B9020(p);
    }
    return 0;
}

void *ts4_create_object_88189AB0(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 68, 4, 0, 2);
    if (p != 0) {
        return fn_889C1690(p);
    }
    return 0;
}

void *ts4_create_object_88189B08(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 68, 4, 0, 0);
    if (p != 0) {
        return fn_889C1690(p);
    }
    return 0;
}

void *ts4_create_object_88189F18(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 2584, 4, 0, 2);
    if (p != 0) {
        fn_8841B550(p);
        *(void **)(p + 0) = lbl_880DCE70;
        return p;
    }
    return 0;
}

void *ts4_create_object_88189F90(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 40, 4, 0, 2);
    if (p != 0) {
        fn_88617D88(p);
        *(int *)(p + 28) = 0;
        *(void **)(p + 0) = lbl_880DCE14;
        *(int *)(p + 32) = 0;
        return p;
    }
    return 0;
}

void *ts4_create_object_8818A018(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 40, 4, 0, 0);
    if (p != 0) {
        fn_88617D88(p);
        *(int *)(p + 28) = 0;
        *(void **)(p + 0) = lbl_880DCE14;
        *(int *)(p + 32) = 0;
        return p;
    }
    return 0;
}

void *ts4_create_object_8818A190(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 132, 4, 0, 2);
    if (p != 0) {
        fn_88197E10(p);
        *(int *)(p + 124) = 0;
        *(void **)(p + 0) = lbl_880DD6D8;
        return p;
    }
    return 0;
}

