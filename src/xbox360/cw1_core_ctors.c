/* CW1: core XData constructors (Swing_DLL.xex 0x88151B90 .. 0x88151F20). */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *ts4_memset(void *dst, int c, u32 n);
extern int ts4_format_text(char *dst, u32 size, const char *fmt, ...);
extern char lbl_880D1B40[];

/* Text-labelled record with 0x21-byte name and 0x200-byte description. */
struct Cw1Label {
    u8 pad0[0x224];
    u32 f224;
    u32 f228;
    u32 f22c;
    u32 f230;
};

struct Cw1Label2 {
    u8 pad0[0x224];
    u32 f224;
    u32 f228;
    u8 pad1[0x2ac - 0x22c];
    u32 f2ac, f2b0, f2b4, f2b8;
};

/* Swing_DLL.xex 0x88151E90 */
struct Cw1Label *ts4_label_init_flags_88151E90(struct Cw1Label *self, const char *name, u32 value)
{
    self->f224 = value;
    self->f228 = 1;
    self->f22c = 0;
    self->f230 = 1;
    ts4_memset((char *)self, 0, 0x21);
    if (name != 0)
        ts4_format_text((char *)self, 0x21, lbl_880D1B40, name);
    ts4_memset((char *)self + 0x21, 0, 0x200);
    return self;
}

/* Swing_DLL.xex 0x88151F20 */
struct Cw1Label2 *ts4_label_init_88151F20(struct Cw1Label2 *self, const char *name, u32 value)
{
    self->f228 = value;
    self->f224 = 0;
    self->f2ac = 0;
    self->f2b0 = 0;
    self->f2b4 = 0;
    self->f2b8 = 0;
    ts4_memset((char *)self, 0, 0x21);
    if (name != 0)
        ts4_format_text((char *)self, 0x21, lbl_880D1B40, name);
    ts4_memset((char *)self + 0x21, 0, 0x200);
    ts4_memset((char *)self + 0x22c, 0, 0x80);
    return self;
}
