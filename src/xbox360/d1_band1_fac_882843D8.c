/* Swing_DLL.xex 0x882843D8-0x882852C8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *lbl_88D45B38;
extern void *fn_88613268(void *heap, u32 size, u32 a, u32 b, u32 c);
extern void *fn_88622D18(void *self);
extern void *ts4_call_seq_fn_8861B128_88622BF0(void *self);
extern void *fn_88617D88(void *self);
extern void *lbl_880F8310[];
extern void *ts4_call_seq_fn_8861B128_8827DA88(void *self);
extern void *fn_88622888(void *self);
extern void *fn_8862A190(void *self);
extern void *fn_88626840(void *self);
extern void *fn_886214A0(void *self);
extern void *fn_88626638(void *self);
extern void *fn_88621250(void *self);
extern void *ts4_call_seq_fn_886197F0_88621028(void *self);
extern void *ts4_call_seq_fn_886197F0_88620C10(void *self);
extern void *lbl_880F8950[];
extern void *lbl_880F8978[];
extern void *ts4_call_seq_fn_886197F0_88620480(void *self);
extern void *ts4_call_seq_fn_886197F0_88620190(void *self);
extern void *ts4_call_seq_fn_886197F0_8861FE98(void *self);
extern void *fn_8861F9B8(void *self);
extern void *fn_886197F0(void *self);
extern void *lbl_880F8748[];

void *ts4_create_object_88284C68(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 400, 4, 0, 2);
    if (p != 0) {
        return ts4_call_seq_fn_886197F0_88620C10(p);
    }
    return 0;
}

void *ts4_create_object_88284CC0(void)
{
    char *p = (char *)fn_88613268(lbl_88D45B38, 400, 4, 0, 0);
    if (p != 0) {
        return ts4_call_seq_fn_886197F0_88620C10(p);
    }
    return 0;
}

