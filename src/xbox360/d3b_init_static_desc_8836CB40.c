/* Swing_DLL.xex 0x8836CB40-0x8836CBE8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; char pad8[0x4]; u32 fc; Fn f10; Fn f14; Fn f18; char pad1c[0x4]; Fn f20; char pad24[0x1c]; u32 f40; u32 f44; char padend[0x34]; } Desc;
extern Desc lbl_88B36950;
extern char lbl_8802B888[];
void fn_8836C238(void);
void ts4_adjust_minus_28_thunk_8836C2B0(void);
void ts4_adjust_minus_28_thunk_8836CB10(void);
void ts4_adjust_minus_28_thunk_8836CB28(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_8836CB40(void)
{
    Desc *p = &lbl_88B36950;
    ts4_memset(p, 0, 0x7c);
    lbl_88B36950.f0 = (Fn)(unsigned long)lbl_8802B888;
    p->f4 = 0x10100;
    p->fc = 0x2;
    p->f10 = ts4_adjust_minus_28_thunk_8836CB10;
    p->f14 = fn_8836C238;
    p->f18 = ts4_adjust_minus_28_thunk_8836C2B0;
    p->f20 = ts4_adjust_minus_28_thunk_8836CB28;
    p->f40 = 0x2;
    p->f44 = 0x114;
    return p;
}
