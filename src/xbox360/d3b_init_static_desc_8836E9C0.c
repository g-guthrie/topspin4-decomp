/* Swing_DLL.xex 0x8836E9C0-0x8836EA80, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; char pad8[0x4]; u32 fc; Fn f10; Fn f14; Fn f18; char pad1c[0x4]; Fn f20; char pad24[0x4]; Fn f28; char pad2c[0x14]; u32 f40; u32 f44; char pad48[0x10]; Fn f58; char padend[0x20]; } Desc;
extern Desc lbl_88B36A60;
extern char lbl_8802B914[];
void ts4_adjust_minus_28_thunk_8836E598(void);
void ts4_adjust_minus_28_thunk_8836E5B0(void);
void ts4_adjust_minus_28_thunk_8836E5C8(void);
void ts4_adjust_minus_28_thunk_8836E5E0(void);
void ts4_adjust_minus_28_thunk_8836E5F8(void);
void ts4_adjust_minus_28_thunk_8836E9A8(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_8836E9C0(void)
{
    Desc *p = &lbl_88B36A60;
    ts4_memset(p, 0, 0x7c);
    lbl_88B36A60.f0 = (Fn)(unsigned long)lbl_8802B914;
    p->f4 = 0x10100;
    p->fc = 0xa;
    p->f10 = ts4_adjust_minus_28_thunk_8836E598;
    p->f14 = ts4_adjust_minus_28_thunk_8836E5B0;
    p->f18 = ts4_adjust_minus_28_thunk_8836E5F8;
    p->f20 = ts4_adjust_minus_28_thunk_8836E9A8;
    p->f28 = ts4_adjust_minus_28_thunk_8836E5C8;
    p->f58 = ts4_adjust_minus_28_thunk_8836E5E0;
    p->f40 = 0x14;
    p->f44 = 0x170;
    return p;
}
