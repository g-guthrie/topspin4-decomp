/* SM1: reset a buffer owned by the object whose secondary base is `t` (object starts 0x1c before). */
extern void *ts4_memset(void *, int, unsigned);
#define CLEAR_BUFFER(NAME, ADJ, OBUF, OLEN, OSIZE) \
    int NAME(char *t) { \
        char *p = t ? t - ADJ : 0; \
        void *buf = *(void **)(p + OBUF); \
        *(int *)(p + OLEN) = 0; \
        if (buf) ts4_memset(buf, 0, *(unsigned *)(p + OSIZE)); \
        return 0; \
    }

/* Swing_DLL.xex 0x8833EB38 */
CLEAR_BUFFER(ts4_clear_owned_buffer_adj1c_8833EB38, 0x1c, 0x158, 0x168, 0x164)
/* Swing_DLL.xex 0x883460E8 */
CLEAR_BUFFER(ts4_clear_owned_buffer_adj1c_883460E8, 0x1c, 0x158, 0x164, 0x160)
/* Swing_DLL.xex 0x883488A0 */
CLEAR_BUFFER(ts4_clear_owned_buffer_adj1c_883488A0, 0x1c, 0x15c, 0x168, 0x164)
