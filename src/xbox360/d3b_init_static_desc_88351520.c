/* Swing_DLL.xex 0x88351520-0x883515E0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; char pad8[0x4]; u32 fc; Fn f10; Fn f14; Fn f18; char pad1c[0x4]; Fn f20; char pad24[0x4]; Fn f28; char pad2c[0x14]; u32 f40; u32 f44; char pad48[0xc]; Fn f54; char padend[0x24]; } Desc;
extern Desc lbl_88B35C40;
extern char lbl_8802B0E4[];
void ts4_adjust_minus_28_thunk_88350BC0(void);
void ts4_adjust_minus_28_thunk_88350BD8(void);
void ts4_adjust_minus_28_thunk_88350BF0(void);
void ts4_adjust_minus_28_thunk_88350C08(void);
void ts4_adjust_minus_28_thunk_88350C20(void);
void ts4_adjust_minus_28_thunk_88351508(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_88351520(void)
{
    Desc *p = &lbl_88B35C40;
    ts4_memset(p, 0, 0x7c);
    lbl_88B35C40.f0 = (Fn)(unsigned long)lbl_8802B0E4;
    p->f4 = 0x10100;
    p->fc = 0xa;
    p->f10 = ts4_adjust_minus_28_thunk_88351508;
    p->f14 = ts4_adjust_minus_28_thunk_88350BC0;
    p->f18 = ts4_adjust_minus_28_thunk_88350BF0;
    p->f20 = ts4_adjust_minus_28_thunk_88350C08;
    p->f28 = ts4_adjust_minus_28_thunk_88350BD8;
    p->f54 = ts4_adjust_minus_28_thunk_88350C20;
    p->f40 = 0xd;
    p->f44 = 0x12c;
    return p;
}
