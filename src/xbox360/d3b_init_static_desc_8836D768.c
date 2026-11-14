/* Swing_DLL.xex 0x8836D768-0x8836D81C, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; char pad8[0x4]; u32 fc; Fn f10; Fn f14; Fn f18; char pad1c[0x4]; Fn f20; char pad24[0x1c]; u32 f40; u32 f44; char pad48[0x28]; Fn f70; char padend[0x8]; } Desc;
extern Desc lbl_88B369D8;
extern char lbl_8802B8C0[];
void fn_8836D0C8(void);
void fn_8836D120(void);
void ts4_adjust_minus_28_thunk_8836D108(void);
void ts4_adjust_minus_28_thunk_8836D210(void);
void ts4_adjust_minus_28_thunk_8836D750(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_8836D768(void)
{
    Desc *p = &lbl_88B369D8;
    ts4_memset(p, 0, 0x7c);
    lbl_88B369D8.f0 = (Fn)(unsigned long)lbl_8802B8C0;
    p->f4 = 0x10100;
    p->fc = 0x2;
    p->f10 = ts4_adjust_minus_28_thunk_8836D750;
    p->f14 = fn_8836D0C8;
    p->f18 = ts4_adjust_minus_28_thunk_8836D108;
    p->f20 = fn_8836D120;
    p->f70 = ts4_adjust_minus_28_thunk_8836D210;
    p->f40 = 0xe;
    p->f44 = 0x508;
    return p;
}
