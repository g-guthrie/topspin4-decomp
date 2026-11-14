/* SM4: object initialisers that store a vtable pointer and zero or set fields in a fixed order.
 * The object is accessed through a volatile pointer so the stores keep their source order (MSVC 16.00 /O2). */
#define ST32(OFF, V) (*(volatile int *)(p + (OFF)) = (V))
#define ST16(OFF, V) (*(volatile short *)(p + (OFF)) = (short)(V))
#define ST8(OFF, V) (*(volatile char *)(p + (OFF)) = (char)(V))

/* Swing_DLL.xex 0x886E7EC8 */
extern char lbl_880F34BC[];
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *);
void ts4_init_fields_886E7EC8(void *self)
{
    volatile char *p = (volatile char *)self;
    ST32(0x84, 0);
    ST32(0x0, (int)(unsigned long)lbl_880F34BC);
    ST32(0x80, 0);
    ST32(0x7c, 0);
    ST32(0x78, 0);
    ts4_if_call_seq_lbl_880F7EE4_88617D28((void *)self);
}

/* Swing_DLL.xex 0x886CEFD8 */
extern char lbl_880F37D8[];
void ts4_init_fields_886CEFD8(void *self)
{
    volatile char *p = (volatile char *)self;
    ST32(0x0, (int)(unsigned long)lbl_880F37D8);
    ST32(0x8, 0);
    ST32(0xc, 0);
    ST32(0x10, 0);
    ST32(0x14, 0);
    ST32(0x18, 0);
    ST32(0x1c, 0);
    ST32(0x20, 0);
    ST32(0x24, 0);
    ST32(0x28, 0);
    ST32(0x4, 0);
}

/* Swing_DLL.xex 0x886CA2D8 */
extern char lbl_880F37D0[];
void ts4_init_fields_886CA2D8(void *self)
{
    volatile char *p = (volatile char *)self;
    ST32(0x0, (int)(unsigned long)lbl_880F37D0);
    ST32(0x8, 0);
    ST32(0xc, 0);
    ST32(0x10, 0);
    ST32(0x14, 0);
    ST32(0x18, 0);
    ST32(0x1c, 0);
    ST32(0x20, 0);
    ST32(0x24, 0);
    ST32(0x28, 0);
    ST32(0x2c, 0);
    ST32(0x30, 0);
    ST32(0x34, 0);
    ST32(0x4, 0);
}

/* Swing_DLL.xex 0x886CF8E0 */
extern char lbl_880F37D4[];
void ts4_init_fields_886CF8E0(void *self)
{
    volatile char *p = (volatile char *)self;
    ST32(0x0, (int)(unsigned long)lbl_880F37D4);
    ST32(0x8, 0);
    ST32(0xc, 0);
    ST32(0x10, 0);
    ST32(0x14, 0);
    ST32(0x18, 0);
    ST32(0x1c, 0);
    ST32(0x20, 0);
    ST32(0x24, 0);
    ST32(0x28, 0);
    ST32(0x2c, 0);
    ST32(0x30, 0);
    ST32(0x34, 0);
    ST32(0x3c, 0);
    ST32(0x40, 0);
    ST32(0x44, 0);
    ST32(0x4, 0);
    ST16(0x38, 0);
}

/* Swing_DLL.xex 0x886DAC48 */
extern char lbl_880F379C[];
void ts4_init_fields_886DAC48(void *self)
{
    volatile char *p = (volatile char *)self;
    ST32(0x0, (int)(unsigned long)lbl_880F379C);
    ST32(0x3c, 0);
    ST32(0x40, 0);
    ST32(0x44, 0);
    ST32(0x48, 0);
    ST32(0x4c, 0);
    ST32(0x50, 0);
    ST32(0x54, 0);
    ST32(0x58, 0);
    ST32(0x5c, 0);
    ST32(0x60, 0);
    ST32(0x64, 0);
    ST32(0x68, 0);
    ST32(0x28, 0);
    ST32(0x2c, 0);
    ST32(0x30, 0);
    ST32(0x34, 0);
    ST8(0x6d, 0);
    ST8(0x6c, 0);
}

/* Swing_DLL.xex 0x886D37C0 */
void ts4_init_fields_886D37C0(void *self)
{
    volatile char *p = (volatile char *)self;
    ST32(0x0, 0);
    ST32(0x4, 0);
    ST32(0x8, 0);
    ST32(0x1c, 0);
    ST32(0x20, 0);
    ST32(0x24, 0);
    ST32(0x28, 0);
    ST32(0x2c, 0);
    ST32(0x30, 0);
    ST32(0x34, 0);
    ST32(0x38, 0);
    ST32(0x3c, 0);
    ST32(0x40, 0);
    ST32(0x44, 0);
    ST32(0x48, 0);
    ST32(0x4c, 0);
    ST32(0x50, 0);
    ST32(0x54, 0);
    ST32(0x58, 0);
    ST32(0x5c, 0);
    ST32(0x60, 0);
    ST32(0x64, 0);
    ST32(0x68, 0);
    ST32(0x6c, 0);
    ST32(0x70, 0);
    ST32(0x74, 0);
    ST32(0x78, 0);
    ST32(0x7c, 0);
    ST32(0x80, 0);
    ST32(0x84, 0);
    ST32(0x88, 0);
    ST32(0x8c, 0);
    ST32(0x90, 0);
    ST32(0x14, 0);
    ST32(0x10, 0);
    ST32(0xc, 0);
    ST32(0x18, 0);
}

