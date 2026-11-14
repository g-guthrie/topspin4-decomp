/* Swing_DLL.xex 0x88354F58-0x88355000, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; char pad8[0x4]; u32 fc; Fn f10; Fn f14; Fn f18; char pad1c[0x4]; Fn f20; char pad24[0x1c]; u32 f40; u32 f44; char padend[0x34]; } Desc;
extern Desc lbl_88B35D50;
extern char lbl_8802B25C[];
void ts4_adjust_minus_28_thunk_88353210(void);
void ts4_adjust_minus_28_thunk_88353228(void);
void ts4_adjust_minus_28_thunk_88354F28(void);
void ts4_adjust_minus_28_thunk_88354F40(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_88354F58(void)
{
    Desc *p = &lbl_88B35D50;
    ts4_memset(p, 0, 0x7c);
    lbl_88B35D50.f0 = (Fn)(unsigned long)lbl_8802B25C;
    p->f4 = 0x10100;
    p->fc = 0x2;
    p->f10 = ts4_adjust_minus_28_thunk_88354F28;
    p->f14 = ts4_adjust_minus_28_thunk_88353210;
    p->f18 = ts4_adjust_minus_28_thunk_88353228;
    p->f20 = ts4_adjust_minus_28_thunk_88354F40;
    p->f40 = 0x6;
    p->f44 = 0x130;
    return p;
}
