/* Swing_DLL.xex 0x8834E2F0-0x8834E3A4, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; char pad8[0x4]; u32 fc; Fn f10; Fn f14; Fn f18; char pad1c[0x4]; Fn f20; char pad24[0x1c]; u32 f40; u32 f44; char pad48[0x10]; Fn f58; char padend[0x20]; } Desc;
extern Desc lbl_88B35718;
extern char lbl_8802AF08[];
void fn_8834DED8(void);
void fn_8834DF60(void);
void ts4_adjust_minus_28_thunk_8834E2D8(void);
void ts4_fn_883E63B8(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_8834E2F0(void)
{
    Desc *p = &lbl_88B35718;
    ts4_memset(p, 0, 0x7c);
    lbl_88B35718.f0 = (Fn)(unsigned long)lbl_8802AF08;
    p->f4 = 0x10100;
    p->fc = 0xa;
    p->f10 = ts4_adjust_minus_28_thunk_8834E2D8;
    p->f14 = ts4_fn_883E63B8;
    p->f18 = fn_8834DED8;
    p->f20 = fn_8834DF60;
    p->f58 = ts4_fn_883E63B8;
    p->f40 = 0x10;
    p->f44 = 0x23c;
    return p;
}
