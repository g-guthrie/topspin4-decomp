/* Swing_DLL.xex 0x88374940-0x88374A00, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef void (*Fn)(void);
typedef struct Desc { Fn f0; u32 f4; u32 f8; Fn fc; Fn f10; Fn f14; Fn f18; Fn f1c; Fn f20; char pad24[0x1c]; u32 f40; u32 f44; char padend[0x64]; } Desc;
extern Desc lbl_88B36D00;
extern char lbl_8802BA44[];
void fn_883746B0(void);
void ts4_forward_fields_adj1c_88374720(void);
void ts4_adjust_this_minus_28_forward_9_args_88374908(void);
void ts4_call_seq_lbl_8802BA10_88374A10(void);
void ts4_get_u32_off0_88374A48(void);
void ts4_set_u32_off0_88374A00(void);
#ifdef _MSC_VER
extern void *ts4_memset(void *, int, unsigned int);
#else
void *ts4_memset(void *, int, unsigned int);
#endif

Desc *ts4_init_static_desc_88374940(void)
{
    Desc *p = &lbl_88B36D00;
    ts4_memset(p, 0, 0xac);
    lbl_88B36D00.f0 = (Fn)(unsigned long)lbl_8802BA44;
    p->f4 = 0x10100;
    p->f8 = 0x0;
    p->fc = ts4_set_u32_off0_88374A00;
    p->f10 = ts4_call_seq_lbl_8802BA10_88374A10;
    p->f14 = ts4_get_u32_off0_88374A48;
    p->f18 = ts4_adjust_this_minus_28_forward_9_args_88374908;
    p->f1c = fn_883746B0;
    p->f20 = ts4_forward_fields_adj1c_88374720;
    p->f40 = 0x4;
    p->f44 = 0x170;
    return p;
}
