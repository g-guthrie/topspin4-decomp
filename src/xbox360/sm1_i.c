/* SM1 batch i: sized reads through a shared reader (default /O2). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/* Each function asks the reader for 1 or 2 bytes into a local buffer and stores the value, zero-extended, through an optional output pointer. */
extern int fn_883194F0(void *, void *, int, int, void *);
#define READ_SIZED(NAME, SIZE, LOAD_T, STORE_T) \
    void NAME(void *t, STORE_T *out) { \
        u32 buf; \
        u32 aux; \
        fn_883194F0(t, &buf, SIZE, 1, &aux); \
        if (out) *out = (STORE_T)*(LOAD_T *)&buf; \
    }

/* Swing_DLL.xex 0x883199C0 */
READ_SIZED(ts4_read_u8_to_u8_883199C0, 1, u8, u8)
/* 0x88319A10 */
READ_SIZED(ts4_read_u8_to_u16_88319A10, 1, u8, u16)
/* 0x88319A60 */
READ_SIZED(ts4_read_u8_to_u32_88319A60, 1, u8, u32)
/* 0x88319B00 */
READ_SIZED(ts4_read_u16_to_u16_88319B00, 2, u16, u16)
/* 0x88319B50 */
READ_SIZED(ts4_read_u16_to_u32_88319B50, 2, u16, u32)
/* 0x88319AB0: sign-extended byte */
READ_SIZED(ts4_read_s8_to_s32_88319AB0, 1, signed char, int)
/* 0x88319BA0: sign-extended halfword */
READ_SIZED(ts4_read_s16_to_s32_88319BA0, 2, short, int)

/* 0x883A38C0: float member of the indexed child, reported through an optional pointer; 0x25 on a bad index or null output */
int ts4_get_child_float_adj1c_883A38C0(char *t, int idx, float *out) { char *p = t ? t - 0x1c : 0; if (idx >= 0 && idx < *(int *)(p + 0x31c) && out != 0) { *out = *(float *)(*(char **)(p + (idx + 0xc8) * 4) + 0x270); return 0; } return 0x25; }
