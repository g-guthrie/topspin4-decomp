/* Swing_DLL.xex 0x88382FB0: fills a static 0xAC-byte plugin descriptor (name label, version 0x10100, kind, flags, callback thunks)
 * and returns it; same template as 88359310. agAE: /Oc. */
typedef struct PluginDesc { unsigned int w[43]; } PluginDesc;
extern PluginDesc lbl_88B36E98;
void *ts4_memset(void *p, int v, unsigned int n);
extern const char lbl_8802BEE4[];
void ts4_set_u32_off0_88374A00(void);
void ts4_if_call_seq_lbl_8802BE78_883817E8(void);
void ts4_if_get_u32_off0_88381850(void);
void fn_883826D8(void);
void ts4_forward_adjusted_or_null_m1c_883818A0(void);
void fn_883818B8(void);
void ts4_forward_adjusted_or_null_m1c_88381928(void);
void ts4_get_u32_off2A0_adj1c_88381958(void);
void ts4_forward_adjusted_or_null_m1c_88381940(void);
void ts4_forward_adjusted_or_null_m1c_88381988(void);
void ts4_forward_adjusted_or_null_m1c_883819A0(void);
void ts4_get_mode_883819B8(void);
void ts4_forward_adjusted_or_null_m1c_88381A28(void);
void ts4_thunk_adj1c_bool_arg_88382F90(void);
void ts4_forward_adjusted_or_null_m1c_88381A40(void);
void ts4_forward_adjusted_or_null_m1c_88382738(void);
void ts4_forward_adjusted_or_null_m1c_88381A58(void);
PluginDesc *fn_88382FB0(void)
{
    PluginDesc *d = &lbl_88B36E98;
    ts4_memset(d, 0, sizeof(PluginDesc));
    d->w[0] = (unsigned int)lbl_8802BEE4;
    d->w[1] = 0x10100;
    d->w[16] = 0x11;
    d->w[17] = 0x6d4;
    d->w[2] = 0x1;
    d->w[3] = (unsigned int)ts4_set_u32_off0_88374A00;
    d->w[4] = (unsigned int)ts4_if_call_seq_lbl_8802BE78_883817E8;
    d->w[23] = (unsigned int)ts4_if_get_u32_off0_88381850;
    d->w[25] = (unsigned int)fn_883826D8;
    d->w[7] = (unsigned int)ts4_forward_adjusted_or_null_m1c_883818A0;
    d->w[26] = (unsigned int)fn_883818B8;
    d->w[27] = (unsigned int)ts4_forward_adjusted_or_null_m1c_88381928;
    d->w[9] = (unsigned int)ts4_get_u32_off2A0_adj1c_88381958;
    d->w[8] = (unsigned int)ts4_forward_adjusted_or_null_m1c_88381940;
    d->w[10] = (unsigned int)ts4_forward_adjusted_or_null_m1c_88381988;
    d->w[11] = (unsigned int)ts4_forward_adjusted_or_null_m1c_883819A0;
    d->w[32] = (unsigned int)ts4_get_mode_883819B8;
    d->w[33] = (unsigned int)ts4_forward_adjusted_or_null_m1c_88381A28;
    d->w[36] = (unsigned int)ts4_thunk_adj1c_bool_arg_88382F90;
    d->w[37] = (unsigned int)ts4_forward_adjusted_or_null_m1c_88381A40;
    d->w[38] = (unsigned int)ts4_forward_adjusted_or_null_m1c_88382738;
    d->w[39] = (unsigned int)ts4_forward_adjusted_or_null_m1c_88381A58;
    return d;
}
