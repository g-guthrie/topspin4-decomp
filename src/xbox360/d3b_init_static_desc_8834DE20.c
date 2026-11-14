/* Swing_DLL.xex 0x8834DE20-0x8834DED8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; char pad8[0x4]; u32 fc; Fn f10; Fn f14; Fn f18; char pad1c[0x4]; Fn f20; char pad24[0x20]; u32 f44; char pad48[0x8]; Fn f50; char pad54[0x1c]; Fn f70; char padend[0x8]; } Desc;
extern Desc lbl_88B35690;
extern char lbl_8802AEF8[];
void fn_8834DDE0(void);
void ts4_adjust_minus_28_thunk_8834DAC8(void);
void ts4_adjust_minus_28_thunk_8834DAE0(void);
void ts4_adjust_minus_28_thunk_8834DAF8(void);
void ts4_adjust_minus_28_thunk_8834DDC8(void);
void ts4_fn_8834DAC0(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_8834DE20(void)
{
    Desc *p = &lbl_88B35690;
    ts4_memset(p, 0, 0x7c);
    lbl_88B35690.f0 = (Fn)(unsigned long)lbl_8802AEF8;
    p->f4 = 0x10100;
    p->fc = 0x2;
    p->f10 = ts4_fn_8834DAC0;
    p->f14 = ts4_adjust_minus_28_thunk_8834DAC8;
    p->f18 = ts4_adjust_minus_28_thunk_8834DDC8;
    p->f20 = ts4_adjust_minus_28_thunk_8834DAE0;
    p->f50 = ts4_adjust_minus_28_thunk_8834DAF8;
    p->f70 = fn_8834DDE0;
    p->f44 = 0x1770;
    return p;
}
