/* Swing_DLL.xex 0x88374DB8-0x88374E84, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; u32 f8; Fn fc; Fn f10; Fn f14; Fn f18; Fn f1c; char pad20[0x8]; Fn f28; Fn f2c; char pad30[0x10]; u32 f40; u32 f44; char padend[0x64]; } Desc;
extern Desc lbl_88B36DB8;
extern char lbl_8802BA88[];
void fn_88374A60(void);
void fn_88374AD0(void);
void fn_88374B40(void);
void ts4_adjust_this_minus_28_forward_9_args_88374D80(void);
void ts4_call_seq_lbl_8802BA10_88374A10(void);
void ts4_get_u32_off0_88374A48(void);
void ts4_set_u32_off0_88374A00(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_88374DB8(void)
{
    Desc *p = &lbl_88B36DB8;
    ts4_memset(p, 0, 0xac);
    lbl_88B36DB8.f0 = (Fn)(unsigned long)lbl_8802BA88;
    p->f4 = 0x10100;
    p->f8 = 0x1;
    p->fc = ts4_set_u32_off0_88374A00;
    p->f10 = ts4_call_seq_lbl_8802BA10_88374A10;
    p->f14 = ts4_get_u32_off0_88374A48;
    p->f18 = ts4_adjust_this_minus_28_forward_9_args_88374D80;
    p->f1c = fn_88374A60;
    p->f28 = fn_88374AD0;
    p->f2c = fn_88374B40;
    p->f40 = 0x2;
    p->f44 = 0x2a8;
    return p;
}
