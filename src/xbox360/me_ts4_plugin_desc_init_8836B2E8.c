/* Swing_DLL.xex 0x8836B2E8: fills a static 0x7C-byte plugin descriptor (name label, version 0x10100, kind, flags, callback thunks)
 * and returns it; the stores follow the target order with two adjacent pairs swapped, as in 88359310. agAE: /Oc. */
typedef struct PluginDesc { unsigned int w[31]; } PluginDesc;
extern PluginDesc lbl_88B36840;
void *ts4_memset(void *p, int v, unsigned int n);
extern const char lbl_8802B7EC[];
void ts4_adjust_minus_28_thunk_8836B2D0(void);
void ts4_adjust_minus_28_thunk_88369E48(void);
void ts4_adjust_minus_28_thunk_8836A2B0(void);
void ts4_query_prop_883A3758(void);
void ts4_query_prop_883A37C8(void);
void ts4_adjust_minus_28_thunk_88369E60(void);
void ts4_get_word_31c_883A3828(void);
void ts4_set_item_level_883A3858(void);
void ts4_get_child_float_adj1c_883A38C0(void);
void ts4_thunk_adj1c_set_float_883A3910(void);
void ts4_get_float_off868_adj1c_883A3930(void);
PluginDesc *fn_8836B2E8(void)
{
    PluginDesc *d = &lbl_88B36840;
    ts4_memset(d, 0, sizeof(PluginDesc));
    d->w[0] = (unsigned int)lbl_8802B7EC;
    d->w[1] = 0x10100;
    d->w[3] = 0x702;
    d->w[2] = 0x1;
    d->w[4] = (unsigned int)ts4_adjust_minus_28_thunk_8836B2D0;
    d->w[5] = (unsigned int)ts4_adjust_minus_28_thunk_88369E48;
    d->w[6] = (unsigned int)ts4_adjust_minus_28_thunk_8836A2B0;
    d->w[7] = (unsigned int)ts4_query_prop_883A3758;
    d->w[8] = (unsigned int)ts4_adjust_minus_28_thunk_88369E60;
    d->w[9] = (unsigned int)ts4_query_prop_883A37C8;
    d->w[23] = (unsigned int)ts4_get_word_31c_883A3828;
    d->w[24] = (unsigned int)ts4_set_item_level_883A3858;
    d->w[25] = (unsigned int)ts4_get_child_float_adj1c_883A38C0;
    d->w[29] = (unsigned int)ts4_thunk_adj1c_set_float_883A3910;
    d->w[30] = (unsigned int)ts4_get_float_off868_adj1c_883A3930;
    d->w[16] = 0xc;
    d->w[17] = 0xef0;
    return d;
}
